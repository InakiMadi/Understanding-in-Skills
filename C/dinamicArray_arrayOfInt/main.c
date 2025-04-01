#include "include/dinamicArray.h"

int main(){
    ArrayOfInt example = createArrayOfInt();

    addElementToArray(&example,10);
    addElementToArray(&example,11);
    addElementToArray(&example,12);

    displayArray(&example);
}