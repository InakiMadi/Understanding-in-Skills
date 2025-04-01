#ifndef DINAMICARRAY_H
#define DINAMICARRAY_H

typedef struct{
    int* list;
    int length;
} ArrayOfInt;

ArrayOfInt createArrayOfInt();

void displayArray(const ArrayOfInt* array);

void addElementToArray(ArrayOfInt* array, int element);

#endif