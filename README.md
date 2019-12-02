# Computacao_ParalelaTP02

Tempo Sequencial

- Mining block 1...
- Block mined: 000000dee3aae84d1390b8f0fb67862052b7987d01bc00fbcef0124fd33098f5
  Mining block 2...
  Block mined: 0000007a84619f72241f21343473cbd695a9492e8292c1b9ccd79d1d7f4d6276
  Mining block 3...
  Block mined: 00000089e4755f64093024527479c8622ff8983608fa4e5ff7dabdc3df85afdb

  real 12m11.962s
  user 12m11.765s
  sys 0m0.012s

==============================================================================

Tempo Paralelo com OpenMP (CPU):

Block mined: 000000b5c8a92cfba4e355add4fdddf7d769981794537b4709e7d8c51c9c4373
Mining block 2...
Block mined: 0000007ba1ce4f6525e0bc2e0331fd44e83f112a1a34b077ea96659c31fe0993
Mining block 3...
Block mined: 000000afda97cde89a582bc69ce4e513632fb2c24f6627fbdfff481b290502a4

real 3m15.444s
user 3m15.367s
sys 0m0.004s


=================================================================================

Tempo Paralelo com OpenMP (GPU):

Mining block 1...
Block mined: 000000402d3c48433bb7c6ae27020d9fcf08b8bbd8f4326c8a2144757d4b4f8a
Mining block 2...
Block mined: 000000bbfd700cbdfeac3af2243a8cdfb48d924e63fb0374dfa083c41fbd85e7
Mining block 3...
Block mined: 000000b1db31b384e5100ac8b0bdfdad84bc996ee3d441fb174f5a501981da1b

real 5m9.740s
user 5m9.502s
sys 0m0.116s
