#include "quadratic.h"
#include "modulecomparison.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

///            Solve of Square Equation when coefficient b equal to 0
/**
*   This function solves square equations ax2+c=0
*
*   @param[IN]   struct Coefficients coeffs  structure that consists of all coefficients of square equation
*   @param[OUT]  struct Solutions solutions  structure that consists of quantity of solutions and values of solutions
*
**/


void SolveSquareEquationBnull(Coefficients coeffs, Solutions *solutions)
{
    if (coeffs.a > 0)
    {

        if (coeffs.c < 0)
        {
            double ModuleOfSolution = sqrt (-coeffs.c / coeffs.a);

            solutions->x1 =  ModuleOfSolution;
            solutions->x2 = -ModuleOfSolution;
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
            double SquareRootdiscr = sqrt (-coeffs.c / coeffs.a);

            solutions->x1 =  SquareRootdiscr;
            solutions->x2 = -SquareRootdiscr;
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
*   @param[IN]   struct Coefficients coeffs  structure that consists of all coefficients of linear equation
*   @param[OUT]  struct Solutions solutions  structure that consists of quantity of solutions and values of solutions
*
**/


void SolveLinearEquation (Coefficients coeffs, Solutions *solutions)
{
    ASSERT(solutions != NULL);

    if (modulecomparison(coeffs.b, 0))
    {
        if (modulecomparison(coeffs.c, 0))
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

///            Solve of Square Equation with discriminant
/**
*   This function solves square equations ax2+bx+c=0
*
*   @param[IN]   struct Coefficients coeffs  structure that consists of all coefficients of square equation
*   @param[OUT]  struct Solutions solutions  structure that consists of quantity of solutions and values of solutions
**/


void SolveSquareEquationDiscr(Coefficients coeffs, Solutions *solutions)
{
    double discr = 0;

    discr = (coeffs.b * coeffs.b) - (4 * coeffs.a * coeffs.c);

    double sdiscr = sqrt(discr);

    if (modulecomparison(discr, 0))
    {
        solutions->x1 = -coeffs.b / 2 / coeffs.a;
        solutions->NumberOfSolutions = ONE_SOLUTION;
    }
    else if (discr > 0)
    {

        solutions->x1 = (-coeffs.b + sdiscr) / 2 / coeffs.a;
        solutions->x2 = (-coeffs.b - sdiscr) / 2 / coeffs.a;
        solutions->NumberOfSolutions = TWO_SOLUTIONS;
    }
    else if (discr < 0)
    {
        solutions->NumberOfSolutions = ZERO_SOLUTIONS;
    }
}

///            Solve of Square Equation
/**
*   This function solves square equations ax2+bx+c=0
*
*   @param[IN]   struct Coefficients coeffs  structure that consists of all coefficients of square equation
*   @param[OUT]  struct Solutions solutions  structure that consists of quantity of solutions and values of solutions
**/


int SolveSquareEquation (Coefficients coeffs, Solutions *solutions)
{
    ASSERT(solutions != NULL);

    if (modulecomparison(coeffs.a, 0))
    {
        SolveLinearEquation (coeffs, solutions);

        return 0;
    }
    else if (modulecomparison(coeffs.b, 0))
    {
     SolveSquareEquationBnull(coeffs, solutions);
     return 0;
    }
    if (modulecomparison(coeffs.c, 0))
    {
        solutions->x1 = 0;
        solutions->x2 = -coeffs.b / coeffs.a;
        solutions->NumberOfSolutions = TWO_SOLUTIONS;

        return 0;
    }
    SolveSquareEquationDiscr(coeffs, solutions);

    return 0;
}
