#include <stdio.h>
#include <stdlib.h>
#include "dinamicArray.h"

void initializeQueryCollection(struct QueryCollection* query_col){
    query_col->queries = NULL;
    query_col->number_of_queries = 0;
}

void displayQuery(const struct Query* query){
    printf("Type of query: %d\n", query->type_of_query);
    printf("Request:\n");
    for(int i = 0; i < 2; i++){
        printf("%d, ", query->request[i]);
    }
    printf("\n");
}

void displayQueryCollection(const struct QueryCollection* query_collection){
    printf("Amount of queries: %d\n", query_collection->number_of_queries);
    printf("Queries:\n");
    for(int i = 0; i < query_collection->number_of_queries; i++){
        displayQuery(&query_collection->queries[i]);
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

void addQuery(struct QueryCollection* query_col, const struct Query query){
    query_col->queries = (struct Query*)realloc(query_col->queries, (query_col->number_of_queries+1) * sizeof(struct Query));
    //query_col->queries = (struct Query*)malloc((query_col->number_of_queries+1) * sizeof(struct Query));
    if(query_col->queries == NULL){
        printf("Adding queries failed due to memory allocation.\n");
        exit(1);
    }
    // Add the new query
    query_col->queries[query_col->number_of_queries] = query;
    query_col->number_of_queries++;
}