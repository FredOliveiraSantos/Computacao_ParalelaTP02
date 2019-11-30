/**
 * Frederico Oliveira Costa Santos
 * Projeto 02 - Computação Paralela
 * 
 * Tempo Paralelo:
 * Mining block 1...
Block mined: 000000b5c8a92cfba4e355add4fdddf7d769981794537b4709e7d8c51c9c4373
Mining block 2...
Block mined: 0000007ba1ce4f6525e0bc2e0331fd44e83f112a1a34b077ea96659c31fe0993
Mining block 3...
Block mined: 000000afda97cde89a582bc69ce4e513632fb2c24f6627fbdfff481b290502a4

real    3m15.444s
user    3m15.367s
sys     0m0.004s
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

    //Reescrevendo esse código para ser paralelizado mais facilmente:

#pragma omp parallel //Inicio do bloco paralelo:
    {
#pragma omp single nowait // Executar a seção em uma thead disponível e não esperar pela barreira
        while (sHash.substr(0, nDifficulty) != str)
        {
#pragma omp task firstprivate(sHash) //Tarefa paralela
            _nNonce++;
            sHash = _CalculateHash();
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
