#ifndef MERGESORT_H
#define MERGESORT_H

void merge(int arr[], int left, int middle, int right)
{
   int auxSize = right - left + 1;
   int *aux = (int *)malloc(auxSize * sizeof(int));

   // Copie os elementos para o array auxiliar
   for (int i = left; i <= right; i++)
   {
      aux[i - left] = arr[i];
   }

   int i = left;       // Índice inicial da primeira metade
   int j = middle + 1; // Índice inicial da segunda metade
   int k = left;       // Índice atual no array original arr[]

   while (i <= middle && j <= right)
   {
      if (aux[i - left] <= aux[j - left])
      {
         arr[k] = aux[i - left];
         i++;
      }
      else
      {
         arr[k] = aux[j - left];
         j++;
      }
      k++;
   }

   // Copie os elementos restantes da primeira metade, se houver
   while (i <= middle)
   {
      arr[k] = aux[i - left];
      i++;
      k++;
   }

   // Copie os elementos restantes da segunda metade, se houver
   while (j <= right)
   {
      arr[k] = aux[j - left];
      j++;
      k++;
   }
}

void mergesorteRecurse(int arr[], int left, int right)
{
   if (left < right)
   {
      int middle = (left + right) / 2;
      mergesorteRecurse(arr, left, middle);
      mergesorteRecurse(arr, middle + 1, right);
      merge(arr, left, middle, right);
   }
}

void mergesort(int arr[], int tam)
{
   mergesorteRecurse(arr, 0, tam - 1);
}

#endif