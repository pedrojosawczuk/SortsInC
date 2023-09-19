#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <dirent.h>

#include "./sort/bubblesort.h"
#include "./sort/insertsort.h"
#include "./sort/selectsort.h"
#include "./sort/shellsort.h"
#include "./sort/quicksort.h"
#include "./sort/quicksort-lomuto.h"
#include "./sort/mergesort.h"
#include "./sort/radixsort.h"
#include "./utils/utils.h"
#include "./utils/autosort.h"
#include "./utils/writeToFile.h"

#define SAMPLES 5
#define ARRAY_SIZE 4
#define SORT_SIZE 8
char PATH_OUT[256] = "./output/";
char PATH_DATA[256] = "./data/";
int name[ARRAY_SIZE] = {5, 50, 75, 100};
int tam[ARRAY_SIZE] = {50000, 500000, 750000, 1000000};
char sortName[SORT_SIZE][255] = {"Bubblesort", "Insertsort", "Selectsort", "Shellsort", "Quicksort", "QuicksortLomuto", "Mergesort", "Radixsort"};
char sortLowerName[SORT_SIZE][255] = {"bubble", "insert", "select", "shell", "quick", "lomuto", "merge", "radix"};

int main(void)
{
   FILE *file;

   char fileName[256];

   int choice;
   int vector[tam[0]];

   printf("Generate new Files?\n");
   printf(" 1 - Yes\n");
   printf(" 0 - No\n");
   scanf("%d", &choice);

   if (choice == 1)
   {
      for (int count = 0; count < ARRAY_SIZE; count++)
      {
         sprintf(fileName, "%s%d-ascending.txt", PATH_DATA, name[count]);
         file = fopen(fileName, "w");

         if (file == NULL)
         {
            system("clear");
            printf("Unable to Create File %s\n", fileName);
            exit(0);
         }

         writeDescendingNumbersToFile(tam[count], file);
         fclose(file);

         sprintf(fileName, "%s%d-descending.txt", PATH_DATA, name[count]);
         file = fopen(fileName, "w");

         if (file == NULL)
         {
            system("clear");
            printf("Unable to Create File %s\n", fileName);
            exit(0);
         }

         writeAscendingNumbersToFile(tam[count], file);
         fclose(file);

         sprintf(fileName, "%s%d-descending.txt", PATH_DATA, name[count]);
         file = fopen(fileName, "r");

         int vector[tam[count]];

         file2Vector(vector, file);

         shuffle(vector, tam[count]);

         fclose(file);

         sprintf(fileName, "%s%d-random.txt", PATH_DATA, name[count]);
         file = fopen(fileName, "w");

         if (file == NULL)
         {
            system("clear");
            printf("Unable to Create File %s\n", fileName);
            exit(0);
         }

         writeVectorNumbersToFile(tam[count], file, vector);
         fclose(file);
         system("clear");
         printf("Files Created Successfully\n");
      }
   }
   // Check for Duplicates on file
   /*
   sprintf(fileName, "%s%d-random.txt", name);
   file = fopen(fileName, "r");
   checkForDuplicateNumbers(tam[count], file);
   fclose(file);*/

   choice = 1;

   double executionTime;

   while (choice != 0)
   {
      printf("Choice a option\n");
      printf(" 1 - AutoSort\n");
      printf("\n");
      printf(" 2 - BubbleSort\n");
      printf(" 3 - InsertSort\n");
      printf(" 4 - SelectSort\n");
      printf(" 5 - ShellSort\n");
      printf(" 6 - QuickSort\n");
      printf(" 7 - QuickSort-Lomuto (NOT WORKING!!!)\n");
      printf(" 8 - MergeSort\n");
      printf(" 9 - RadixSort\n");
      printf(" 0 - Exit\n");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         system("clear");
         printf("Auto...\n");

         for (int i = 0; i < ARRAY_SIZE; i++)
         {
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[0], sortLowerName[0], bubblesort);
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[1], sortLowerName[1], insertsort);
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[2], sortLowerName[2], selectsort);
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[3], sortLowerName[3], shellsort);
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[4], sortLowerName[4], quicksort);
            // autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[5], sortLowerName[5], quicksortLomuto);
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[6], sortLowerName[6], mergesort);
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[7], sortLowerName[7], radixsort);
         }
         break;

      case 2:
         system("clear");

         sprintf(fileName, "%s%d-descending.txt", PATH_DATA, name[0]);
         file = fopen(fileName, "r");
         file2Vector(vector, file);
         imprimeVetor(vector, tam[0]);

         printf("BubbleSort...\n");
         executionTime = measureExecutionTime(bubblesort, vector, tam[0]);

         imprimeVetor(vector, tam[0]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 3:
         system("clear");

         sprintf(fileName, "%s%d-descending.txt", PATH_DATA, name[0]);
         file = fopen(fileName, "r");
         file2Vector(vector, file);
         imprimeVetor(vector, tam[0]);

         printf("InsertSort...\n");
         executionTime = measureExecutionTime(insertsort, vector, tam[0]);

         imprimeVetor(vector, tam[0]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 4:
         system("clear");

         sprintf(fileName, "%s%d-descending.txt", PATH_DATA, name[0]);
         file = fopen(fileName, "r");
         file2Vector(vector, file);
         imprimeVetor(vector, tam[0]);

         printf("SelectSort...\n");
         executionTime = measureExecutionTime(selectsort, vector, tam[0]);

         imprimeVetor(vector, tam[0]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 5:
         system("clear");

         sprintf(fileName, "%s%d-descending.txt", PATH_DATA, name[0]);
         file = fopen(fileName, "r");
         file2Vector(vector, file);
         imprimeVetor(vector, tam[0]);

         printf("ShellSort...\n");
         executionTime = measureExecutionTime(shellsort, vector, tam[0]);

         imprimeVetor(vector, tam[0]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 6:
         system("clear");

         sprintf(fileName, "%s%d-descending.txt", PATH_DATA, name[0]);
         file = fopen(fileName, "r");
         file2Vector(vector, file);
         imprimeVetor(vector, tam[0]);

         printf("QuickSort...\n");
         executionTime = measureExecutionTime(quicksort, vector, tam[0]);

         imprimeVetor(vector, tam[0]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 7:
         system("clear");

         sprintf(fileName, "%s%d-descending.txt", PATH_DATA, name[0]);
         file = fopen(fileName, "r");
         file2Vector(vector, file);
         imprimeVetor(vector, tam[0]);

         printf("QuickSort Lomuto...\n");
         // executionTime = measureExecutionTime(quicksortLomuto, vector, tam[0]);

         imprimeVetor(vector, tam[0]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 8:
         system("clear");

         sprintf(fileName, "%s%d-descending.txt", PATH_DATA, name[0]);
         file = fopen(fileName, "r");
         file2Vector(vector, file);
         imprimeVetor(vector, tam[0]);

         printf("MergeSort...\n");
         executionTime = measureExecutionTime(mergesort, vector, tam[0]);

         imprimeVetor(vector, tam[0]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 9:
         system("clear");

         sprintf(fileName, "%s%d-descending.txt", PATH_DATA, name[0]);
         file = fopen(fileName, "r");
         file2Vector(vector, file);
         imprimeVetor(vector, tam[0]);

         printf("RadixSort...\n");
         executionTime = measureExecutionTime(radixsort, vector, tam[0]);

         imprimeVetor(vector, tam[0]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 0:
         system("clear");
         choice = 0;
         printf("Exiting...\n");
         break;

      default:
         system("clear");
         printf("Invalid Option\n");
         break;
      }
   }

   return 0;
}