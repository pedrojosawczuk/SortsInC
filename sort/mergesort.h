#ifndef MERGESORT_H
#define MERGESORT_H

void merge(int vetor[], int left, int middle, int right)
{
   int auxSize = right - left + 1;
   int *aux=(int*)malloc(auxSize*sizeof(int));

   // Copie os elementos para o array auxiliar
   for (int i = left; i <= right; i++)
   {
      aux[i - left] = vetor[i];
   }

   int i = left;       // Índice inicial da primeira metade
   int j = middle + 1; // Índice inicial da segunda metade
   int k = left;       // Índice atual no array original vetor[]

   while (i <= middle && j <= right)
   {
      if (aux[i - left] <= aux[j - left])
      {
         vetor[k] = aux[i - left];
         i++;
      }
      else
      {
         vetor[k] = aux[j - left];
         j++;
      }
      k++;
   }

   // Copie os elementos restantes da primeira metade, se houver
   while (i <= middle)
   {
      vetor[k] = aux[i - left];
      i++;
      k++;
   }

   // Copie os elementos restantes da segunda metade, se houver
   while (j <= right)
   {
      vetor[k] = aux[j - left];
      j++;
      k++;
   }
}

void mergesorteRecurse(int vetor[], int left, int right)
{
   if (left < right)
   {
      int middle = (left + right) / 2;
      mergesorteRecurse(vetor, left, middle);
      mergesorteRecurse(vetor, middle + 1, right);
      merge(vetor, left, middle, right);
   }
}

void mergesort(int vetor[], int tam)
{
   mergesorteRecurse(vetor, 0, tam - 1);
}

#endif