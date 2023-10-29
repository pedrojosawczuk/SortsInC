#ifndef UTILS_H
#define UTILS_H

typedef void (*SortFunction)(int[], int);

void imprimeVetor(int arr[], int tam)
{
   for (int cont = 0; cont < tam; cont++)
   {
      printf("%d\t", arr[cont]);
   }
   printf("\n");
}

void shuffle(int *array, int tam)
{
   srand(time(NULL));
   for (int i = tam - 1; i > 0; i--)
   {
      int j = rand() % (i + 1);
      int tmp = array[j];
      array[j] = array[i];
      array[i] = tmp;
   }
}

void checkForDuplicateNumbers(int tam, FILE *file)
{
   int arr[tam];
   char line[255];

   for (int i = 0; i < tam; i++)
   {
      fgets(line, sizeof(line), file);
      arr[i] = atoi(line);
   }

   // Check for duplicate numbers
   for (int i = 0; i < tam - 1; i++)
   {
      for (int j = i + 1; j < tam; j++)
      {
         if (arr[i] == arr[j])
         {
            printf("The numbers on Lines %d and %d are equals.\n", i + 1, j + 1);
         }
      }
   }
   printf("No Duplicate Numbers\n");
}

double measureExecutionTime(SortFunction function, int arr[], int tam)
{
   clock_t start, end;

   start = clock();
   function(arr, tam);
   end = clock();
   double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
   return timeTaken;

   // struct timeval start, end;

   // gettimeofday(&start, NULL);
   // function(arr, tam);
   // gettimeofday(&end, NULL);

   // double timeTaken = (end.tv_sec - start.tv_sec) + (end.tv_sec - start.tv_sec) / 1000000.0;
   // return timeTaken;
}

void file2Vector(int arr[], FILE *file)
{
   int line, i = 0;

   while (!feof(file))
   {
      fscanf(file, "%d", &line);
      arr[i] = line;
      i++;
   }
}

void validaFile(char fileName[255], FILE *file)
{
   if (file == NULL)
   {
      printf("->%s<-", fileName);
      printf("Não foi possível abrir o arquivo");
      exit(0);
   }
}

void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

int isInAscendingOrder(int array[], int size) {
   for (int i = 0; i < size - 1; i++) {
      if (array[i] > array[i + 1]) {
         return 0; // Not in ascending order
      }
   }
   return 1; // In ascending order
}

#endif