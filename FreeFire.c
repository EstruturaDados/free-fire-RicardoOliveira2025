//===================================================
//  MOCHILA DE SOBREVIVENCIA   -   CODIGO DA ILHA
//===================================================
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

#define MAX_ITENS 10
Item inventario[MAX_ITENS];
int contadorItens = 0;

void inserirItem();
void removerItem();
void listarItens();
void buscarItem();
void exibirMenu();

void listarItens() {
    printf("\n--- Inventário Atual (%d/%d) ---\n", contadorItens, MAX_ITENS);


    if (contadorItens == 0) {
        printf("A mochila está vazia. Cadastre itens para começar!\n");
        return;
    }

    for (int i = 0; i < contadorItens; i++) {
        printf("  [%d] Nome: %s, Tipo: %s, Quantidade: %d\n",
               i + 1,
               inventario[i].nome,
               inventario[i].tipo,
               inventario[i].quantidade);
    }
    printf("--------------------------------------\n");
}

void inserirItem() {
    if (contadorItens >= MAX_ITENS) {
        printf("\n Mochila cheia! Não é possível adicionar mais itens (%d/%d).\n", MAX_ITENS, MAX_ITENS);
        return;
    }

    printf("\n--- Cadastro de Novo Item ---\n");
    Item novoItem;

    printf("Digite o NOME do item (sem espacos): ");
    scanf("%29s", novoItem.nome);

    printf("Digite o TIPO do item (ex: arma, municao, cura): ");
    scanf("%19s", novoItem.tipo); 

    
    printf("Digite a QUANTIDADE: ");
    while (scanf("%d", &novoItem.quantidade) != 1 || novoItem.quantidade < 1) {
        printf("Entrada invalida. Digite uma quantidade inteira positiva: ");
        while (getchar() != '\n');
    }
    
    inventario[contadorItens] = novoItem;
    contadorItens++;

    printf("\n Item '%s' cadastrado com sucesso!\n", novoItem.nome);
}

void removerItem() {
    char nomeBusca[30];
    int i, encontrado = 0;

    if (contadorItens == 0) {
        printf("\n Nao ha itens na mochila para remover.\n");
        return;
    }

    printf("\n---  Remocao de Item ---\n");
    printf("Digite o NOME do item que deseja remover (sem espacos): ");
    scanf("%29s", nomeBusca);

    for (i = 0; i < contadorItens; i++) {
        if (strcmp(inventario[i].nome, nomeBusca) == 0) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        printf(" Item '%s' encontrado e removido.\n", inventario[i].nome);

        for (int j = i; j < contadorItens - 1; j++) {
            inventario[j] = inventario[j+1];
        }

        contadorItens--;
    } else {
        printf(" Item '%s' nao encontrado na mochila.\n", nomeBusca);
    }
}

void buscarItem() {
    char nomeBusca[30];
    int i, encontrado = 0;

    if (contadorItens == 0) {
        printf("\n Nao ha itens na mochila para buscar.\n");
        return;
    }

    printf("\n--- Busca de Item ---\n");
    printf("Digite o NOME do item que deseja buscar (sem espacos): ");
    scanf("%29s", nomeBusca);

    for (i = 0; i < contadorItens; i++) {
        if (strcmp(inventario[i].nome, nomeBusca) == 0) {
            encontrado = 1;
            break; // Item encontrado
        }
    }

    if (encontrado) {
        printf("\n Item ENCONTRADO:\n");
        printf("  Nome: %s\n", inventario[i].nome);
        printf("  Tipo: %s\n", inventario[i].tipo);
        printf("  Quantidade: %d\n", inventario[i].quantidade);
    } else {
        printf("\n Item '%s' nao foi encontrado no inventario.\n", nomeBusca);
    }
}

void exibirMenu() {
    printf("\n============================================\n");
    printf(" Sistema de Gerenciamento de Inventario \n");
    printf("============================================\n");
    printf("1. Cadastrar Novo Item\n");
    printf("2. Remover Item por Nome\n");
    printf("3. Listar Todos os Itens\n");
    printf("4. Buscar Item por Nome\n");
    printf("5. Sair do Sistema\n");
    printf("--------------------------------------------\n");
    printf("Escolha uma opcao (1-5): ");
}

int main() {
    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.

    return 0;
}

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
