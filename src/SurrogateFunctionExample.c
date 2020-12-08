
#include <math.h>
#include "allocate.h"
#include "randlib.h"
#include "typeutil.h"
#include "qGGMRF.h"


int main (int argc, char **argv) 
{
  double delta_prime; /* initial difference between pixel x_s^\prime and its neighbor x_r^\prime */
  double b;           /* neighborhood relationship coefficient. */
  double sigma_x;     /* scale parameter. Increasing sigma_x reduces regularization. */
  double p;           /* 1st shape parameter of qggmrf. Typically, p=1.2, and it is best to choose 1.0<p<=2.0 */
  double q;           /* 2nd shape parameter of qggmrf. It is best to choose q=2.0 */
  double T;           /* threshold parameter of qggmrf. Typically, T=1.0 */
  double btilde;      /* Output value of btilde */
  double *delta, *rho, *Q, offset;
  int i, N, NN;

  N = 100;
  NN = 2*N;

  delta_prime = 2.0;
  b = 1.0;
  sigma_x = 1.0;
  p = 1.2;
  q = 2.0;
  T = 1.0;

  /* allocate memory */
  delta = get_spc(NN, sizeof(double));
  rho = get_spc(NN, sizeof(double));
  Q = get_spc(NN, sizeof(double));

  /* Generate array of delta and rho values */
  for ( i = 0; i < NN; ++i)
  {
    delta[i] = 4.0*(i - N)/N;
  }

  /* Compute btilde and offset constant */
  btilde = get_btilde(delta_prime, b, sigma_x, p, q, T);
  offset = get_rho(delta_prime, b, sigma_x, p, q, T) - btilde*pow(delta_prime,2.0);

  /* Generate array of rho and Q values */
  for ( i = 0; i < NN; ++i)
  {
    /* code */
    rho[i] = get_rho( delta[i], b, sigma_x, p, q, T);
    Q[i] = btilde*pow( delta[i], 2.0) + offset;
  }

  /* printout out results */
  /* fprintf ( stdout, "delta, rho, Q; \n", delta[i], rho[i], Q[i] ); */
  for ( i = 0; i < NN; ++i)
  {
    fprintf ( stdout, "%g, %g, %g; \n", delta[i], rho[i], Q[i] );
  }

  return(0);
}

