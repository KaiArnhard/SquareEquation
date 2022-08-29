#include "quadratic.h"
#include "common.h"

///            Solve of Square Equation when coefficient b equal to 0
/**
*   This function solves square equations ax2+c=0
*
*   @param[IN]   struct Coefficients coeffs  structure that consists of all coefficients of square equation
*   @param[IN]   struct Solutions *solutions  pointer to structure that consists of quantity of solutions and values of solutions
*
**/

void SolveSquareEquationBnull(Coefficients coeffs, Solutions *solutions)
{
    if (coeffs.a > EPSILON)
    {
      *solutions = SolveSquareEquationPlusA (coeffs, *solutions);
    }
    else
    {
      *solutions = SolveSquareEquationMinusA (coeffs, *solutions);
    }
}

///            Solve of Square Equation when coefficient b equal to 0 and when coefficient a > 0
/**
*   This function solves square equations ax2+c=0
*
*   @param[IN]   struct Coefficients coeffs  structure that consists of all coefficients of square equation
*   @param[IN]   struct Solutions solutions  structure that consists of quantity of solutions and values of solutions
*   @return      On success return struct Solutions solutions on fail return ASSERT
*
**/

Solutions SolveSquareEquationPlusA(Coefficients coeffs, Solutions solutions)
{
if (coeffs.c < -EPSILON)
        {
            double ModuleOfSolution = sqrt (-coeffs.c / coeffs.a);

            solutions.x1 =  ModuleOfSolution;
            solutions.x2 = -ModuleOfSolution;
            solutions.NumberOfSolutions = TWO_SOLUTIONS;

            return solutions;

        }
        else if (coeffs.c > EPSILON)
        {
            solutions.NumberOfSolutions = ZERO_SOLUTIONS;

            return solutions;
        }
        else
        {
            solutions.x1 = 0;
            solutions.NumberOfSolutions = ONE_SOLUTION;

            return solutions;
        }
        ASSERT(0 && "Error in function");
}

///            Solve of Square Equation when coefficient b equal to 0  and coefficient a < 0
/**
*   This function solves square equations ax2+c=0
*
*   @param[IN]   struct Coefficients coeffs  structure that consists of all coefficients of square equation
*   @param[IN]   struct Solutions solutions  structure that consists of quantity of solutions and values of solutions
*   @return      On success return struct Solutions solutions on fail return ASSERT
**/

Solutions SolveSquareEquationMinusA (Coefficients coeffs, Solutions solutions)
{
    if (coeffs.c > EPSILON)
        {
            double SquareRootdiscr = sqrt (-coeffs.c / coeffs.a);

            solutions.x1 =  SquareRootdiscr;
            solutions.x2 = -SquareRootdiscr;
            solutions.NumberOfSolutions = TWO_SOLUTIONS;

            return solutions;

        }
        else if (coeffs.c < -EPSILON)
        {
            solutions.NumberOfSolutions = ZERO_SOLUTIONS;

            return solutions;
        }

        ASSERT(0 && "Error in function");
}

///            Solve of Linear Equation
/**
*   This function solves linear equations bx+c=0
*
*   @param[IN]   struct Coefficients coeffs  structure that consists of all coefficients of linear equation
*   @param[IN]  struct Solutions solutions  structure that consists of quantity of solutions and values of solutions
*
**/

void SolveLinearEquation (Coefficients coeffs, Solutions *solutions)
{
    ASSERT(solutions != NULL);

    if (ModuleComparison(coeffs.b, 0))
    {
        if (ModuleComparison(coeffs.c, 0))
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

    if (ModuleComparison(discr, 0))
    {
        solutions->x1 = -coeffs.b / 2 / coeffs.a;
        solutions->NumberOfSolutions = ONE_SOLUTION;
    }
    else if (discr > EPSILON)
    {
        solutions->x1 = (-coeffs.b + sdiscr) / 2 / coeffs.a;
        solutions->x2 = (-coeffs.b - sdiscr) / 2 / coeffs.a;
        solutions->NumberOfSolutions = TWO_SOLUTIONS;
    }
    else if (discr < -EPSILON)
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
*   @return     On success return 0
**/

int SolveSquareEquation (Coefficients coeffs, Solutions *solutions)
{
    ASSERT(solutions != NULL);

    if (ModuleComparison(coeffs.a, 0))
    {
        SolveLinearEquation (coeffs, solutions);

        return 0;
    }
    else if (ModuleComparison(coeffs.b, 0))
    {
        SolveSquareEquationBnull(coeffs, solutions);

        return 0;
    }

    if (ModuleComparison(coeffs.c, 0))
    {
        solutions->x1 = 0;
        solutions->x2 = -coeffs.b / coeffs.a;
        solutions->NumberOfSolutions = TWO_SOLUTIONS;

        return 0;
    }

    SolveSquareEquationDiscr(coeffs, solutions);

    return 0;
}
