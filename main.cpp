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

struct Solutions SolveSquareEquation ();
struct Solutions SolveLinearEquation ();

void OutputSolutions (struct Solutions solutions);
struct Coefficients InputCoefficients ();

bool SquareEquationTest (FILE *fp);
void UnitTest ();

//struct

struct Solutions
    {
        double x1;
        double x2;
        int NumberOfSolutions;
     };

struct Coefficients
    {
        double  a;
        double  b;
        double  c;

    };


int main()
{

    //UnitTest();

    struct Coefficients coeffs {0, 0, 0};

    coeffs = InputCoefficients ();

    struct Solutions solutions {0, 0, 0};

    solutions = SolveSquareEquation ();

    OutputSolutions (solutions);

    return 0;
}

struct Coefficients InputCoefficients()
{
    printf ("Enter coefficients a, b, c\n");

    int i = 0;

    struct Coefficients coeffs;

    while (scanf ("%lg %lg %lg", &(coeffs.a), &(coeffs.b), &(coeffs.c) ) != 3)
    {
        while ((i = getchar()) != '\n' && i != EOF)
        {}

        printf("You can enter only numbers\n");
    }
    return coeffs;
}

void OutputSolutions (struct Solutions solutions)
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


struct Solutions SolveLinearEquation ()
{

    struct Solutions solutions;
    struct Coefficients coeffs;

    if (coeffs.b == 0)
    {
        if (coeffs.c == 0)
        {
            solutions.NumberOfSolutions = INF_SOLUTIONS;

            return solutions;
        }

        solutions.NumberOfSolutions = ZERO_SOLUTIONS;

        return solutions;
    }

    solutions.x1 = -(coeffs.c / coeffs.b);
    solutions.NumberOfSolutions = ZERO_SOLUTIONS;

    return solutions;
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


struct Solutions SolveSquareEquation ()
{

    struct Solutions solutions;
    struct Coefficients coeffs;

    if (coeffs.a == 0)
    {
        struct Solutions NumberOfSolutions = SolveLinearEquation ();

        return NumberOfSolutions;
    }
    else if (coeffs.b == 0)
    {

        if (coeffs.c < 0)
        {
            int i = sqrt (-coeffs.c / coeffs.a);

            solutions.x1 =  i;
            solutions.x2 = -i;
            solutions.NumberOfSolutions = TWO_SOLUTIONS;

            return solutions;
        }

        if (coeffs.c > 0)
        {
            solutions.NumberOfSolutions = ZERO_SOLUTIONS;

            return solutions;
        }
    }
    if (coeffs.c == 0)
    {
        solutions.x1 = 0;
        solutions.x2 = -coeffs.b / coeffs.a;
        solutions.NumberOfSolutions = TWO_SOLUTIONS;

        return solutions;
    }

        double discr = 0;


        discr = (coeffs.b * coeffs.b) - (4 * coeffs.a * coeffs.c);

        double sdiscr = sqrt(discr);

        if (discr > 0)
        {

            solutions.x1 = (-coeffs.b + sdiscr) / 2 / coeffs.a;
            solutions.x2 = (-coeffs.b - sdiscr) / 2 / coeffs.a;
            solutions.NumberOfSolutions = TWO_SOLUTIONS;

            return solutions;
        }
        else if (discr < 0)
        {
            solutions.NumberOfSolutions = ZERO_SOLUTIONS;

            return solutions;
        }
        else if (discr <= 0,00001)
        {
            solutions.x1 = -coeffs.b / 2 / coeffs.a;
            solutions.NumberOfSolutions = ONE_SOLUTION;

            return solutions;
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

    int NumbSolutions; //= SolveSquareEquation ();

    if (!(NumbSolutions == rightNumb && (fabs(x1 - rightx1) <= 0.0000001) && (fabs(x2 - rightx2) <= 0.0000001)))
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



