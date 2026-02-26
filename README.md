# Projeto — Estruturas de Dados e Ordenação

### Ranking de Jogos — Análise de Algoritmos em C

---

## Equipe

| Nome                          | GitHub                                                   |
| ----------------------------- | -------------------------------------------------------- |
| Leôncio Ferreira Flores Neto  | [@LeoncioFerreira](https://github.com/LeoncioFerreira)   |
| Alan Mendes Vieira            | [@alan-mendes-ufca](https://github.com/alan-mendes-ufca) |
| Paulo Gabriel Leite Landim    | [@LandimPG](https://github.com/LandimPG)                 |
| Salomão Rodrigues Silva       | [@salomaosilvaa](https://github.com/salomaosilvaa)       |
| Cícero Jesus da Silva Gomes   | [@cicero-jesus](https://github.com/cicero-jesus)         |
| Carlos Eduardo Bezerra Santos | [@carlossan25c](https://github.com/carlossan25c)         |

---

## Contexto do Projeto

Este projeto implementa e compara algoritmos clássicos de ordenação aplicados a um cenário de ranking de jogadores.

Cada jogador possui atributos como:

- `nickname`
- `pontuacao`
- `nivel`
- `tempo_jogado`

O objetivo é analisar como a escolha de:

- estrutura de dados (lista estática vs dinâmica),
- algoritmo de ordenação,
- tipo de entrada,
- volume de dados

impacta diretamente o desempenho.

---

## Estruturas de Dados

- **Lista Encadeada Estática** (`src/lista_encadeada_estatica.*`)
  - Implementada com vetor pré-alocado e encadeamento por índices.
- **Lista Duplamente Encadeada Dinâmica** (`src/lista_encadeada_dinamica.*`)
  - Implementada com alocação dinâmica de nós.

---

## Algoritmos Implementados

Todos os algoritmos usam comparador comum (`sorting_utils`) para manter o critério de ordenação padronizado.

- **Bubble Sort**
  - Estática: `src/sortingAlgorithms/bubble_sort_estatico/`
  - Dinâmica: `src/sortingAlgorithms/bubble_doubly/`
- **Insertion Sort**
  - Estática: `src/sortingAlgorithms/insertion_sort_estatico/`
  - Dinâmica: `src/sortingAlgorithms/insertion_sort_dinamico/`
- **Selection Sort**
  - Estática: `src/sortingAlgorithms/selection_estatico/`
  - Dinâmica: `src/sortingAlgorithms/selection_sort_duplamente_encadeada/`
- **Merge Sort** (recursivo)
  - Estática: `src/sortingAlgorithms/merge_estatica/`
  - Dinâmica: `src/sortingAlgorithms/merge_doubly/`
- **Quick Sort** (recursivo)
  - Estática: `src/sortingAlgorithms/quick_static/`
  - Dinâmica: `src/sortingAlgorithms/quick_doubly/`
  - Estratégia de pivô: **median-of-three** (low/mid/high).

---

## Benchmark e Métricas

Arquivo principal de benchmark:

- `src/graficos/mede_tempo.c`

Características:

- Mede apenas o trecho de ordenação.
- Usa `clock_gettime(CLOCK_MONOTONIC)` em nanossegundos.
- Testa para `N = 100`, `1000`, `10000`.
- Tipos de entrada:
  - `aleatoria`
  - `ordenada`
  - `inversamente_ordenada`
- Executa múltiplas repetições por cenário (padrão: `100`).
  - Pode alterar via: `BENCH_REPETICOES`.

Saídas do benchmark:

- `resultados_execucoes.csv` (todas as execuções)
- `resultados_medias.csv` (médias agregadas)

---

## Gráficos (Pandas + Matplotlib)

Script:

- `src/graficos/gerador_de_graficos/grafico_de_barras.py`

Saídas:

- `src/graficos/out/barras_estatica.png`
- `src/graficos/out/barras_dinamica.png`

Dependências Python são gerenciadas com **uv** (`pyproject.toml`).

---

## Estrutura do Repositório

```text
├── src/
│   ├── lista_encadeada_estatica.*
│   ├── lista_encadeada_dinamica.*
│   ├── sortingAlgorithms/                 # Implementações de ordenação
│   ├── utilitarios/                       # Geração de dados
│   └── graficos/                          # Benchmark e geração de gráficos
├── resultados_execucoes.csv
├── resultados_medias.csv
├── pyproject.toml                         # Dependências Python (uv)
└── Makefile                               # Comandos de build/test/bench/plot
```

---

## Como Executar

### 1. Rodar testes dos algoritmos

```bash
make test
```

### 2. Rodar benchmark (gera CSV)

```bash
make bench
```

Benchmark rápido (exemplo com 10 repetições):

```bash
BENCH_REPETICOES=10 make bench
```

### 3. Instalar dependências Python para gráficos

```bash
make plot-deps
```

### 4. Gerar gráficos de barras

```bash
make plot
```

---

## Observações Técnicas

- O projeto está em C (`gcc`, padrão C11).
- A análise de desempenho deve sempre ser interpretada por:
  - algoritmo,
  - estrutura,
  - tipo de entrada,
  - tamanho `N`.
- Quick e Merge são recursivos; Bubble, Insertion e Selection são iterativos.
