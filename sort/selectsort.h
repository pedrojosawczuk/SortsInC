#ifndef SELECTSORT_H
#define SELECTSORT_H

void selectsort(int arr[], int tam)
{
   for (int i = 0; i < tam; i++)
   {
      int menorValue = arr[i];
      int menorPosicao = i;
      for (int j = i; j < tam; j++)
      {
         if (arr[j] < menorValue)
         {
            menorValue = arr[j];
            menorPosicao = j;
         }
      }

      int aux = arr[i];
      arr[i] = arr[menorPosicao];
      arr[menorPosicao] = aux;
   }
}

#endif