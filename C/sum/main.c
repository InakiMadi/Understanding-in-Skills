#include<stdio.h>
#include<stdlib.h>

// Declare the function sum.
int sum(int a, int b);

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Usage: %s <number1> <number2>.\n", argv[0]);
        return 1; // Ends with error.
    }

    // Transform the parameters as integers.
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int result = sum(a,b);
    printf("%d.\n", result);

    return 0;
}