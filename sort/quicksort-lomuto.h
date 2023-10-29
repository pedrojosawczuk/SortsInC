#ifndef QUICKSORT_LOMUTO_H
#define QUICKSORT_LOMUTO_H

int partitionLomuto(int arr[], int low, int high){
	int pivot_index = (low + high) / 2;
    int pivot = arr[pivot_index];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void quickSortLomutoR(int arr[], int low, int high) 
{ 
	if (low < high) 
	{
		int pi = partitionLomuto(arr, low, high); 

		quickSortLomutoR(arr, low, pi - 1); 
		quickSortLomutoR(arr, pi + 1, high); 
	} 
}

void quicksortLomuto(int arr[], int tam)
{
  quickSortLomutoR(arr, 0, tam);
}

#endif