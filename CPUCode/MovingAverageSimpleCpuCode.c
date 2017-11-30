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
	&y,
	&dataPoints);

    float * x;
    x == malloc(dataPoints * sizeof(float));
    /* float x[dataPoints]; */
    loadObservations(
	"../data/poisson.y",
	&x,
	&dataPoints);

    printf("Running DFE\n");
    MovingAverageSimple(dataPoints, x, y, &beta_hat);

    printf("estimate beta %f\n",beta_hat);
    
    return 0;
}
