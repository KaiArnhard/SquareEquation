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
}                                                  \


enum NumberOfSolutions
{
    ZERO_SOLUTIONS =  0,
    ONE_SOLUTION   =  1,
    TWO_SOLUTIONS  =  2,
    INF_SOLUTIONS  = -1
};

int SolveSquareEquation (const double a, const double b, const double c, double* x1, double* x2);
int SolveLinearEquation (const double b, const double c, double* x1);

void OutputSolutions (const int NumbSolutions, const double x1, const double x2);
void InputCoefficients (double *a, double *b, double *c);

bool SquareEquationTest (FILE *fp);
void UnitTest ();

struct Coefficients
    {
        double  a;
        double  b;
        double  c;
    } coeffs {0, 0, 0};

struct Solutions
    {
        double x1;
        double x2;
        int NumbSolutions;
     } solutions {0, 0, 0};


int main()
{
    UnitTest();

    InputCoefficients (&(coeffs.a), &(coeffs.b), &(coeffs.c));


    solutions.NumbSolutions = SolveSquareEquation ( coeffs.a, coeffs.b, coeffs.c, &(solutions.x1), &(solutions.x2));

    OutputSolutions (solutions.NumbSolutions, solutions.x1, solutions.x2);

    return 0;
}

void InputCoefficients(double *a, double *b, double *c)
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

void OutputSolutions (const int NumbSolutions, const double x1, const double x2)
{
    switch (NumbSolutions)
    {
        case ZERO_SOLUTIONS:
            printf("There're no solutions\n");
            break;

        case ONE_SOLUTION:
            printf ("Solution of square equation:\n");
            printf ("%lg \n", x1);
            break;

        case TWO_SOLUTIONS:
            printf ("Solutions of square equation:\n");
            printf ("%lg %lg \n", x1, x2);
            break;

        case INF_SOLUTIONS:
            printf ("All numbers\n");
            break;

        default:
            assert(0);
            break;
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


int SolveLinearEquation (const double b, const double c, double* x1)
{
    if ( b == 0)
    {
        if (c == 0)
        {
            return INF_SOLUTIONS;
        }

        return ZERO_SOLUTIONS;
    }

    *x1 = -(c / b);

    return ONE_SOLUTION;
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


int SolveSquareEquation (const double a, const double b, const double c, double* x1, double* x2)
{
    if (a == 0)
    {
        int NumberOfSolutions = SolveLinearEquation (b, c, x1);
        return NumberOfSolutions;
    }
    else if (b == 0)
    {

        if (c < 0)
        {
            int i = sqrt (-c / a);
            *x1 =  i;
            *x2 = -i;

            return TWO_SOLUTIONS;
        }

        if (c > 0)
        {
            return ZERO_SOLUTIONS;
        }
    }
    if (c == 0)
    {
        *x1 = 0;
        *x2 = -b/a;

        return TWO_SOLUTIONS;
    }

        double discr = 0;


        discr = (b * b) - (4 * a * c);

        double sdiscr = sqrt(discr);

        if (discr > 0)
        {

            *x1 = (-b + sdiscr) / 2 / a;
            *x2 = (-b - sdiscr) / 2 / a;

            return 2;
        }
        else if (discr < 0)
        {

            return ZERO_SOLUTIONS;
        }
        else if (discr <= 0,00001)
        {
            *x1 = -b / 2 / a;

            return ONE_SOLUTION;
        }
}

void UnitTest()
{
    int NumberOfAllTests = 0;
    int NumberOfRightTests = 0;

    const char *FileName = "ForUnitTest.txt";

    FILE *fp = fopen (FileName, "r");
    assert( fp != 0);

    for ( ; NumberOfAllTests < 3; NumberOfAllTests++)
    {
    NumberOfRightTests += SquareEquationTest(fp);
    }
    printf ("Number of right tests %d; Number of all tests %d\n", NumberOfRightTests, NumberOfAllTests);
}

bool SquareEquationTest (FILE *fp)
{
    double rightx1 = 0;
    double rightx2 = 0;
    double  x1 = 0;
    double  x2 = 0;
    double   a = 0;
    double   b = 0;
    double   c = 0;

    int rightNumb = 0;

    int n = fscanf (fp, "%lg %lg %lg %lg %lg %d ", &a, &b, &c, &rightx1, &rightx2, &rightNumb);

    printf("%d\n", n);
    if (n == EOF)
    printf("yes/n");

    int NumbSolutions = SolveSquareEquation ( a, b, c, &x1, &x2);

    if (!(NumbSolutions == rightNumb && x1 == rightx1 && x2 == rightx2))
    {

        printf ("Error in condition, in the line %d, in function %s, in file %s\n", __LINE__, __PRETTY_FUNCTION__, __FILE__);
        printf ("Expected NumbSolutions =%d, x1 =%lg, x2 =%lg\n", rightNumb, rightx1, rightx2);
        printf ("%lg %lg %d \n", x1, x2, NumbSolutions);
        return 0;
    }
    else
    printf ("%lg %lg %lg %lg %lg %d \n", a, b, c, rightx1, rightx2, rightNumb);

    return 1;
}



