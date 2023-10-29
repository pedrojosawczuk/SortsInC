#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <dirent.h>

#include "./sort/bubblesort.h"
#include "./sort/insertsort.h"
#include "./sort/selectsort.h"
#include "./sort/shellsort.h"
#include "./sort/quicksort-hoare.h"
#include "./sort/quicksort-lomuto.h"
#include "./sort/mergesort.h"
#include "./sort/radixsort.h"
#include "./sort/heapsort.h"
#include "./search/binarysearch.h"
#include "./utils/utils.h"
#include "./utils/autosort.h"
#include "./utils/writeToFile.h"

#define SAMPLES 5
#define ARRAY_SIZE 7  // número de arquivos de amostras, 0, 1, 2, 3 ou 4
#define SORT_SIZE 9   // número de sort algotimos nos vetores sortName[] and sortLowerName[]
#define SAMPLE_SORT 0 // de 0, 1, 2 ou 3
char PATH_OUT[256] = "./out/";
char PATH_DATA[256] = "./data/";
int name[ARRAY_SIZE] = {5, 7, 10, 25, 50, 75, 100};
int tam[ARRAY_SIZE] = {50000, 75000, 100000, 250000, 500000, 750000, 1000000};
// int name[ARRAY_SIZE] = {5, 50, 75, 100};
// int tam[ARRAY_SIZE] = {50000, 500000, 750000, 1000000};
char sortName[SORT_SIZE][255] = {"Bubblesort", "Insertsort", "Selectsort", "Shellsort", "QuicksortHoare", "QuicksortLomuto", "Mergesort", "Radixsort", "Heapsort"};
char sortLowerName[SORT_SIZE][255] = {"bubble", "insert", "select", "shell", "quickHoare", "quickLomuto", "merge", "radix", "heap"};

