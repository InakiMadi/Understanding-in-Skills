#include <stdio.h>
#include <stdlib.h>
#include "../include/queryCollection.h"

void initializeQueryCollection(struct QueryCollection* query_col){
    query_col->queries = NULL;
    query_col->number_of_queries = 0;
}

void displayQueryCollection(const struct QueryCollection* query_collection){
    printf("Amount of queries: %d\n", query_collection->number_of_queries);
    printf("Queries:\n");
    for(int i = 0; i < query_collection->number_of_queries; i++){
        displayQuery(&query_collection->queries[i]);
    }
    printf("\n");
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