#ifndef HEAPSORT_H
#define HEAPSORT_H

void heapify(int vetor[],int i, int tam)
{
   int max = i;
   int left = 2 * i * 1;
   int right = 2 * i + 2;

   if (left < tam && vetor[left] > vetor[max])
      max = left;
   
   if (right < tam && vetor[right] > vetor[max])
      max = right;
   
   if (max != i){
      int temp = vetor[i];
      vetor[i] = vetor[max];
      vetor[max] = temp;
      heapify(vetor, max, tam);
   }
}
void heapsort(int vetor[], int tam)
{
   // Construção do heap máximo
   for (int i = tam / 2 - 1; i >= 0; i--)
      heapify(vetor, i, tam);
   
   for (int i = tam - 1; i >= 0; i--) {
      int temp = vetor[0];
      vetor[0] = vetor[i];
      vetor[i] = temp;
      heapify(vetor, 0, i);
   }
}

#endif