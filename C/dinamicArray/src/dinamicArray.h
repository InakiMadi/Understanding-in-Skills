#ifndef DINAMICARRAY_H
#define DINAMICARRAY_H

#include <stdio.h>
#include <stdlib.h>

struct Query{
    int type_of_query;
    int* request;
};

struct QueryCollection {
    int number_of_queries;
    struct Query* queries;
};

void initializeQueryCollection(struct QueryCollection* query_col);

void displayQuery(const struct Query* query);

void displayQueryCollection(const struct QueryCollection* query_collection);

void addRequest(struct Query* query);

void addQuery(struct QueryCollection* query_col, const struct Query query);

#endif