#ifndef IO_H

#define IO_H


enum StatusOfInput
{
    ERROR = 1,
    ALLRIGHT = 0
};

int InputCoefficients (Coefficients *coeffs);

void OutputSolutions (Solutions solutions);

#endif


