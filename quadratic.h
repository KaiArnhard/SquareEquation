#ifndef QUADRATIC_H
#define QUADRATIC_H

#define ASSERT(condition)                          \
{                                                  \
    if (!(condition))                              \
    printf ("Error in condition %s, in the line %d,\
    in function %s, in file %s\n", #condition,     \
     __LINE__, __PRETTY_FUNCTION__, __FILE__);     \
}
const double EPSILON = 0.00001;

enum NumberOfSolutions
{
    ZERO_SOLUTIONS =  0,
    ONE_SOLUTION   =  1,
    TWO_SOLUTIONS  =  2,
    INF_SOLUTIONS  = -1
};

typedef struct
    {
        double  a;
        double  b;
        double  c;

    } Coefficients;

typedef struct
    {
        double x1;
        double x2;
        int NumberOfSolutions;
     } Solutions;

int  SolveSquareEquation      (Coefficients coeffs, Solutions *solutions);

void SolveLinearEquation      (Coefficients coeffs, Solutions *solutions);
void SolveSquareEquationBnull (Coefficients coeffs, Solutions *solutions);
void SolveSquareEquationDiscr (Coefficients coeffs, Solutions *solutions);

#endif
