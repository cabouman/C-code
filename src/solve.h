#ifndef _SOLVE_H_
#define _SOLVE_H_

/* Solves equation (*f)(x) = 0 on x in [a,b]. Uses half interval method.
 * Requires that (*f)(a) and (*f)(b) have opposite signs.		
 * Returns code=0 if signs are opposite.				
 * Returns code=1 if signs are both positive. 				
 * Returns code=-1 if signs are both negative. 				
 * Returns code=-2 if a NAN or infinity creeps into computation         
 *
 * EXAMPLE
 *
 * typedef struct {
 *   double theta1, theta2;
 * } Parameters;
 *
 * static double f(double x, void * pblock)
 * {
 *    Parameters * p = (Parameters *) pblock;
 *    return (x - 1.0) * p->theta1 + (x - 4.0) * p->theta2;
 * }
 *
 * void test()
 * {
 *    Parameters p;
 *    p.theta1 = 10.0;
 *    p.theta2 = 3.0;
 *    int code;
 *    double ret = solve(f, &p, 1e3, -1e3, 1e-10, &code);
 *
 *    printf("root{%g(x-1.0) + %g(x-4.0)} = %g, with code = %d. f(%g) = %g",
 *           p.theta1, p.theta2, ret, code, ret, f(ret, &p));
 * }
 */

double solve(/* pointer to function to be solved */
             double (*f) (double x, void * pblock), 
             void * pblock, /* parameter passed to callback function f */
             double a,      /* minimum value of solution */
             double b,      /* maximum value of solution */
             double err,    /* accuarcy of solution */
             int *code      /* error code */
             );

#endif /* _SOLVE_H_ */
