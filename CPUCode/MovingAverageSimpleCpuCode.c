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

// simdata w/ beta=3
/* float x[dataPoints] = {6.6,  3.6,  3.1,  5.1,  2.1,  6.1,  1.6,  7.1,  0.6,  5.6,  1.1, */
/*         8.1,  0.1,  9.1,  2.6,  7.6,  4.1,  4.6,  9.6,  8.6}; */
/* float y[dataPoints] = {24, 9, 7, 20, 7, 12, 6, 27, 0, 19, 3, 29, 0, 35, 9, 14, 11, 12, 30, 25}; */

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
    MovingAverageSimple(dataPoints, x, y, beta_hat);

    printf("estimate beta %f\n",beta_hat);
    
    return 0;
}
