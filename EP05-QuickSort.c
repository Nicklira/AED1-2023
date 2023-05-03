#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5000

int divide(int p, int r, int v[]) {
    int c = v[r], j = p, k, t;
    for (k = p; k < r; k++) {
        if (v[k] <= c) {
            t = v[j]; v[j] = v[k]; v[k] = t;
            j++;
        }
    }
    v[r] = v[j]; v[j] = c;
    return j;
}

void quicksort(int p, int r, int v[]) {
    if (p < r) {
        int j = divide(p, r, v);
        quicksort(p, j - 1, v);
        quicksort(j + 1, r, v);
    }
}

int main() {
    int vetor[MAX];
    int i, n = MAX, j = MAX;
    double time_spent = 0.0;

    clock_t begin = clock();
    srand(time(NULL));

    for (i = 0; i < MAX; i++) {
        vetor[i] = j--;
    }
    quicksort(0, n, vetor);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime taken = %lf", time_spent);
    return 0;
}
