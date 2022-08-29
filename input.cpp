#include "quadratic.h"
#include "io.h"

///            Input of Square Equation coefficients
/**
*   This function inputs square equation ax2+bx+c=0 coefficients
*
*   @param[IN]   struct Coefficients coeffs  structure that consists of all coefficients of square equation
*   @return     On success return ALLRIGHT, on failure return EXIT
*
**/

int InputCoefficients(Coefficients *coeffs)
{
    printf ("Enter coefficients a, b, c\n");

    int nextchar = 0;

    while (scanf ("%lg %lg %lg", &(coeffs->a), &(coeffs->b), &(coeffs->c) ) != 3)
    {
        if ((nextchar = getchar()) == 'e')
        {
            printf ("Exiting\n");

            return EXIT;
        }

        ClearOfBuffer(nextchar);
        printf("You can enter only numbers or 'e' to exit\n");
    }

    return ALLRIGHT;
}
