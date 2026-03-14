"""
Gera gráficos de desempenho a partir de ``resultados_medias.csv``.

Este script:
- lê tempos médios em nanossegundos e converte para milissegundos;
- agrega os resultados por algoritmo e tamanho de entrada (n);
- plota gráficos de barras verticais com eixo Y em escala logarítmica;
- gera saídas separadas por estrutura (estática e dinâmica) e um gráfico unificado.

Entradas esperadas:
- arquivo CSV com colunas: ``estrutura``, ``algoritmo``, ``n`` e ``media_ns``.

Saídas geradas em ``src/graficos/out``:
- ``vertical_estatica.png``
- ``vertical_dinamica.png``
- ``vertical_unificado_geral.png``

Como executar:
- primeiro rode ``make bench`` para gerar ``resultados_medias.csv``;
- depois rode ``make plot`` para gerar os graficos.
"""

from __future__ import annotations
from pathlib import Path
import numpy as np

try:
    import matplotlib.pyplot as plt
    import pandas as pd
except ModuleNotFoundError as exc:
    pacote = str(exc).split("'")[1] if "'" in str(exc) else "dependencia"
    raise SystemExit(
        f"Dependencia ausente: {pacote}. "
        "Instale com: uv add pandas matplotlib numpy"
    ) from exc


def preparar_dados(media_csv: Path) -> pd.DataFrame:
    df = pd.read_csv(media_csv)
    df["media_ms"] = df["media_ns"] / 1_000_000.0
    return df


def autolabel_vertical(ax, bars):
    """Adiciona os rótulos de dados no topo das barras verticais na HORIZONTAL"""
    for bar in bars:
        height = bar.get_height()
        if height > 0:
            ax.text(bar.get_x() + bar.get_width()/2., height * 1.05, 
                    f'{height:.2f}', 
                    ha='center', va='bottom', fontsize=8)


def gerar_graficos_separados_verticais(df: pd.DataFrame, out_dir: Path) -> None:
    estruturas = ["estatica", "dinamica"]
    cores = {100: '#2ca02c', 1000: '#ff7f0e', 10000: '#d62728'}

    for estrutura in estruturas:
        df_filtrado = df[df["estrutura"] == estrutura].copy()
        df_grouped = df_filtrado.groupby(["algoritmo", "n"], as_index=False)["media_ms"].mean()
        df_pivot = df_grouped.pivot(index="algoritmo", columns="n", values="media_ms").fillna(0)
        col_ordem = 10000 if 10000 in df_pivot.columns else max(df_pivot.columns)
        df_pivot = df_pivot.sort_values(by=col_ordem, ascending=True)
        df_pivot.index = df_pivot.index.str.capitalize()

        plt.style.use('default')
        fig, ax = plt.subplots(figsize=(12, 6), dpi=140)

        nomes_algoritmos = df_pivot.index
        x = np.arange(len(nomes_algoritmos))
        width = 0.25  

        bars_100 = ax.bar(x - width, df_pivot.get(100, 0), width, color=cores[100], label='100 Jogadores')
        bars_1000 = ax.bar(x, df_pivot.get(1000, 0), width, color=cores[1000], label='1.000 Jogadores')
        bars_10000 = ax.bar(x + width, df_pivot.get(10000, 0), width, color=cores[10000], label='10.000 Jogadores')

        ax.set_ylabel('Tempo Médio (ms) - Log', fontweight='bold', fontsize=12)
        ax.set_xticks(x)
        ax.set_xticklabels(nomes_algoritmos, fontweight='bold', fontsize=12)
        
        ax.set_yscale('log')
        ax.grid(axis='y', alpha=0.3, linestyle='--')
        ax.spines['top'].set_visible(False)
        ax.spines['right'].set_visible(False)

        autolabel_vertical(ax, bars_100)
        autolabel_vertical(ax, bars_1000)
        autolabel_vertical(ax, bars_10000)

        # Legenda encaixada logo acima do gráfico
        ax.legend(loc='lower center', bbox_to_anchor=(0.5, 1.05), ncol=3, fontsize=11, frameon=False)

        fig.tight_layout()
        
        out_file = out_dir / f"vertical_{estrutura}.png"
        fig.savefig(out_file)
        plt.close(fig)
        print(f"OK: {out_file} gerado com sucesso!")


def gerar_grafico_unificado_vertical(df: pd.DataFrame, out_dir: Path) -> None:
    df["alg_est"] = df["algoritmo"].str.capitalize() + "\n(" + df["estrutura"].str.capitalize() + ")"

    df_grouped = df.groupby(["alg_est", "n"], as_index=False)["media_ms"].mean()
    df_pivot = df_grouped.pivot(index="alg_est", columns="n", values="media_ms").fillna(0)
    col_ordem = 10000 if 10000 in df_pivot.columns else max(df_pivot.columns)
    df_pivot = df_pivot.sort_values(by=col_ordem, ascending=True)

    plt.style.use('default')
    fig, ax = plt.subplots(figsize=(16, 6), dpi=140)

    cores = {100: '#2ca02c', 1000: '#ff7f0e', 10000: '#d62728'}

    nomes_algoritmos = df_pivot.index
    x = np.arange(len(nomes_algoritmos))
    width = 0.25  

    bars_100 = ax.bar(x - width, df_pivot.get(100, 0), width, color=cores[100], label='100 Jogadores')
    bars_1000 = ax.bar(x, df_pivot.get(1000, 0), width, color=cores[1000], label='1.000 Jogadores')
    bars_10000 = ax.bar(x + width, df_pivot.get(10000, 0), width, color=cores[10000], label='10.000 Jogadores')

    ax.set_ylabel('Tempo Médio (ms) - Escala Logarítmica', fontweight='bold', fontsize=12)
    ax.set_xticks(x)
    ax.set_xticklabels(nomes_algoritmos, fontweight='bold', fontsize=10)
    
    ax.set_yscale('log')
    ax.grid(axis='y', alpha=0.3, linestyle='--')
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)

    autolabel_vertical(ax, bars_100)
    autolabel_vertical(ax, bars_1000)
    autolabel_vertical(ax, bars_10000)

    ax.legend(loc='lower center', bbox_to_anchor=(0.5, 1.05), ncol=3, fontsize=12, frameon=False)

    fig.tight_layout()
    
    out_file = out_dir / "vertical_unificado_geral.png"
    fig.savefig(out_file)
    plt.close(fig)
    print(f"OK: {out_file} gerado com sucesso!")


def main() -> None:
    csv_path = Path("resultados_medias.csv")
    out_dir = Path("src/graficos/out")
    out_dir.mkdir(parents=True, exist_ok=True)
    
    df_dados = preparar_dados(csv_path)
    
    gerar_graficos_separados_verticais(df_dados, out_dir)
    gerar_grafico_unificado_vertical(df_dados, out_dir)


if __name__ == "__main__":
    main()
