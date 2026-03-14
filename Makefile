CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Isrc
BUILD_DIR := build-tests

.PHONY: test clean
.PHONY: test clean bench plot plot-deps ensure-uv

test: \
	$(BUILD_DIR)/test_lista_estatica \
	$(BUILD_DIR)/test_bubble_dinamico \
	$(BUILD_DIR)/test_quick_static \
	$(BUILD_DIR)/test_insertion_static \
	$(BUILD_DIR)/test_selection_static \
	$(BUILD_DIR)/test_merge_static \
	$(BUILD_DIR)/test_bubble_static \
	$(BUILD_DIR)/test_selection_dinamico \
	$(BUILD_DIR)/test_insertion_dinamico \
	$(BUILD_DIR)/test_merge_dinamico \
	$(BUILD_DIR)/test_quick_dinamico \
	$(BUILD_DIR)/test_gerador
	@set -e; \
	for t in test_lista_estatica test_bubble_dinamico test_quick_static test_insertion_static test_selection_static test_merge_static test_bubble_static test_selection_dinamico test_insertion_dinamico test_merge_dinamico test_quick_dinamico test_gerador; do \
		echo "==> $$t"; \
		./$(BUILD_DIR)/$$t; \
	done

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/test_lista_estatica: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/estruturas/estatica/test_lista_encadeada_estatica.c src/estruturas/estatica/lista_encadeada_estatica.c -o $@

$(BUILD_DIR)/test_bubble_dinamico: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/algoritmos_ordenacao/bubble_sort_dinamico/test_bubble_dinamico.c src/algoritmos_ordenacao/bubble_sort_dinamico/bubble_sort_dinamico.c src/utilitarios/utilitarios_ordenacao.c src/estruturas/dinamica/lista_encadeada_dinamica.c -o $@

$(BUILD_DIR)/test_quick_static: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/algoritmos_ordenacao/quick_sort_estatico/teste_quick_sort_static.c src/algoritmos_ordenacao/quick_sort_estatico/quick_sort_lista_estatica.c src/utilitarios/utilitarios_ordenacao.c src/estruturas/estatica/lista_encadeada_estatica.c -o $@

$(BUILD_DIR)/test_insertion_static: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/algoritmos_ordenacao/insertion_sort_estatico/teste_insertion_sort_estatico.c src/algoritmos_ordenacao/insertion_sort_estatico/insertion_sort_estatico.c src/utilitarios/utilitarios_ordenacao.c src/estruturas/estatica/lista_encadeada_estatica.c -o $@

$(BUILD_DIR)/test_selection_static: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/algoritmos_ordenacao/selection_sort_estatico/test_selection_estatico.c src/algoritmos_ordenacao/selection_sort_estatico/selection_sort_estatico.c src/utilitarios/utilitarios_ordenacao.c src/estruturas/estatica/lista_encadeada_estatica.c -o $@

$(BUILD_DIR)/test_merge_static: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/algoritmos_ordenacao/merge_sort_estatico/teste_merge_sort_lista_estatica.c src/algoritmos_ordenacao/merge_sort_estatico/merge_sort_lista_estatica.c src/utilitarios/utilitarios_ordenacao.c src/estruturas/estatica/lista_encadeada_estatica.c -o $@

$(BUILD_DIR)/test_bubble_static: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/algoritmos_ordenacao/bubble_sort_estatico/teste_bubble_sort_estatica.c src/algoritmos_ordenacao/bubble_sort_estatico/bubble_sort_estatica.c src/utilitarios/utilitarios_ordenacao.c src/estruturas/estatica/lista_encadeada_estatica.c -o $@

$(BUILD_DIR)/test_selection_dinamico: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/algoritmos_ordenacao/selection_sort_dinamico/teste_selection_sort_lista_dinamica.c src/algoritmos_ordenacao/selection_sort_dinamico/selection_sort_lista_dinamica.c src/utilitarios/utilitarios_ordenacao.c src/estruturas/dinamica/lista_encadeada_dinamica.c -o $@

$(BUILD_DIR)/test_insertion_dinamico: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/algoritmos_ordenacao/insertion_sort_dinamico/teste_inserction_lista_dinamica.c src/algoritmos_ordenacao/insertion_sort_dinamico/insertion_sort_lista_dinamica.c src/utilitarios/utilitarios_ordenacao.c src/estruturas/dinamica/lista_encadeada_dinamica.c -o $@

$(BUILD_DIR)/test_merge_dinamico: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/algoritmos_ordenacao/merge_sort_dinamico/teste_merge_sort_lista_dinamica.c src/algoritmos_ordenacao/merge_sort_dinamico/merge_sort_lista_dinamica.c src/utilitarios/utilitarios_ordenacao.c src/estruturas/dinamica/lista_encadeada_dinamica.c -o $@

$(BUILD_DIR)/test_quick_dinamico: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/algoritmos_ordenacao/quick_sort_dinamico/teste_quick_sort_lista_dinamica.c src/algoritmos_ordenacao/quick_sort_dinamico/quick_sort_lista_dinamica.c src/utilitarios/utilitarios_ordenacao.c src/estruturas/dinamica/lista_encadeada_dinamica.c -o $@

$(BUILD_DIR)/test_gerador: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/utilitarios/teste_gerador.c src/utilitarios/gerador_jogadores.c src/estruturas/estatica/lista_encadeada_estatica.c src/estruturas/dinamica/lista_encadeada_dinamica.c -o $@

$(BUILD_DIR)/bench: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/graficos/mede_tempo.c src/estruturas/estatica/lista_encadeada_estatica.c src/estruturas/dinamica/lista_encadeada_dinamica.c src/utilitarios/gerador_jogadores.c src/utilitarios/utilitarios_ordenacao.c src/algoritmos_ordenacao/bubble_sort_estatico/bubble_sort_estatica.c src/algoritmos_ordenacao/bubble_sort_dinamico/bubble_sort_dinamico.c src/algoritmos_ordenacao/insertion_sort_estatico/insertion_sort_estatico.c src/algoritmos_ordenacao/insertion_sort_dinamico/insertion_sort_lista_dinamica.c src/algoritmos_ordenacao/merge_sort_estatico/merge_sort_lista_estatica.c src/algoritmos_ordenacao/merge_sort_dinamico/merge_sort_lista_dinamica.c src/algoritmos_ordenacao/quick_sort_estatico/quick_sort_lista_estatica.c src/algoritmos_ordenacao/quick_sort_dinamico/quick_sort_lista_dinamica.c src/algoritmos_ordenacao/selection_sort_estatico/selection_sort_estatico.c src/algoritmos_ordenacao/selection_sort_dinamico/selection_sort_lista_dinamica.c -o $@

bench: $(BUILD_DIR)/bench
	./$(BUILD_DIR)/bench

ensure-uv:
	@command -v uv >/dev/null 2>&1 || (echo "uv nao encontrado; instalando via pip..." && python3 -m pip install --user uv)

plot: ensure-uv
	uv run python src/graficos/gerador_de_graficos/grafico.py

plot-deps: ensure-uv
	uv sync

clean:
	rm -rf $(BUILD_DIR)
