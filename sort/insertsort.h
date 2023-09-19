#ifndef INSERTSORT_H
#define INSERTSORT_H

void insertsort(int vetor[], int tam)
{
   for (int x = 1; x <= tam - 1; x++)
   {
      int aux = vetor[x];
      int y = x - 1;

      while (y >= 0 && aux < vetor[y])
      {
         vetor[y + 1] = vetor[y];
         y = y - 1;
         vetor[y + 1] = aux;
      }
   }
}

#endif