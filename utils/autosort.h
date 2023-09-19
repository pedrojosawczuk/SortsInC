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
   char outputFileName[255];

   for (int i = 0; i < SAMPLES; i++)
   {
      sprintf(outputFileName, "%s%d-%s-output.txt", PATH_OUT, name, sortLowerName);
      output = fopen(outputFileName, "a");

      int choice;
      int vector[tam];

      double executionTime;

      printf("[AUTO] %s[%d](%d/%d) in '%s' |", sortName, tam, i + 1, SAMPLES, outputFileName);
      fprintf(output, "%s[%d](%d/%d): \n", sortName, tam, i + 1, SAMPLES);

      sprintf(fileName, "%s%d-ascending.txt", PATH_DATA, name);
      file = fopen(fileName, "r");
      file2Vector(vector, file);
      fclose(file);
      executionTime = measureExecutionTime(function, vector, tam);
      fprintf(output, "  Ascending: %f seconds\n", executionTime);
      printf(" asc: %f seconds", executionTime);

      sprintf(fileName, "%s%d-descending.txt", PATH_DATA, name);
      file = fopen(fileName, "r");
      file2Vector(vector, file);
      fclose(file);
      executionTime = measureExecutionTime(function, vector, tam);
      fprintf(output, "  Descending: %f seconds\n", executionTime);
      printf(" desc: %f seconds", executionTime);

      sprintf(fileName, "%s%d-random.txt", PATH_DATA, name);
      file = fopen(fileName, "r");
      file2Vector(vector, file);
      fclose(file);
      executionTime = measureExecutionTime(function, vector, tam);
      fprintf(output, "  Random: %f seconds\n\n", executionTime);
      printf(" rand: %f seconds\n", executionTime);
      fclose(output);
   }
}

#endif