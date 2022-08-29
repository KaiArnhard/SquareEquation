#include "quadratic.h"

void ClearOfBuffer(int nextchar)
{
    while ((nextchar = getchar()) != '\n' &&  nextchar != EOF)
        {}
}
