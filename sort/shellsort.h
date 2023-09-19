#ifndef SHELLSORT_H
#define SHELLSORT_H

void shellsort(int vector[], int tam)
{
   int h;
   for (h = 1; h < tam; h =3*h+1);
   while (h > 0)
   {
      h = (h-1)/3;
      for (int i = h; i < tam; i++)
      {
         int aux = vector[i];
         int j = i;
         while (vector[j - h] > aux)
         {
            vector[j] = vector[j - h];
            j -= h;
            if (j < h)
               break;
         }
         vector[j] = aux;
      }
   }
}

#endif