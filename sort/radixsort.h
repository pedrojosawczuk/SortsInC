#ifndef RADIXSORT_H
#define RADIXSORT_H

void radixsort(int vetor[], int tam)
{
   int base = 10, r, m, i, j;;
   int digit = 7;
   int *B = (int *)malloc(tam * sizeof(int));
   int *C = (int *)malloc(base * sizeof(int));

   for (m = 0; m < digit; m++)
   {
      for (i = 0; i < base; ++i)
         C[i] = 0;

      for (j = 0; j < tam; ++j)
      {
         r = (vetor[j] / (int)(pow(10.0, m))) % base;
         ++C[r];
      }

      for (i = 1; i < base; ++i)
         C[i] += C[i - 1];

      for (j = tam - 1; j >= 0; --j)
      {
         r = (vetor[j] / (int)(pow(10.0, m))) % base;
         i = --C[r];
         B[i] = vetor[j];
      }

      for (j = 0; j < tam; ++j)
         vetor[j] = B[j];
   }

   free(B);
   free(C);
}

#endif