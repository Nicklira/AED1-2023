#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5000

void selection_sort(int n, int v[]) {
    int i, j, min, x;
    
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min]) 
                min = j;
        }
        x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}

void random_array(int n, int v[]) {
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        v[i] = rand() % MAX;
    }
}

void sorted_array(int n, int v[]) {
    int i;
    for (i = 0; i < n; i++) {
        v[i] = i;
    }
}

void reversed_array(int n, int v[]) {
    int i, j = n;
    for (i = 0; i < n; i++) {
        v[i] = j--;
    }
}

int main() {
    int vetor[MAX];
    int i, n = MAX;
    double time_spent = 0.0;
    
    // inicializar vetor com numeros aleatorios
    random_array(n, vetor);
    
    clock_t begin = clock();
    
    // ordenar vetor
    selection_sort(n, vetor);
    
    clock_t end = clock();
    
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    
   
    
    printf("\nTime spent: %lf seconds\n", time_spent);
    
    return 0;
}

