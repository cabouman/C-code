
#include <math.h>
#include "allocate.h"
#include "randlib.h"
#include "typeutil.h"
#include "get_btilde.h"


int main (int argc, char **argv) 
{
  double delta;  /* difference between pixel x_s and its neighbor x_r */
  double b;       /* neighborhood relationship coefficient. */
  double sigma_x; /* scale parameter. Increasing sigma_x reduces regularization. */
  double p;       /* 1st shape parameter of qggmrf. Typically, p=1.2, and it is best to choose 1.0<p<=2.0 */
  double q;       /* 2nd shape parameter of qggmrf. It is best to choose q=2.0 */
  double T;       /* threshold parameter of qggmrf. Typically, T=1.0 */
  double btilde;  /* Output value of btilde */

  delta = 1.0;
  b = 1.0;
  sigma_x = 1.0;
  p = 1.2;
  q = 2.0;
  T = 1.0;

  btilde = get_btilde(delta, b, sigma_x, p, q, T);

  fprintf ( stdout, "btilde = %g\n", btilde );

  return(0);
}

