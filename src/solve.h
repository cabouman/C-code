#ifndef _SOLVE_H_
#define _SOLVE_H_

/* Solves equation (*f)(x) = 0 on x in [a,b]. Uses half interval method.
 * Requires that (*f)(a) and (*f)(b) have opposite signs.		
 * Returns code=0 if signs are opposite.				
 * Returns code=1 if signs are both positive. 				
 * Returns code=-1 if signs are both negative. 				
 * Returns code=-2 if a NAN or infinity creeps into computation         
 *
 * See SolveExample.c */

double solve(/* pointer to function to be solved */
             double (*f) (double x, void * pblock), 
             void * pblock, /* pointer to structure containing function parameters */
             double a,      /* low bound on solution */
             double b,      /* upper bound on solution */
             double err,    /* accuarcy of solution */
             int *code      /* error code */
             );

#endif /* _SOLVE_H_ */
