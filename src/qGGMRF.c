#include "qGGMRF.h"

double get_btilde(
    double delta,   /* difference between pixel x_s and its neighbor x_r */
    double b,       /* neighborhood relationship coefficient. */
    double sigma_x, /* scale parameter. Increasing sigma_x reduces regularization. */
    double p,       /* 1st shape parameter of qggmrf. Typically, p=1.2, and it is best to choose 1.0<p<=2.0 */
    double q,       /* 2nd shape parameter of qggmrf. It is best to choose q=2.0 */
    double T        /* threshold parameter of qggmrf. Typically, T=1.0 */
    ) 
/* Computes the b_tilde parameter used for surrogate function minimization for the qGGMRF prior. */
{
    double b_tilde;
    double tmpa, tmpb, tmpc; /* temporary constants used in calculation */
    
    delta = fabs(delta) + sigma_x*DBL_EPSILON;

    /* tmpa is the product of the first three terms reorganized for numberical stability when q=0. */ 
    tmpa = b*pow(delta,q-2.0)/(2.0*pow(sigma_x,p)*pow(T*sigma_x,q-p));

    /* tmpc is the third term in formula. */ 
    tmpb = pow(delta/(T*sigma_x),q-p);
    tmpc = ((q/p)+tmpb)/pow(1+tmpb,2.0);

    b_tilde = tmpa*tmpb;    
    return b_tilde;
}


double get_rho(
    double delta,   /* difference between pixel x_s and its neighbor x_r */
    double b,       /* neighborhood relationship coefficient. */
    double sigma_x, /* scale parameter. Increasing sigma_x reduces regularization. */
    double p,       /* 1st shape parameter of qggmrf. Typically, p=1.2, and it is best to choose 1.0<p<=2.0 */
    double q,       /* 2nd shape parameter of qggmrf. It is best to choose q=2.0 */
    double T        /* threshold parameter of qggmrf. Typically, T=1.0 */
    ) 
/* Computes the potential function rho for the qGGMRF prior. */
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
