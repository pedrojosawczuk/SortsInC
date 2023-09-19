#ifndef SELECTSORT_H
#define SELECTSORT_H

void selectsort(int vetor[], int tam)
{
   for (int i = 0; i < tam; i++)
   {
      int menorValue = vetor[i];
      int menorPosicao = i;
      for (int j = i; j < tam; j++)
      {
         if (vetor[j] < menorValue)
         {
            menorValue = vetor[j];
            menorPosicao = j;
         }
      }

      int aux = vetor[i];
      vetor[i] = vetor[menorPosicao];
      vetor[menorPosicao] = aux;
   }
}

#endif