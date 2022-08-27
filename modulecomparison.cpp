#include <stdio.h>
#include <math.h>
#include "modulecomparison.h"
#include "quadratic.h"

int modulecomparison(double a, double b)
{
   if (fabs (a - b) <= EPSILON)
   return TRUE;
   else
   return FALSE;
}

