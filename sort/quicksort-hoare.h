#ifndef QUICKSORT_HOARE_H
#define QUICKSORT_HOARE_H

int particioneHoare(int vetor[], int left, int right)
{
   int x = vetor[left];
   srand(time(NULL));
   // int x = left + rand() % (right - left + 1);
   int down = left;
   int up = right;

   while (down < up)
   {
      while (vetor[down] <= x && down < right)
      {
         down = down+1;
      }
      while (vetor[up] > x)
      {
         up = up-1;
      }
      if (down < up)
      {
         int aux = vetor[down];
         vetor[down] = vetor[up];
         vetor[up] = aux;
      }
   }
   vetor[left] = vetor[up];
   vetor[up] = x;
   return up;
}

void quicksortRecurse(int vetor[], int left, int right)
{
   int i;
   if (right > left){
      i = particioneHoare(vetor, left, right);
      quicksortRecurse(vetor, left, i-1);
      quicksortRecurse(vetor, i+1, right);
   }
}

void quicksortHoare(int vetor[], int tam) {
   quicksortRecurse(vetor, 0, tam-1);
}

#endif