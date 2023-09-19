#ifndef UTILS_H
#define UTILS_H

typedef void (*SortFunction)(int[], int);

void imprimeVetor(int vetor[], int tam)
{
   for (int cont = 0; cont < tam; cont++)
   {
      printf("%d\t", vetor[cont]);
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
   int vector[tam];
   char line[255];

   for (int i = 0; i < tam; i++)
   {
      fgets(line, sizeof(line), file);
      vector[i] = atoi(line);
   }

   // Check for duplicate numbers
   for (int i = 0; i < tam - 1; i++)
   {
      for (int j = i + 1; j < tam; j++)
      {
         if (vector[i] == vector[j])
         {
            printf("The numbers on Lines %d and %d are equals.\n", i + 1, j + 1);
         }
      }
   }
   printf("No Duplicate Numbers\n");
}

double measureExecutionTime(SortFunction function, int vetor[], int tam)
{
   struct timeval start, end;

   gettimeofday(&start, NULL);
   function(vetor, tam);
   gettimeofday(&end, NULL);
   
   double timeTaken = (end.tv_sec - start.tv_sec) + (end.tv_sec - start.tv_sec) / 1000000.0;
   return timeTaken;
}

void file2Vector(int vector[], FILE *file)
{
   int line, i = 0;
   while (fscanf(file, "%d", &line) != EOF)
   {
      vector[i] = line;
      i++;
   }
}

#endif