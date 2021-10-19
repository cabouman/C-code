
#include <math.h>
#include "allocate.h"
#include "randlib.h"
#include "typeutil.h"
#include "solve.h"

/* Solves equation (*f)(x) = 0 on x in [a,b]. Uses half interval method.
 * Requires that (*f)(a) and (*f)(b) have opposite signs.		
 * Returns code=0 if signs are opposite.				
 * Returns code=1 if signs are both positive. 				
 * Returns code=-1 if signs are both negative. 				
 * Returns code=-2 if a NAN or infinity creeps into computation         
 *
 * EXAMPLE */
 
typedef struct {
  double theta1, theta2;
} Parameters;

static double MyFunction(double x, void * pblock);


int main (int argc, char **argv) 
{
  Parameters p;
  int error_code;
  double root, fvalue, min_solution, max_solution, epsilon;

  p.theta1 = 10.0;
  p.theta2 = 3.0;
  min_solution = -1e3;
  max_solution = 1e3;
  epsilon = 1e-10;

  printf("Rooting the function f(x) = %g * (x - %g)^3 \n", p.theta2, p.theta1 );
  printf("Lower bound = %g; upper bound = %g; precision = %g; \n", min_solution, max_solution, epsilon);

  root = solve(MyFunction, &p, min_solution, max_solution, epsilon, &error_code);
  fvalue = MyFunction(root, &p);

  printf("root = %3.10f, with code = %d; theta1 = %g; theta2 = %g; f(%g) = %g; \n",
          root, error_code, p.theta1, p.theta2, root, fvalue);
}
 

static double MyFunction(double x, void * pblock)
{
  Parameters *p;
  double fvalue;

  /* Retype pblock as a pointer to the parameter structure */
  p = (Parameters *) pblock;

  /* Compute function and return value */
  fvalue = pow(x - p->theta1, 3 )*(p->theta2);
  return fvalue;
}


