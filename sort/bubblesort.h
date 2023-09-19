#ifndef BUBBLESORT_H
#define BUBBLESORT_H

void bubblesort(int vetor[], int tam)
{
   for (int x = tam; x > 1; x--)
   {
      for (int y = 0; y < x - 1; y++)
      {
         if (vetor[y] > vetor[y + 1])
         {
            int aux = vetor[y];
            vetor[y] = vetor[y + 1];
            vetor[y + 1] = aux;
         }
      }
   }
}

#endif