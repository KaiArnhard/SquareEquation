///            Solve of Square Equation
/**
*   This program solves square equations ax2+bx+c=0
*
*   @param[IN] double a     first coefficient of square equation
*   @param[IN] double b    second coefficient of square equation
*   @param[IN] double c     third coefficient of square equation
*   @param[OUT] double x1    first solution of square equation
*   @param[OUT] double x2   second solution of square equation
*   @param[OUT] int nSolutions  quantity of solutions
*
**/

#include <stdio.h>
#include <math.h>
#include <assert.h>

#define ASSERT(condition)                          \
{                                                  \
    if (!(condition))                              \
    printf ("Error in condition %s, in the line %d,\
    in function %s, in file %s\n", #condition,     \
     __LINE__, __PRETTY_FUNCTION__, __FILE__);     \
}                                                  \


enum NumberOfSolutions
{
    ZERO_SOLUTIONS = 0,
    ONE_SOLUTION   = 1,
    TWO_SOLUTIONS  = 2,
    INF_SOLUTIONS  = 3
};

int SolveSquareEquation (const double a, const double b, const double c, double* x1, double* x2, int nSolutions);
int SolveLinearEquation (const double b, const double c, double* x1, int nSolutions);

void OutputSolutions (const int nSolutions, const double x1, const double x2);
void InputCoefficients (double* a, double* b, double* c);

void SquareEquationTest ();


int main()
{
    double  a = 0;
    double  b = 0;
    double  c = 0;

    InputCoefficients (&a, &b, &c);

    double x1 = 0;
    double x2 = 0;

    int nSolutions = 0;

    nSolutions = SolveSquareEquation (a, b, c, &x1, &x2, nSolutions);

    OutputSolutions (nSolutions, x1, x2);

    return 0;
}

void InputCoefficients(double* a, double* b, double* c)
{
    printf ("Enter coefficients a, b, c\n");

    int i = 0;

    while (scanf ("%lg %lg %lg", a, b, c) != 3)
    {
        while ((i = getchar()) != '\n' && i != EOF)
        {}

        printf("You can enter only numbers\n");
    }
}

void OutputSolutions (const int nSolutions, const double x1, const double x2)
{
    switch (nSolutions)
    {
        case ZERO_SOLUTIONS:
            printf("There're no solutions\n");
            break;

        case ONE_SOLUTION:
            printf ("Solution of square equation:\n");
            printf ("%f \n", x1);
            break;

        case TWO_SOLUTIONS:
            printf ("Solutions of square equation:\n");
            printf ("%f %f \n", x1, x2);
            break;

        case INF_SOLUTIONS:
            printf ("All numbers\n");
            break;

        default:
            assert(0);
            break;
    }
}

int SolveLinearEquation (double b, double c, double* x1, int nSolutions)
{
    if ( b == 0)
    {
        if (c == 0)
        {
            nSolutions = INF_SOLUTIONS;

            return nSolutions;
        }

        nSolutions = 0;

        return nSolutions;
    }

    *x1 = -(c / b);
    nSolutions = 1;

    return nSolutions;
}

int SolveSquareEquation (double a, double b, double c, double* x1, double* x2, int nSolutions)
{
    if (a == 0)
    {
        SolveLinearEquation (b, c, x1, nSolutions);
    }
    else if (b == 0)
    {

        if (c < 0)
        {
            int i = sqrt (-c / a);
            *x1 =  i;
            *x2 = -i;
            nSolutions = 2;

            return nSolutions;
        }

        if (c > 0)
        {
            nSolutions = 0;

            return nSolutions;
        }
    }

    double discr = 0;

    discr = (b * b) - (4 * a * c);

    double sdiscr = sqrt(discr);

    if (discr > 0)
    {

        *x1 = (-b + sdiscr) / 2 / a;
        *x2 = (-b - sdiscr) / 2 / a;
        nSolutions = 2;

        return nSolutions;
    }
    else if (discr < 0)
    {
        nSolutions = 0;

        return nSolutions;
    }
    else if (discr == 0)
    {
        *x1 = -b / 2 / a;
        nSolutions = 1;

        return nSolutions;
    }
}

void SquareEquationTest ()
{
  double x1 = 0;
  double x2 = 0;
  int nSolutions = SolveSquareEquation( 1, 0, -4, &x1, &x2, nSolutions);
  ASSERT( nSolutions == 2 && x1 == 2 && x2 == -2);
}
