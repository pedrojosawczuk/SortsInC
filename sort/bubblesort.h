#ifndef BUBBLESORT_H
#define BUBBLESORT_H

void bubblesort(int arr[], int tam)
{
   for (int x = tam; x > 1; x--)
   {
      for (int y = 0; y < x - 1; y++)
      {
         if (arr[y] > arr[y + 1])
         {
            int aux = arr[y];
            arr[y] = arr[y + 1];
            arr[y + 1] = aux;
         }
      }
   }
}

#endif