#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define ASSERT(condition)                          \
{                                                  \
    if (!(condition))                              \
    printf ("Error in condition %s, in the line %d,\
    in function %s, in file %s\n", #condition,     \
     __LINE__, __PRETTY_FUNCTION__, __FILE__);     \
}
#define Epsilon 0.00001

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

void OutputSolutions (Solutions solutions);
void InputCoefficients (Coefficients *coeffs);

bool SquareEquationTest (FILE *fp);
void UnitTest ();

//struct


int main()
{
                                                        //код ошибки?
    UnitTest();                                         //warning in SolveSquareEquation?

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

    if (coeffs.b == 0)
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
    else if (discr <=Epsilon)
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
}

void UnitTest()
{
    int NumberOfAllTests = 0;
    int NumberOfRightTests = 0;

    const char *FileName = "ForUnitTest.txt";

    FILE *fp = fopen (FileName, "r");
    assert( fp != 0);

    for ( ; NumberOfAllTests < 7; NumberOfAllTests++)
    {
        NumberOfRightTests += SquareEquationTest(fp);
    }
    printf ("Number of right tests %d; Number of all tests %d\n", NumberOfRightTests, NumberOfAllTests);
}

bool SquareEquationTest (FILE *fp)
{

    double rightx1 = 0;
    double rightx2 = 0;

    Coefficients coeffs {0, 0, 0};
    Solutions solutions {0, 0, 0};

    int rightNumb = 0;

    fscanf(fp, "%lg %lg %lg %lg %lg %d ", &(coeffs.a), &(coeffs.b), &(coeffs.c), &rightx1, &rightx2, &rightNumb);

    SolveSquareEquation (coeffs, &solutions);

    if (!(solutions.NumberOfSolutions == rightNumb && (fabs(solutions.x1 - rightx1) <= Epsilon)     \
          && (fabs(solutions.x2 - rightx2) <= Epsilon)))
    {

        printf ("Error in condition, in the line %d, in function %s, in file %s\n", __LINE__, __PRETTY_FUNCTION__, __FILE__);
        printf ("\n");
        printf ("Expected NumberOfSolutions =%d, x1 =%lg, x2 =%lg\n", rightNumb, rightx1, rightx2);
        printf ("Real NumberOfSolutions =%lg, x1 =%lg, x2 =%lg \n", solutions.NumberOfSolutions, solutions.x1, solutions.x2);
        printf ("\n");

        return 0;
    }
    else
    printf ("Test passed\n");
    printf("\n");

    return 1;
}



