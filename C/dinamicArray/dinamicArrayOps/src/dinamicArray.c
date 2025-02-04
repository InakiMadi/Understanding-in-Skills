#include "../include/dinamicArray.h"
#include <stdio.h>
#include <stdlib.h>

void initializeArrayOfArrays(int **array_of_arrays, int array_length)
{
    for (int i = 0; i < array_length; i++)
    {
        array_of_arrays[i] = NULL;
    }
}