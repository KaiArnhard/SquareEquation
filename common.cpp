#include "common.h"
#include "quadratic.h"

///            Comparison of two double numbers
/**
*   This function compare two double numbers
*
*   @param[IN]   double  FirstNumber   first comparing number
*   @param[IN]   double SecondNumber  second comparing number
*   @return     On success return TRUE, on failure return FALSE
*
**/


int ModuleComparison(double FirstNumber, double SecondNumber)
{
    if (fabs (FirstNumber - SecondNumber) <= EPSILON)
        return TRUE;
    else
        return FALSE;
}


///            Comparison of double number and Null
/**
*   This function compare double number with Null
*
*   @param[IN]   double  FirstNumber   first comparing number
*   @return     On success return TRUE, on failure return FALSE
*
**/

int ModuleComparisonWithNull(double Number)
{
    if (fabs (Number) <= EPSILON)
        return TRUE;
    else
        return FALSE;
}

