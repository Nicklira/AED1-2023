#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CIDADES 1000

typedef struct {
    int cidade;
    struct Rota* prox;
} Rota;

int bfs(int n, Rota** rotas, int curytiba, int riacho, int estadunido) {
    bool visited[MAX_CIDADES + 1] = { false };
    visited[curytiba] = true;

    int queue[MAX_CIDADES];
    int front = 0;
    int rear = 0;

    queue[rear++] = curytiba;

    int horas[MAX_CIDADES + 1] = { 0 };

    while (front < rear) {
        int cidade = queue[front++];
        if (cidade == riacho) {
            return horas[cidade];
        }

        Rota* atual = rotas[cidade];
        while (atual != NULL) {
            int vizinha = atual->cidade;

            if (!visited[vizinha] && vizinha != estadunido) {
                visited[vizinha] = true;
                queue[rear++] = vizinha;
                horas[vizinha] = horas[cidade] + 1;
            }

            atual = atual->prox;
        }
    }

    return -1;
}

void adicionarRota(Rota** rotas, int cidade1, int cidade2) {
    Rota* rota = (Rota*)malloc(sizeof(Rota));
    rota->cidade = cidade2;
    rota->prox = rotas[cidade1];
    rotas[cidade1] = rota;

    rota = (Rota*)malloc(sizeof(Rota));
    rota->cidade = cidade1;
    rota->prox = rotas[cidade2];
    rotas[cidade2] = rota;
}

void liberarRotas(Rota** rotas, int n) {
    for (int i = 1; i <= n; i++) {
        Rota* atual = rotas[i];
        while (atual != NULL) {
            Rota* proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
    }
}

int main() {
    int n, m;

    while (scanf("%d %d", &n, &m) != EOF) {
        Rota** rotas = (Rota**)malloc((n + 1) * sizeof(Rota*));
        for (int i = 1; i <= n; i++) {
            rotas[i] = NULL;
        }

        for (int i = 0; i < m; i++) {
            int cidade1, cidade2;
            scanf("%d %d", &cidade1, &cidade2);
            adicionarRota(rotas, cidade1, cidade2);
        }

        int curytiba, riacho, estadunido;
        scanf("%d %d %d", &curytiba, &riacho, &estadunido);

        int resultado = bfs(n, rotas, curytiba, riacho, estadunido);
        printf("%d\n", resultado);

        liberarRotas(rotas, n);
        free(rotas);
    }

    return 0;
}
