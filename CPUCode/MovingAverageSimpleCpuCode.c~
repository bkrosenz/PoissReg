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

const int dataPoints = 20; 

float beta_hat[20]; 

int main()
{
    
// simdata w/ beta=3
    float x[20] = {6.6,  3.6,  3.1,  5.1,  2.1,  6.1,  1.6,  7.1,  0.6,  5.6,  1.1, 8.1,  0.1,  9.1,  2.6,  7.6,  4.1,  4.6,  9.6,  8.6};
    float y[20] = {24, 9, 7, 20, 7, 12, 6, 27, 0, 19, 3, 29, 0, 35, 9, 14, 11, 12, 30, 25};

	printf("Running DFE\n");
	MovingAverageSimple(dataPoints, x, y, &beta_hat);

    for (int i=0;i<dataPoints;++i)
        printf("estimate beta %d: %f\n",i,beta_hat[i]);
    
	return 0;
}
