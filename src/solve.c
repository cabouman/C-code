#include "solve.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "typeutil.h"

double solve(/* pointer to function to be solved */
             double (*f) (double x, void * pblock), 
             void * pblock, /* pointer to structure containing function parameters */
             double a,      /* low bound on solution */
             double b,      /* upper bound on solution */
             double err,    /* desired accuarcy of solution */
             int *code      /* error code */
             )
/* Solves equation (*f)(x) = 0 on x in the intervale [a,b] using the half interval method. */
/* Requires that (*f)(a) and (*f)(b) have opposite signs.           */
/* Returns code=0 if signs are opposite.				            */
/* Returns code=1 if signs are both positive.                       */
/* Returns code=-1 if signs are both negative.                      */
/* Returns code=-2 if a NAN or infinity creeps into computation.    */
{
    int     signa, signb, signc;
    double  fa, fb, fc, c;
    double  dist;

    fa = f(a, pblock);  signa = fa>0;
    fb = f(b, pblock);  signb = fb>0;
    if(!isfinite(fa)) goto err;
    if(!isfinite(fb)) goto err;

    /* check starting conditions */
    if( signa==signb ) {
        if(signa==1) *code = 1;
        else *code = -1;
        return(0.0);
    }
    else *code = 0;

    /* half interval search */
    if( (dist=b-a)<0 ) dist = -dist;
    while(dist>err) {
        c = (b+a)/2;
        fc = f(c, pblock);  signc = fc>0;
        if(!isfinite(fc)) goto err;

        if(signa == signc) { a = c; fa = fc; }
        else { b = c; fb = fc; }
        if( (dist=b-a)<0 ) dist = -dist;
    }

    /* linear interpolation */
    if( (fb-fa)==0 ) return(a);
    else {
        c = (a*fb - b*fa)/(fb-fa);
        return(c);
    }

 err:
    *code = -2;
    return a;
}

