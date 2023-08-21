#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int *a, int MAX);
 
int main(int argc, char** argv){
    clock_t start, end;
    double cpu_time_used = 0.0;
    start = clock();
    FILE *arq;
    arq = fopen("arquivo.txt", "r");
    int MAX;
    fscanf(arq, "%d", &MAX);
    int i, vet[MAX];
 
    for(i = 0; i < MAX; i++){
        fscanf(arq, "%d", &vet[i]);
    }
    insertion_sort(vet, MAX);

    for(i = 0; i < MAX; i++){
        printf("%d ", vet[i]);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf ("\nTEMPO: %f ", cpu_time_used);
    return 0;
}

void insertion_sort(int *a, int MAX)
{
    int i, j, tmp;
  
    for(i = 1; i < MAX; i++){
        tmp = a[i];
    for(j = i-1; j >= 0 && tmp < a[j]; j--){
        a[j+1] = a[j];
    }
        a[j+1] = tmp;
    }
}