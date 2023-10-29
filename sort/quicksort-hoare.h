#ifndef QUICKSORT_HOARE_H
#define QUICKSORT_HOARE_H

int partitionHoare(int *vetor, int tam){
    int x = vetor[tam/2];
    int esq, dir;
    for (esq = 0, dir = tam - 1; ; esq++, dir--) {
        while (vetor[esq] < x){
            esq++;
        }
        while (vetor[dir] > x){
            dir--;
        }
        if (esq >= dir) {
            return esq;
        }
        int aux2 = vetor[esq];
        vetor[esq] = vetor[dir];
        vetor[dir] = aux2;
    }
}

void quickSortHoareR(int *vetor, int tam) {
    if(tam<2){
        return;
    }
    int esq = partitionHoare(vetor, tam);
    if(tam>esq){
        quickSortHoareR(vetor, esq);
        quickSortHoareR(vetor + esq, tam - esq);
    }
}

void quicksortHoare(int arr[], int tam)
{
   quickSortHoareR(arr, tam);
}

#endif