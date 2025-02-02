#include <stdio.h>
#include <assert.h>
#include "../src/dinamicArray.c"

void test_sum(){
    assert(sum(2,3) == 5);
    assert(sum(-1,1) == 0);
    assert(sum(0,0) == 0);
    printf("All sum tests succeeded.\n");
}

int main(){
    test_sum();
    return 0;
}