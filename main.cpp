#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "quadratic.h"

enum StateOfTest
{
FAULT = 0;
SUCCESS = 1;
};




void OutputSolutions (Solutions solutions);
void InputCoefficients (Coefficients *coeffs);

bool SquareEquationTest (FILE *fp);
void UnitTest ();


int main()
{

    UnitTest();

    Coefficients coeffs = {0, 0, 0};
    Solutions solutions = {0, 0, 0};

    InputCoefficients (&coeffs);

    SolveSquareEquation (coeffs, &solutions);

    OutputSolutions (solutions);

    return 0;
}

void InputCoefficients(Coefficients *coeffs)
{
    printf ("Enter coefficients a, b, c\n");

    int i = 0;

    while (scanf ("%lg %lg %lg", &(coeffs->a), &(coeffs->b), &(coeffs->c) ) != 3)
    {
        while ((i = getchar()) != '\n' && i != EOF)
        {}

        printf("You can enter only numbers\n");
    }
}

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



void UnitTest()
{
    int NumberOfAllTests = 0;
    int NumberOfRightTests = 0;

    const char *FileName = "ForUnitTest.txt";

    FILE *fp = fopen (FileName, "r");
    assert( fp != 0);

    for ( ; NumberOfAllTests < 17; NumberOfAllTests++)
    {
        NumberOfRightTests += SquareEquationTest(fp);
    }
    printf ("Number of right tests %d; Number of all tests %d\n", NumberOfRightTests, NumberOfAllTests);
}

bool SquareEquationTest (FILE *fp)
{                                                                //enum fault

    double rightx1 = 0;
    double rightx2 = 0;

    Coefficients coeffs {5, 10, 3};
    Solutions solutions {0,  0, 3};

    int rightNumb = 0;

    fscanf(fp, "%lg %lg %lg %lg %lg %d ", &(coeffs.a), &(coeffs.b), &(coeffs.c), &rightx1, &rightx2, &rightNumb);

    SolveSquareEquation (coeffs, &solutions);

    if (!(solutions.NumberOfSolutions == rightNumb && (fabs(solutions.x1 - rightx1) <= Epsilon)     \
          && (fabs(solutions.x2 - rightx2) <= Epsilon)))
    {

        printf ("Error in condition, in the line %d, in function %s, in file %s\n", __LINE__, __PRETTY_FUNCTION__, __FILE__);
        printf ("\n");
        printf ("Expected NumberOfSolutions =%d, x1 =%lg, x2 =%lg\n", rightNumb, rightx1, rightx2);
        printf ("Real NumberOfSolutions =%d, x1 =%lg, x2 =%lg \n", solutions.NumberOfSolutions, solutions.x1, solutions.x2);
        printf ("\n");

        return FAULT;
    }
    else
    printf ("Test passed\n");
    printf("\n");

    return SUCCESS;
}



