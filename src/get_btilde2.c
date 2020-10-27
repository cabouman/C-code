#include "get_btilde.h"

double get_btilde( double delta, double b, double sigma_x, double p, double q, double T ) 
/* Computes the b_tilde parameter used for surrogate function minimization for the qGGMRF prior. */
{
    double b_tilde;
    double tmpa, tmpb, tmpc; /* temporary constants used in calculation */
    
    delta = fabs(delta); /* + sigma_x*DBL_EPSILON; */

    /* tmpa is the product of the first three terms reorganized for numberical stability when q=0. */ 
    tmpa = b*pow(delta,q-2.0)/(2.0*pow(sigma_x,p)*pow(T*sigma_x,q-p));

    /* tmpc is the third term in formula. */ 
    tmpb = pow(delta/(T*sigma_x),q-p);
    tmpc = ((q/p)+tmpb)/pow(1+tmpb,2.0);

    b_tilde = tmpa*tmpb;    
    return b_tilde;
}
