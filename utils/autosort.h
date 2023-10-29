#ifndef AUTOSORT_H
#define AUTOSORT_H

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#include "utils.h"
#include "writeToFile.h"

typedef void (*SortFunction)(int[], int);

void autosort(int SAMPLES, int ARRAY_SIZE, char PATH_DATA[256], char PATH_OUT[256], int name, int tam, char sortName[255], char sortLowerName[255], SortFunction function)
{
  FILE *file;
  FILE *output;

  char fileName[255];

  for (int i = 0; i < SAMPLES; i++)
  {
    sprintf(fileName, "%s%s-%d-output.txt", PATH_OUT, sortLowerName, name);
    output = fopen(fileName, "a");
    validaFile(fileName, output);

    int choice;
    int arr[tam];

    double executionTime;

    printf("[AUTO] %s[%d](%d/%d) in '%s' |", sortName, tam, i + 1, SAMPLES, fileName);

    sprintf(fileName, "%sascending-%d.txt", PATH_DATA, name);
    file = fopen(fileName, "r");
    validaFile(fileName, file);

    file2Vector(arr, file);
    fclose(file);
    executionTime = measureExecutionTime(function, arr, tam);
    if (isInAscendingOrder(arr, tam))
    {
      printf(" [✔️]");
    }
    else
    {
      printf(" [❌]");
    }
    fprintf(output, "%f", executionTime);
    printf("asc: %f seconds", executionTime);

    sprintf(fileName, "%sdescending-%d.txt", PATH_DATA, name);
    file = fopen(fileName, "r");
    validaFile(fileName, file);

    file2Vector(arr, file);
    fclose(file);
    executionTime = measureExecutionTime(function, arr, tam);
    if (isInAscendingOrder(arr, tam))
    {
      printf(" [✔️]");
    }
    else
    {
      printf(" [❌]");
    }
    fprintf(output, ";%f", executionTime);
    printf("desc: %f seconds", executionTime);

    sprintf(fileName, "%srandom-%d.txt", PATH_DATA, name);
    file = fopen(fileName, "r");
    validaFile(fileName, file);

    file2Vector(arr, file);
    fclose(file);
    executionTime = measureExecutionTime(function, arr, tam);
    if (isInAscendingOrder(arr, tam))
    {
      printf(" [✔️]");
    }
    else
    {
      printf(" [❌]");
    }
    fprintf(output, ";%f\n", executionTime);
    printf("rand: %f seconds\n", executionTime);
    fclose(output);
  }
}

#endif