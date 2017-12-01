/** 
 * Document: PoissReg 
 * Chapter: 3      Example: 1      Name: Moving Average Simple
 * MaxFile name: MovingAverageSimple
 * Summary:
 *   CPU code for the Poisson Regression
 * TODO: currently uses SGD.  Would like to implement a second-order method (e.g. Newton-Raphson), which will require cyclic data flow.
 */
#include "Maxfiles.h" 			// Includes .max files
#include <MaxSLiCInterface.h>	// Simple Live CPU interface

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "poissIO.h"

const int dataPoints = 1000; 

int main()
{
  /* float y[dataPoints]; */
  float beta_hat;

  float * y;
  y = malloc(dataPoints * sizeof(float));
  loadObservations(
		   "../data/poisson.y",
		   y,
		   &dataPoints);

  for (int i=0;i<dataPoints;++i)
    printf("%f ",y[i]);
	    
  float * x;
  x == malloc(dataPoints * sizeof(float));
  /* float x[dataPoints]; */
  loadObservations(
		   "../data/poisson.y",
		   x,
		   &dataPoints);

  printf("Running DFE\n");
  MovingAverageSimple(dataPoints, x, y, &beta_hat);

  printf("estimate beta %f\n",beta_hat);
    
  return 0;
}


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
      dest[i++] = strtof(line,NULL);
    }    
  fclose(file);
  return;
}
