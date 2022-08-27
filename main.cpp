#include "quadratic.h"
#include "io.h"
#include "unittest.h"


int main(int argc, char *argv[])
{

    Coefficients coeffs = {NAN, NAN, NAN};
    Solutions solutions = {0, 0, 0};

    int id = 1;

    for ( ; id < argc; id++)
    {
        if (*argv[id] == '-')
            {
                switch (argv[id][1])
                {
                    case 'h' :
                    {
                        printf( "-h - show information about launch\n -t - launch test mode\n");
                        break;
                    }
                    case 't' :
                    {
                        UnitTest();
                        break;
                    }
                    default:
                    {
                        printf ("Wrong command: %c, type -h for help\n", argv[id][1]);
                        break;
                    }
                }
            }
            else
            {
                printf ("Wrong argument: %c, type -h for help\n", *argv[id]);
            }
    }
    if (argc == 1)
        {
            if (InputCoefficients (&coeffs))
            {
                return 0;
            }
            else
            {
                SolveSquareEquation (coeffs, &solutions);
                OutputSolutions (solutions);
            }
        }

    return 0;
}


