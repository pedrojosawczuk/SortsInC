#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

int buscaBinaria(int vector[], int start, int end, int key, int *operacoes)
{
   *operacoes += 1;
   int middle = (start + end) / 2;

   if (start > end)
      return -1;

   if (key == vector[middle])
      return middle;
   else
   {
      if (key > vector[middle])
         return buscaBinaria(vector, middle + 1, end, key, operacoes);
      else
         return buscaBinaria(vector, start, middle - 1, key, operacoes);
   }
}

#endif