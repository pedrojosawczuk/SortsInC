#ifndef SHELLSORT_H
#define SHELLSORT_H

void shellsort(int arr[], int tam)
{
   int h;
   for (h = 1; h < tam; h = 3 * h + 1)
      ;
   while (h > 0)
   {
      h = (h - 1) / 3;
      for (int i = h; i < tam; i++)
      {
         int aux = arr[i];
         int j = i;
         while (arr[j - h] > aux)
         {
            arr[j] = arr[j - h];
            j -= h;
            if (j < h)
               break;
         }
         arr[j] = aux;
      }
   }
}

#endif