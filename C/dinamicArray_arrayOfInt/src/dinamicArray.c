#include "../include/dinamicArray.h"
#include <stdio.h>
#include <stdlib.h>

void initializeArrayOfInt(struct ArrayOfInt* array)
{
    array->list = NULL;
    array->length = 0;
    //for (int i = 0; i < array_length; i++)
    //{
    //    array_of_arrays[i] = NULL;
    //}
}

void displayArray(const struct ArrayOfInt* array)
{
    if(array->length <= 0){
        printf("Empty array.\n");
    }
    else{
        printf("List: [");
        if(array->length <= 0){
            printf("%d].\n", array->list[0]);
        }
        else{
            printf("%d", array->list[0]);
            for(int i = 1; i < array->length; i++){
                printf(", %d", array->list[i]);
            }
            printf("].\n");
        }
        
    printf("Length: %d.\n", array->length);
    }
}

void addElementToArray(struct ArrayOfInt* array, int element)
{
    (*array).list = realloc((*array).list,((*array).length+1)*sizeof(int));
    if((*array).list == NULL){
        fprintf(stderr, "Memory reallocation failed.\n");
        exit(1);
    }
    (*array).list[(*array).length] = element;
    (*array).length++;
}