//
//  get_btilde.c
//  
//
//  Created by Benjamin Foster on 10/20/15.
//
//

#include "get_btilde.h"

double get_btilde( double delta, double b, double sigma_x, double p, double q, double T) {
    
    double b_tilde, leading_const=0;
    int sgn = 1;
    
    if (delta < 0) {
        sgn = -1;
    }
    
    if ( delta==0 ) {
        b_tilde = b/(p*pow(sigma_x,p));
    } else {
        leading_const = b*pow(fabs(delta),(p-1))/(pow(sigma_x,p))*sgn*pow(fabs(delta)/(T*sigma_x),(q-p))*(q/p + pow(fabs(delta)/(T*sigma_x),q-p))/pow((1+pow(fabs(delta)/(T*sigma_x),q-p)),2);
        b_tilde = leading_const/(2*delta);
    }
    
    return b_tilde;
    
}
