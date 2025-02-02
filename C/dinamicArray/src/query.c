#include <stdio.h>
#include <stdlib.h>
#include "../include/query.h"

void displayQuery(const struct Query* query){
    printf("Type of query: %d\n", query->type_of_query);
    printf("Request:\n");
    for(int i = 0; i < 2; i++){
        printf("%d, ", query->request[i]);
    }
    printf("\n");
}

void addRequest(struct Query* query){
    scanf("%d",&query->type_of_query);
    if(query->type_of_query == 1 || query->type_of_query == 2){
        query->request = (int*)malloc(2 * sizeof(int));
        if(query->request == NULL){
            printf("Adding queries failed due to memory allocation.\n");
            exit(1);
        }
        scanf("%d",&query->request[0]);
        scanf("%d",&query->request[1]);
    }
    else if(query->type_of_query == 3){
        query->request = (int*)malloc(1 * sizeof(int));
        if(query->request == NULL){
            printf("Adding queries failed due to memory allocation.\n");
            exit(1);
        }
        scanf("%d",&query->request[0]);
    }
    else{
        printf("Error. Parameter not between 1, 2 or 3.\n");
        exit(1);
    }
}