#ifndef QUERYCOLLECTION_H
#define QUERYCOLLECTION_H
#include "query.h"

struct QueryCollection {
    int number_of_queries;
    struct Query* queries;
};

void initializeQueryCollection(struct QueryCollection* query_col);

void addQuery(struct QueryCollection* query_col, const struct Query* query);

void displayQueryCollection(const struct QueryCollection* query_collection);

#endif