#include <stdio.h>
#include "quadratic.h"

///            Input of Square Equation coefficients
/**
*   This function inputs square equation ax2+bx+c=0 coefficients
*
*   @param[IN]   struct Coefficients coeffs  structure that consists of all coefficients of square equation
*
**/

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
