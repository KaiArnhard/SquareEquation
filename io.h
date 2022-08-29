#ifndef IO_H

#define IO_H


enum StatusOfInput
{
    EXIT     = 1,
    ALLRIGHT = 0
};

int InputCoefficients (Coefficients *coeffs);
void ClearOfBuffer (int nextchar);

void OutputSolutions (Solutions solutions);

#endif


