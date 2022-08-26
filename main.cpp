#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "quadratic.h"
#include "input.h"
#include "output.h"
#include "unittest.h"


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
