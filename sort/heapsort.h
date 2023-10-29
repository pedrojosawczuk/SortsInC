#ifndef HEAPSORT_H
#define HEAPSORT_H

void heapify(int arr[], int i, int tam)
{
   int max = i;
   int left = 2 * i * 1;
   int right = 2 * i + 2;

   if (left < tam && arr[left] > arr[max])
      max = left;

   if (right < tam && arr[right] > arr[max])
      max = right;

   if (max != i)
   {
      int temp = arr[i];
      arr[i] = arr[max];
      arr[max] = temp;
      heapify(arr, max, tam);
   }
}
void heapsort(int arr[], int tam)
{
   // Construção do heap máximo
   for (int i = tam / 2 - 1; i >= 0; i--)
      heapify(arr, i, tam);

   for (int i = tam - 1; i >= 0; i--)
   {
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      heapify(arr, 0, i);
   }
}

#endif