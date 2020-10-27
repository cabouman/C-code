#include "get_btilde.h"

double get_btilde(
    double delta,   /* difference between pixel x_s and its neighbor x_r */
    double b,       /* neighborhood relationship coefficient. */
    double sigma_x, /* scale parameter. Increasing sigma_x reduces regularization. */
    double p,       /* 1st shape parameter of qggmrf. Typically, p=1.2, and it is best to choose 1.0<p<=2.0 */
    double q,       /* 2ed shape parameter of qggmrf. It is best to choose q=2.0 */
    double T        /* threshold parameter of qggmrf. Typically, T=1.0 */
    ) 
/* Computes the b_tilde parameter used for surrogate function minimize.*/
/* The value of b_tilde is computed for the qGGMRF potential function.*/
{
    double b_tilde, a, b, c;
    int sgn = 1;
    
    delta = fabs(delta);

    if ( delta==0 ) {
        b_tilde = b/(p*pow(sigma_x,p));
    } else {
        /* compute first two terms in expression */
        consta = b*pow(delta,p-2)/(2*pow(sigma_x,p));

        /* compute third term in expression */
        constb = pow(delta/(T*sigma_x),q-p);
        constc = constb*((q/p)+constb)/pow(1+constb,2.0);

        b_tilde = consta*constb;
    }
    
    return b_tilde;
    
}