int main(void)
{
   FILE *file;

   char fileName[255];

   int choice;
   int arr[tam[SAMPLE_SORT]];

   system("clear");
   printf("Generate new Files?\n \033[1m(This option will replace existing files!!!)\033[0m\n");
   printf(" 1 - Yes\n");
   printf(" 0 - No\n");
   scanf("%d", &choice);

   if (choice == 1)
   {
      for (int count = 0; count < ARRAY_SIZE; count++)
      {
         sprintf(fileName, "%sascending-%d.txt", PATH_DATA, name[count]);
         file = fopen(fileName, "w");
         validaFile(fileName, file);

         if (file == NULL)
         {
            system("clear");
            printf("\033[1mUnable to Create File\033[0m %s\n", fileName);
            exit(0);
         }

         writeDescendingNumbersToFile(tam[count], file);
         fclose(file);

         sprintf(fileName, "%sdescending-%d.txt", PATH_DATA, name[count]);
         file = fopen(fileName, "w");
         validaFile(fileName, file);

         if (file == NULL)
         {
            system("clear");
            printf("\033[1mUnable to Create File\033[0m %s\n", fileName);
            exit(0);
         }

         writeAscendingNumbersToFile(tam[count], file);
         fclose(file);

         sprintf(fileName, "%sdescending-%d.txt", PATH_DATA, name[count]);
         file = fopen(fileName, "r");
         validaFile(fileName, file);

         int arr[tam[count]];

         file2Vector(arr, file);

         shuffle(arr, tam[count]);

         fclose(file);

         sprintf(fileName, "%srandom-%d.txt", PATH_DATA, name[count]);
         file = fopen(fileName, "w");
         validaFile(fileName, file);

         if (file == NULL)
         {
            system("clear");
            printf("\033[1mUnable to Create File\033[0m %s\n", fileName);
            exit(0);
         }

         writeVectorNumbersToFile(tam[count], file, arr);
         fclose(file);
         system("clear");
         printf("\033[1mFiles Created Successfully\033[0m\n");
      }
   }
   // Check for Duplicates on file
   /*
   sprintf(fileName, "%s%d-random.txt", name);
   file = fopen(fileName, "r");
   validaFile(fileName, file);

   checkForDuplicateNumbers(tam[count], file);
   fclose(file);*/

   choice = 1;

   double executionTime;

   while (choice != 0)
   {
      printf("Choice a option\n");
      printf(" 1-\033[1mAuto Sort\033[0m 🤖\n");
      printf("\n");
      printf(" 2-\033[1mBubble Sort\033[0m 🧼\n");
      printf(" 3-\033[1mInsertion Sort\033[0m 🧩\n");
      printf(" 4-\033[1mSelection Sort\033[0m 🎯\n");
      printf(" 5-\033[1mShell Sort\033[0m 🐚\n");
      printf(" 6-\033[1mQuick Sort - Hoare\033[0m ⚡\n");
      printf(" 7-\033[1mQuick Sort - Lomuto\033[0m ⚡\n");
      printf(" 8-\033[1mMerge Sort\033[0m 🧩🧩\n");
      printf(" 9-\033[1mRadix Sort\033[0m 🔍\n");
      printf(" 10-\033[1mHeap Sort\033[0m 📚\n");
      printf(" 0-\033[1mExit\033[0m\n");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         system("clear");
         printf("AutoSort...\n");

         for (int i = 0; i < ARRAY_SIZE-ARRAY_SIZE+1; i++)
         {
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[0], sortLowerName[0], bubblesort);
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[1], sortLowerName[1], insertsort);
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[2], sortLowerName[2], selectsort);
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[3], sortLowerName[3], shellsort);
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[4], sortLowerName[4], quicksortHoare);
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[5], sortLowerName[5], quicksortLomuto);
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[6], sortLowerName[6], mergesort);
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[7], sortLowerName[7], radixsort);
            autosort(SAMPLES, ARRAY_SIZE, PATH_DATA, PATH_OUT, name[i], tam[i], sortName[8], sortLowerName[8], heapsort);
         }
         break;

      case 2:
         system("clear");

         sprintf(fileName, "%sdescending-%d.txt", PATH_DATA, name[SAMPLE_SORT]);
         file = fopen(fileName, "r");
         validaFile(fileName, file);

         file2Vector(arr, file);
         imprimeVetor(arr, tam[SAMPLE_SORT]);

         printf("BubbleSort...\n");
         executionTime = measureExecutionTime(bubblesort, arr, tam[SAMPLE_SORT]);

         imprimeVetor(arr, tam[SAMPLE_SORT]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 3:
         system("clear");

         sprintf(fileName, "%sdescending-%d.txt", PATH_DATA, name[SAMPLE_SORT]);
         file = fopen(fileName, "r");
         validaFile(fileName, file);

         file2Vector(arr, file);
         imprimeVetor(arr, tam[SAMPLE_SORT]);

         printf("InsertSort...\n");
         executionTime = measureExecutionTime(insertsort, arr, tam[SAMPLE_SORT]);

         imprimeVetor(arr, tam[SAMPLE_SORT]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 4:
         system("clear");

         sprintf(fileName, "%sdescending-%d.txt", PATH_DATA, name[SAMPLE_SORT]);
         file = fopen(fileName, "r");
         validaFile(fileName, file);

         file2Vector(arr, file);
         imprimeVetor(arr, tam[SAMPLE_SORT]);

         printf("SelectSort...\n");
         executionTime = measureExecutionTime(selectsort, arr, tam[SAMPLE_SORT]);

         imprimeVetor(arr, tam[SAMPLE_SORT]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 5:
         system("clear");

         sprintf(fileName, "%sdescending-%d.txt", PATH_DATA, name[SAMPLE_SORT]);
         file = fopen(fileName, "r");
         validaFile(fileName, file);

         file2Vector(arr, file);
         imprimeVetor(arr, tam[SAMPLE_SORT]);

         printf("ShellSort...\n");
         executionTime = measureExecutionTime(shellsort, arr, tam[SAMPLE_SORT]);

         imprimeVetor(arr, tam[SAMPLE_SORT]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 6:
         system("clear");

         sprintf(fileName, "%sdescending-%d.txt", PATH_DATA, name[SAMPLE_SORT]);
         file = fopen(fileName, "r");
         validaFile(fileName, file);

         file2Vector(arr, file);
         imprimeVetor(arr, tam[SAMPLE_SORT]);

         printf("QuickSort...\n");
         executionTime = measureExecutionTime(quicksortHoare, arr, tam[SAMPLE_SORT]);

         imprimeVetor(arr, tam[SAMPLE_SORT]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 7:
         system("clear");

         sprintf(fileName, "%sdescending-%d.txt", PATH_DATA, name[SAMPLE_SORT]);
         file = fopen(fileName, "r");
         validaFile(fileName, file);

         file2Vector(arr, file);
         imprimeVetor(arr, tam[SAMPLE_SORT]);

         printf("QuickSort Lomuto...\n");
         executionTime = measureExecutionTime(quicksortLomuto, arr, tam[SAMPLE_SORT]);

         imprimeVetor(arr, tam[SAMPLE_SORT]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 8:
         system("clear");

         sprintf(fileName, "%sdescending-%d.txt", PATH_DATA, name[SAMPLE_SORT]);
         file = fopen(fileName, "r");
         validaFile(fileName, file);

         file2Vector(arr, file);
         imprimeVetor(arr, tam[SAMPLE_SORT]);

         printf("MergeSort...\n");
         executionTime = measureExecutionTime(mergesort, arr, tam[SAMPLE_SORT]);

         imprimeVetor(arr, tam[SAMPLE_SORT]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 9:
         system("clear");

         sprintf(fileName, "%sdescending-%d.txt", PATH_DATA, name[SAMPLE_SORT]);
         file = fopen(fileName, "r");
         validaFile(fileName, file);

         file2Vector(arr, file);
         imprimeVetor(arr, tam[SAMPLE_SORT]);

         printf("RadixSort...\n");
         executionTime = measureExecutionTime(radixsort, arr, tam[SAMPLE_SORT]);

         imprimeVetor(arr, tam[SAMPLE_SORT]);
         printf("Execution time: %f seconds\n", executionTime);
         break;

      case 10:
         system("clear");

         sprintf(fileName, "%sdescending-%d.txt", PATH_DATA, name[SAMPLE_SORT]);
         file = fopen(fileName, "r");
         validaFile(fileName, file);

         file2Vector(arr, file);
         imprimeVetor(arr, tam[SAMPLE_SORT]);

         printf("HeapSort...\n");
         executionTime = measureExecutionTime(heapsort, arr, tam[SAMPLE_SORT]);

         imprimeVetor(arr, tam[SAMPLE_SORT]);
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

   choice = 1;

   while (choice != 0)
   {
      printf("\n");
      printf("Choice a option\n");
      printf(" 1-\033[1mBinary Search\033[0m\n");
      printf("\n");
      printf(" 0-\033[1mExit\033[0m\n");
      scanf("%d", &choice);

      int operacoes = 0;
      int value, resultadoBusca;
      if (choice != 0)
      {
         printf("Qual valor deseja buscar?");
         scanf("%d", &value);
      }

      switch (choice)
      {
      case 1:
         system("clear");

         sprintf(fileName, "%sascending-%d.txt", PATH_DATA, name[SAMPLE_SORT]);
         file = fopen(fileName, "r");
         validaFile(fileName, file);
         printf("%s\n", fileName);

         file2Vector(arr, file);

         resultadoBusca = buscaBinaria(arr, 0, tam[SAMPLE_SORT], value, &operacoes);
         printf("\n Operações Realizadas: %d \n", operacoes);

         if (resultadoBusca != -1)
         {
            printf(" Número %d foi encontrado na posição %d\n", value, resultadoBusca);
         }
         else
         {
            printf(" Número %d não foi encontrado\n", value);
         }

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