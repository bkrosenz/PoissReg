/*
 * Document: MaxCompiler State Machine Tutorial (maxcompiler-sm-tutorial.pdf)
 * Example: 5
 * Summary:
 *      Functions to load and save images from the file system.
 */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


void loadObservations(char *filename, float *dest, const int *length)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
    {
      perror("Error opening observations file.\n");
    }

//  dest = malloc((*length) * sizeof(float));
  char* line = NULL;
  size_t len = 0;
  int i = 0;
  while ( getline(&line, &len, file) != -1)
    {
      //  printf("%d %s\n", i, line);
	dest[i++] = strtof(line,NULL);
    }
  /*       exit(1); */
    /*   dest[i] = atoi(buf); */
    /*   ++i; */
    /* } */
    //(file, "%d\n", &dest[i]))
    
    fclose(file);
    return;
}
