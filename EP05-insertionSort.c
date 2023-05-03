#include <stdio.h>
#include <time.h>

#define MAX 5000

void Insertion(int n, int v[]) {
    int i, j, x;
    for (j = 1; j < n; j++) {
        x = v[j];
        for (i = j - 1; i >= 0 && v[i] > x; i--)
            v[i + 1] = v[i];
        v[i + 1] = x;
    }
}

int main() {
    int vetor[MAX];
    int i, n = MAX, j = MAX;
    double time_spent = 0.0;

    clock_t begin = clock();

    for (i = 0; i < MAX; i++) // initialize array with numbers in descending order from MAX to 0
        vetor[i] = j--;

    Insertion(n, vetor);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime taken: %lf seconds", time_spent);

    return 0;
}
