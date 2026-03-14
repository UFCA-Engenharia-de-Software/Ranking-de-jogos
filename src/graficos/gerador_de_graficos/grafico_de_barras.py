"""
Gera 2 graficos de barras simples a partir de resultados_medias.csv:
- um para estrutura estatica
- outro para estrutura dinamica
"""

from __future__ import annotations

from pathlib import Path

try:
    import matplotlib.pyplot as plt
    import pandas as pd

except ModuleNotFoundError as exc:
    pacote = str(exc).split("'")[1] if "'" in str(exc) else "dependencia"
    raise SystemExit(
        f"Dependencia ausente: {pacote}. "
        "Instale com: uv add pandas matplotlib"
    ) from exc


def gerar_barras(media_csv: Path, out_dir: Path) -> None:
    df = pd.read_csv(media_csv)
    df["media_ms"] = df["media_ns"] / 1_000_000.0

    out_dir.mkdir(parents=True, exist_ok=True)

    for estrutura in ["estatica", "dinamica"]:
        foco = df[df["estrutura"] == estrutura].copy()

        resumo = (
            foco.groupby("algoritmo", as_index=False)["media_ms"]
            .mean()
            .sort_values("media_ms")
        )

        fig, ax = plt.subplots(figsize=(9, 5), dpi=140)
        bars = ax.bar(resumo["algoritmo"], resumo["media_ms"], color="#4c78a8")

        ax.set_title(f"Tempo médio por algoritmo - estrutura {estrutura}")
        ax.set_xlabel("")
        ax.set_ylabel("Tempo médio (ms)")
        ax.grid(axis="y", alpha=0.3)

        # Escala log para evitar que merge/quick "sumam" perto de zero.
        ax.set_yscale("log")

        for bar, valor in zip(bars, resumo["media_ms"]):
            ax.text(
                bar.get_x() + bar.get_width() / 2.0,
                bar.get_height(),
                f"{valor:.3f}",
                ha="center",
                va="bottom",
                fontsize=8,
            )

        fig.tight_layout()
        out_file = out_dir / f"barras_{estrutura}.png"
        fig.savefig(out_file)
        plt.close(fig)
        print(f"OK: {out_file}")


def main() -> None:
    gerar_barras(
        media_csv=Path("resultados_medias.csv"),
        out_dir=Path("src/graficos/out"),
    )


if __name__ == "__main__":
    main()
