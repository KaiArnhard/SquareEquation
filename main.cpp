#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "quadratic.h"
#include "input.h"
#include "output.h"
#include "unittest.h"


int main(int argc, char *argv[])
{

    Coefficients coeffs = {0, 0, 0};
    Solutions solutions = {0, 0, 0};

    int id = 1;

    for ( ; id < argc; id++)
    {
        if (*argv[id] == '-')
            {
                switch (argv[id][1])
                {
                    case 'h' :

                    printf( "-h - show information about launch\n -t - launch test mode\n");
                    break;

                    case 't' :

                    UnitTest();
                    break;

                    default:

                    printf ("Wrong command\n");

                    break;

                }
            }
            else
            {
                printf ("Wrong command\n");
            }
    }
    if (argc == 1)
    {
        InputCoefficients (&coeffs);
        SolveSquareEquation (coeffs, &solutions);
        OutputSolutions (solutions);
    }

    return 0;
}


