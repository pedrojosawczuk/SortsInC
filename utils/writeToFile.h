#ifndef WRITE_TO_FILE_H
#define WRITE_TO_FILE_H

void writeAscendingNumbersToFile(int tam, FILE *file)
{
   fprintf(file, "%d", tam);
   for (int i = tam - 1; i > 0; i--)
   {
      fprintf(file, "\n%d", i);
   }
}

void writeDescendingNumbersToFile(int tam, FILE *file)
{
   fprintf(file, "%d", 1);
   for (int i = 2; i <= tam; i++)
   {
      fprintf(file, "\n%d", i);
   }
}

void writeVectorNumbersToFile(int tam, FILE *file, int *vector)
{
   for (int i = 0; i < tam; i++)
   {
      if (i == 0)
      {
         fprintf(file, "%d", vector[i]);
         continue;
      }
      fprintf(file, "\n%d", vector[i]);
   }
}

#endif