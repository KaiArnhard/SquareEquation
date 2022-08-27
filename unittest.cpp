#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "quadratic.h"
#include "unittest.h"
#include "modulecomparison.h"

///            Unit Test of Square Equation
/**
*   This function tests function SolveSquareEquation seventeen times
*
**/

void UnitTest()
{
    int NumberOfAllTests = 1;
    int NumberOfRightTests = 0;

    const char *FileName = "ForUnitTest.txt";

    FILE *fp = fopen (FileName, "r");
    assert( fp != 0);

    for ( ; NumberOfAllTests <= 17; NumberOfAllTests++)
    {
        printf("Test Number %d. Status:", NumberOfAllTests);
        NumberOfRightTests += SquareEquationTest(fp);
    }
    printf ("Number of right tests %d; Number of all tests %d\n", NumberOfRightTests, NumberOfAllTests);
}

///            One Test of Square Equation
/**
*   This function tests function SolveSquareEquation one time
*
*   @param[IN]   FILE *fp   pointer of file which includes quantity of solutions and values of solutions
**/

bool SquareEquationTest (FILE *fp)
{

    double rightx1 = 0;
    double rightx2 = 0;

    Coefficients coeffs {5, 10, 3};
    Solutions solutions {0,  0, 3};

    int rightNumb = 0;

    fscanf(fp, "%lg %lg %lg %lg %lg %d ", &(coeffs.a), &(coeffs.b), &(coeffs.c), &rightx1, &rightx2, &rightNumb);

    SolveSquareEquation (coeffs, &solutions);

    if (!(solutions.NumberOfSolutions == rightNumb && modulecomparison(solutions.x2, rightx2)     \
          && modulecomparison(solutions.x2, rightx2)))
    {
        printf ("failed\n");
        printf ("Error in condition, in the line %d, in function %s, in file %s\n", __LINE__, __PRETTY_FUNCTION__, __FILE__);
        printf ("\n");
        printf ("Expected NumberOfSolutions =%d, x1 =%lg, x2 =%lg\n", rightNumb, rightx1, rightx2);
        printf ("Real NumberOfSolutions =%d, x1 =%lg, x2 =%lg \n", solutions.NumberOfSolutions, solutions.x1, solutions.x2);
        printf ("\n");

        return FAULT;
    }
    else
    printf ("passed\n");
    printf("\n");

    return SUCCESS;
}

