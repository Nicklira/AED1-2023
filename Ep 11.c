#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

void hashing(int N, int** cases) {
    for (int i = 0; i < N; i++) {
        int M = cases[i][0];
        int C = cases[i][1];
        int* keys = cases[i] + 2;

        // Inicializar a tabela de dispersão com listas vazias
        Node** hashtable = (Node**)malloc(M * sizeof(Node*));
        for (int j = 0; j < M; j++) {
            hashtable[j] = NULL;
        }

        // Função de dispersão: h(x) = x mod M
        int hash_function(int key) {
            return key % M;
        }

        // Inserção das chaves na tabela de dispersão com tratamento de colisão por encadeamento exterior
        for (int j = 0; j < C; j++) {
            int key = keys[j];
            int address = hash_function(key);

            // Criar um novo nó para a chave
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->key = key;
            newNode->next = NULL;

            // Inserir o nó na lista encadeada correspondente ao endereço
            if (hashtable[address] == NULL) {
                hashtable[address] = newNode;
            } else {
                Node* curr = hashtable[address];
                while (curr->next != NULL) {
                    curr = curr->next;
                }
                curr->next = newNode;
            }
        }

        // Imprimir a tabela de dispersão
        for (int j = 0; j < M; j++) {
            printf("%d -> ", j);
            Node* curr = hashtable[j];
            while (curr != NULL) {
                printf("%d -> ", curr->key);
                curr = curr->next;
            }
            printf("\\\n");
        }

        if (i < N - 1) {
            printf("\n");
        }

        // Liberar a memória alocada para a tabela de dispersão
        for (int j = 0; j < M; j++) {
            Node* curr = hashtable[j];
            while (curr != NULL) {
                Node* temp = curr;
                curr = curr->next;
                free(temp);
            }
        }
        free(hashtable);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int** cases = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        int M, C;
        scanf("%d %d", &M, &C);

        cases[i] = (int*)malloc((C + 2) * sizeof(int));
        cases[i][0] = M;
        cases[i][1] = C;

        for (int j = 0; j < C; j++) {
            scanf("%d", &cases[i][j + 2]);
        }
    }

    // Chamada da função principal
    hashing(N, cases);

    // Liberar a memória alocada para os casos de teste
    for (int i = 0; i < N; i++) {
        free(cases[i]);
    }
    free(cases);

    return 0;
}
