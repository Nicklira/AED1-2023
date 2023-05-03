#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX 5000

void maxHeap(int m, int v[]) {
    int f = m + 1;
    int t;

    while (f > 0 && v[f/2] < v[f]) {
        t = v[f/2]; 
        v[f/2] = v[f];
        v[f] = t;
        f = f/2;
    }
}

void heapify(int m, int v[]) {
    int t, f = 2;

    while (f <= m) {
        if (f < m && v[f] < v[f+1])
            ++f;
        if (v[f/2] >= v[f])
            break;
        t = v[f/2];
        v[f/2] = v[f];
        v[f] = t;
        f *= 2;
    }
}

void heapSort(int n, int v[]) {
    int i, m, t, first;

    for (m = 1; m < n; m++) {
        maxHeap(m-1, v);
    }
    for (m = n-1; m > 0; m--) {
        t = v[1];
        v[1] = v[m];
        v[m] = t;
        heapify(m-1, v);
    }
    for (i = 0; i < n-1; i++) {
        first = v[i];
        v[i] = v[i+1];
        v[i+1] = first;
    }
}

int main() {
    int vetor[MAX];
    int i, n = MAX, j = MAX;
    double time_spent = 0.0;

    clock_t begin = clock();
    srand(time(NULL));

    for (i = 0; i < MAX; i++) {
        vetor[i] = (rand() % MAX);
    }

    heapSort(n, vetor);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (i = 0; i < MAX; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nTime spent: %lf seconds", time_spent);

    return 0;
}
