#include "include/dinamicArray.h"

int main(){
    struct ArrayOfInt example;

    initializeArrayOfInt(&example);

    addElementToArray(&example,10);
    addElementToArray(&example,11);
    addElementToArray(&example,12);

    displayArray(&example);
}