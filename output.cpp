#include "quadratic.h"
#include "output.h"
#include <stdio.h>
#include <assert.h>


///            Output of Square Equation solutions
/**
*   This function outputs square equation ax2+bx+c=0 solutions
*
*   @param[in]  struct Solutions solutions structure that consists of quantity of solutions and values of solutions
*
**/


void OutputSolutions (Solutions solutions)
{

    switch (solutions.NumberOfSolutions)
    {
        case ZERO_SOLUTIONS:
            printf("There're no solutions\n");
            break;

        case ONE_SOLUTION:
            printf ("Solution of square equation:\n");
            printf ("%lg \n", solutions.x1);
            break;

        case TWO_SOLUTIONS:
            printf ("Solutions of square equation:\n");
            printf ("%lg %lg \n", solutions.x1, solutions.x2);
            break;

        case INF_SOLUTIONS:
            printf ("All numbers\n");
            break;

        default:
            assert(0);
            break;
    }
}
