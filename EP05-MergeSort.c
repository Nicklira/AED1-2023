#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5000

void Intercalate(int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = (int*) malloc ((r-p) * sizeof (int));
    i = p;
    j = q;
    k = 0;
    
    while (i < q && j < r) {
        if (v[i] <= v[j])
            w[k++] = v[i++];
        else 
            w[k++] = v[j++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (i = p; i < r; i++)
        v[i] = w[i-p];
    free(w);
}

void Mergesort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r)/2;
        Mergesort(p, q, v);
        Mergesort(q, r, v);
        Intercalate(p, q, r, v);    
    }
}

int main() {
    int vetor[MAX];
    int i, n = MAX, j = MAX;
    double time_spent = 0.0;
    clock_t begin, end;
    
    srand(time(NULL));

    // inicializar vetor com números em ordem decrescente
    for (i = 0; i < MAX; i++) {
        vetor[i] = j--;
    }

    begin = clock();
    Mergesort(0, n, vetor);
    end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTempo igual a %lf segundos\n", time_spent);
    
    return 0;
}
