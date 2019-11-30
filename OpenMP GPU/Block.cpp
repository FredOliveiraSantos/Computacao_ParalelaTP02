/**
 * Frederico Oliveira Costa Santos
 * Projeto 02 - Computação Paralela
 * 
 * Tempo Paralelo (GPU):

real    5m9.740s
user    5m9.502s
sys     0m0.116s
 */

#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    _nNonce = 0;
    _tTime = time(nullptr);

    sHash = _CalculateHash();
}

void Block::MineBlock(uint32_t nDifficulty)
{
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);

    // do
    // {
    //     _nNonce++;
    //     sHash = _CalculateHash();
    // }
    // while (sHash.substr(0, nDifficulty) != str);

    // Assim como na paralelização com CPU, vamos reescrever esse código:

#pragma omp parallel shared(sHash)
    {
#pragma omp single nowait
        {
            while (sHash.substr(0, nDifficulty) != str)
            {
                _nNonce++;
#pragma omp target data map(tofrom \
                            : sHash)
#pragma omp task firstprivate(sHash)
                sHash = _CalculateHash();
            }
        }
    }

    cout << "Block mined: " << sHash << endl;
}

inline string Block::_CalculateHash() const
{
    stringstream ss;
    ss << _nIndex << sPrevHash << _tTime << _sData << _nNonce;

    return sha256(ss.str());
}
