#include "quadratic.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

void SolveSquareEquationBnull(Coefficients coeffs, Solutions *solutions)
{
    if (coeffs.a > 0)
    {

        if (coeffs.c < 0)
        {
            double i = sqrt (-coeffs.c / coeffs.a);

            solutions->x1 =  i;
            solutions->x2 = -i;
            solutions->NumberOfSolutions = TWO_SOLUTIONS;

        }
        else if (coeffs.c > 0)
        {
            solutions->NumberOfSolutions = ZERO_SOLUTIONS;

        }
        else
        {
            solutions->x1 = 0;
            solutions->NumberOfSolutions = ONE_SOLUTION;
        }
    }
    else
    {
    if (coeffs.c > 0)
        {
            double i = sqrt (-coeffs.c / coeffs.a);

            solutions->x1 =  i;
            solutions->x2 = -i;
            solutions->NumberOfSolutions = TWO_SOLUTIONS;

        }
        else if (coeffs.c < 0)
        {
            solutions->NumberOfSolutions = ZERO_SOLUTIONS;

        }
    }
}

///            Solve of Linear Equation
/**
*   This function solves linear equations bx+c=0
*
*   @param[IN]   double b    first coefficient of linear equation
*   @param[IN]   double c    second coefficient of linear equation
*   @param[OUT] double x1    solution of linear equation
*   @param[OUT] int nSolutions  quantity of solutions
*
**/


void SolveLinearEquation (Coefficients coeffs, Solutions *solutions)
{
    ASSERT(solutions != NULL);

    if (coeffs.b <= EPSILON)
    {
        if (coeffs.c == 0)
        {
            solutions->NumberOfSolutions = INF_SOLUTIONS;

        }
        else
        {
            solutions->NumberOfSolutions = ZERO_SOLUTIONS;
        }
    }
    else
    {
        solutions->x1 = -(coeffs.c / coeffs.b);
        solutions->NumberOfSolutions = ONE_SOLUTION;
    }
}

void SolveSquareEquationDiscr(Coefficients coeffs, Solutions *solutions)
{
    double discr = 0;

    discr = (coeffs.b * coeffs.b) - (4 * coeffs.a * coeffs.c);

    double sdiscr = sqrt(discr);

    if (discr > 0)
    {

        solutions->x1 = (-coeffs.b + sdiscr) / 2 / coeffs.a;
        solutions->x2 = (-coeffs.b - sdiscr) / 2 / coeffs.a;
        solutions->NumberOfSolutions = TWO_SOLUTIONS;
    }
    else if (discr < 0)
    {
        solutions->NumberOfSolutions = ZERO_SOLUTIONS;
    }
    else if (discr <= Epsilon)
    {
        solutions->x1 = -coeffs.b / 2 / coeffs.a;
        solutions->NumberOfSolutions = ONE_SOLUTION;
    }
}

///            Solve of Square Equation
/**
*   This function solves square equations ax2+bx+c=0
*
*   @param[IN] double a     first coefficient of square equation
*   @param[IN] double b    second coefficient of square equation
*   @param[IN] double c     third coefficient of square equation
*   @param[OUT] double x1      first solution of square equation
*   @param[OUT] double x2     second solution of square equation
*   @param[OUT] int nSolutions  quantity of solutions
*
**/


int SolveSquareEquation (Coefficients coeffs, Solutions *solutions)
{
    ASSERT(solutions != NULL);

    if (coeffs.a == 0)
    {
        SolveLinearEquation (coeffs, solutions);

        return 0;
    }
    else if (coeffs.b == 0)
    {
     SolveSquareEquationBnull(coeffs, solutions);
     return 0;
    }
    if (coeffs.c == 0)
    {
        solutions->x1 = 0;
        solutions->x2 = -coeffs.b / coeffs.a;
        solutions->NumberOfSolutions = TWO_SOLUTIONS;

        return 0;
    }
    SolveSquareEquationDiscr(coeffs, solutions);

    return 0;
}
