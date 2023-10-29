#ifndef INSERTSORT_H
#define INSERTSORT_H

void insertsort(int arr[], int tam)
{
   for (int x = 1; x <= tam - 1; x++)
   {
      int aux = arr[x];
      int y = x - 1;

      while (y >= 0 && aux < arr[y])
      {
         arr[y + 1] = arr[y];
         y = y - 1;
         arr[y + 1] = aux;
      }
   }
}

#endif