#ifndef DINAMICARRAY_H
#define DINAMICARRAY_H

struct ArrayOfInt{
    int* list;
    int length;
};

void initializeArrayOfArrays(int **array_of_arrays, int array_length);

void initializeArrayOfInt(struct ArrayOfInt* array);

void displayArray(const struct ArrayOfInt* array);

void addElementToArray(struct ArrayOfInt* array, int element);

#endif