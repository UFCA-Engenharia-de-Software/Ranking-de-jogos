CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Isrc
BUILD_DIR := build-tests

.PHONY: test clean

test: \
	$(BUILD_DIR)/test_lista_estatica \
	$(BUILD_DIR)/test_bubble_dinamico \
	$(BUILD_DIR)/test_quick_static \
	$(BUILD_DIR)/test_insertion_static \
	$(BUILD_DIR)/test_merge_static \
	$(BUILD_DIR)/test_bubble_static \
	$(BUILD_DIR)/test_selection_doubly \
	$(BUILD_DIR)/test_insertion_doubly \
	$(BUILD_DIR)/test_insertion_dinamico \
	$(BUILD_DIR)/test_merge_doubly \
	$(BUILD_DIR)/test_quick_doubly \
	$(BUILD_DIR)/test_gerador
	@set -e; \
	for t in test_lista_estatica test_bubble_dinamico test_quick_static test_insertion_static test_merge_static test_bubble_static test_selection_doubly test_insertion_doubly test_insertion_dinamico test_merge_doubly test_quick_doubly test_gerador; do \
		echo "==> $$t"; \
		./$(BUILD_DIR)/$$t; \
	done

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/test_lista_estatica: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/test_lista_encadeada_estatica.c src/lista_encadeada_estatica.c -o $@

$(BUILD_DIR)/test_bubble_dinamico: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/sortingAlgorithms/bubble_doubly/test_bubble_dinamico.c src/sortingAlgorithms/bubble_doubly/bubble_sort_dinamico.c src/sortingAlgorithms/sorting_utils.c src/lista_encadeada_dinamica.c -o $@

$(BUILD_DIR)/test_quick_static: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/sortingAlgorithms/quick_static/teste_quick_sort_static.c src/sortingAlgorithms/quick_static/quick_sort_lista_estatica.c src/sortingAlgorithms/sorting_utils.c src/lista_encadeada_estatica.c -o $@

$(BUILD_DIR)/test_insertion_static: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/sortingAlgorithms/insertion_sort_estatico/teste_insertion_sort_estatico.c src/sortingAlgorithms/insertion_sort_estatico/insertion_sort_estatico.c src/sortingAlgorithms/sorting_utils.c src/lista_encadeada_estatica.c -o $@

$(BUILD_DIR)/test_merge_static: $(BUILD_DIR)
	$(CC) $(CFLAGS) "src/sortingAlgorithms/merge_estática/teste_merge_sort_lista_estatica.c" "src/sortingAlgorithms/merge_estática/merge_sort_lista_estatica.c" src/sortingAlgorithms/sorting_utils.c src/lista_encadeada_estatica.c -o $@

$(BUILD_DIR)/test_bubble_static: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/sortingAlgorithms/bubble_sort_estatico/teste_bubble_sort_estatica.c src/sortingAlgorithms/bubble_sort_estatico/bubble_sort_estatica.c src/sortingAlgorithms/sorting_utils.c src/lista_encadeada_estatica.c -o $@

$(BUILD_DIR)/test_selection_doubly: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/sortingAlgorithms/selection_sort_duplamente_encadeada/teste_selection_sort_lista_duplamente_encadeada.c src/sortingAlgorithms/selection_sort_duplamente_encadeada/selection_sort_lista_duplamente_encadeada.c src/sortingAlgorithms/sorting_utils.c src/lista_encadeada_dinamica.c -o $@

$(BUILD_DIR)/test_insertion_doubly: $(BUILD_DIR)
	$(CC) $(CFLAGS) -x c src/sortingAlgorithms/insertion_sort/teste_inserction_doubly_list -x none src/sortingAlgorithms/insertion_sort/insertion_sort_doubly_linked_list.c src/sortingAlgorithms/sorting_utils.c src/lista_encadeada_dinamica.c -o $@

$(BUILD_DIR)/test_insertion_dinamico: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/sortingAlgorithms/insertion_sort_dinamico/teste_inserction_lista_dinamica.c src/sortingAlgorithms/insertion_sort_dinamico/insertion_sort_lista_dinamica.c src/sortingAlgorithms/sorting_utils.c src/lista_encadeada_dinamica.c -o $@

$(BUILD_DIR)/test_merge_doubly: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/sortingAlgorithms/merge_doubly/test_merge_sort.c src/sortingAlgorithms/merge_doubly/merge_sort_doubly_linked_list.c src/sortingAlgorithms/sorting_utils.c src/lista_encadeada_dinamica.c -o $@

$(BUILD_DIR)/test_quick_doubly: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/sortingAlgorithms/quick_doubly/teste_quick_sort.c src/sortingAlgorithms/quick_doubly/quick_sort_lista_dupla.c src/sortingAlgorithms/sorting_utils.c src/lista_encadeada_dinamica.c -o $@

$(BUILD_DIR)/test_gerador: $(BUILD_DIR)
	$(CC) $(CFLAGS) src/utilitarios/teste_gerador.c src/utilitarios/gerador_jogadores.c src/lista_encadeada_estatica.c -o $@

clean:
	rm -rf $(BUILD_DIR)
