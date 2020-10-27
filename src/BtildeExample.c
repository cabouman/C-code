
#include <math.h>
#include "allocate.h"
#include "randlib.h"
#include "typeutil.h"
#include "qGGMRF.h"


int main (int argc, char **argv) 
{
  double delta;       /* difference between pixel x_s and its neighbor x_r */
  double delta_prime; /* initial difference between pixel x_s^\prime and its neighbor x_r^\prime */
  double b;           /* neighborhood relationship coefficient. */
  double sigma_x;     /* scale parameter. Increasing sigma_x reduces regularization. */
  double p;           /* 1st shape parameter of qggmrf. Typically, p=1.2, and it is best to choose 1.0<p<=2.0 */
  double q;           /* 2nd shape parameter of qggmrf. It is best to choose q=2.0 */
  double T;           /* threshold parameter of qggmrf. Typically, T=1.0 */
  double btilde;      /* Output value of btilde */
  double rho, rho_prime;

  delta = 1.0;

  delta_prime = 1.0;
  b = 1.0;
  sigma_x = 1.0;
  p = 1.2;
  q = 2.0;
  T = 1.0;

  btilde = get_btilde(delta_prime, b, sigma_x, p, q, T);

  rho_prime = get_rho(delta_prime, b, sigma_x, p, q, T);

  fprintf ( stdout, "btilde = %g; rho_prime = %g\n", btilde , rho_prime );

  return(0);
}

