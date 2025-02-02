#ifndef QUERY_H
#define QUERY_H

struct Query{
    int type_of_query;
    int* request;
};

void displayQuery(const struct Query* query);


void addRequest(struct Query* query);

#endif