#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

int buscaBinaria(int arr[], int start, int end, int key, int *operacoes)
{
   *operacoes += 1;
   int middle = (start + end) / 2;

   if (start > end)
      return -1;

   if (key == arr[middle])
      return middle;
   else
   {
      if (key > arr[middle])
         return buscaBinaria(arr, middle + 1, end, key, operacoes);
      else
         return buscaBinaria(arr, start, middle - 1, key, operacoes);
   }
}

#endif