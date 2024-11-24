#include <stdio.h>
#include <string.h>

#define MAX_CATEGORIAS 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
} Categoria;

// Função para cadastrar uma nova categoria
void cadastrarCategoria(Categoria categorias[], int *quantidade) {
    if (*quantidade >= MAX_CATEGORIAS) {
        printf("Limite de categorias atingido!\n");
        return;
    }

    printf("Digite o nome da nova categoria: ");
    getchar(); // Limpar o buffer
    fgets(categorias[*quantidade].nome, MAX_NOME, stdin);
    
    // Remover o '\n' do final da string, caso exista
    categorias[*quantidade].nome[strcspn(categorias[*quantidade].nome, "\n")] = '\0';

    (*quantidade)++;

    printf("Categoria cadastrada com sucesso!\n\n");
}

// Função para listar as categorias cadastradas
void listarCategorias(Categoria categorias[], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhuma categoria cadastrada.\n");
        return;
    }

    printf("\nCategorias cadastradas:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d. %s\n", i + 1, categorias[i].nome);
    }
}

// Função para editar uma categoria existente
void editarCategoria(Categoria categorias[], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhuma categoria cadastrada para editar.\n");
        return;
    }

    int escolha;
    listarCategorias(categorias, quantidade);

    printf("Escolha o número da categoria que deseja editar: ");
    scanf("%d", &escolha);

    if (escolha < 1 || escolha > quantidade) {
        printf("Escolha inválida.\n");
        return;
    }

    printf("Digite o novo nome para a categoria %d: ", escolha);
    getchar(); // Limpar o buffer
    fgets(categorias[escolha - 1].nome, MAX_NOME, stdin);
    categorias[escolha - 1].nome[strcspn(categorias[escolha - 1].nome, "\n")] = '\0';

    printf("Categoria editada com sucesso!\n\n");
}

int main() {
    Categoria categorias[MAX_CATEGORIAS];
    int quantidade = 0;
    int opcao;

    do {
        printf("\n--- Menu de Categorias de Suplementos ---\n");
        printf("1. Cadastrar nova categoria\n");
        printf("2. Listar categorias cadastradas\n");
        printf("3. Editar categoria existente\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCategoria(categorias, &quantidade);
                break;
            case 2:
                listarCategorias(categorias, quantidade);
                break;
            case 3:
                editarCategoria(categorias, quantidade);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
