#include <stdio.h>
#include <stdlib.h>
#include "src/dinamicArray.h"





//int main(int argc, char* argv[])
int main()
{
    struct QueryCollection query_collection;
    struct Query query;
    initializeQueryCollection(&query_collection);

    /*
    * This stores the total number of books in each shelf.
    
    int* total_number_of_books;

    *
    * This stores the total number of pages in each book of each shelf.
    * The rows represent the shelves and the columns represent the books.
    
    int** total_number_of_pages;
    */

    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    // Number of queries
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    int** total_number_of_pages = (int**)malloc(total_number_of_shelves * sizeof(int*));
    int* total_number_of_books = (int*)calloc(total_number_of_shelves,sizeof(int));

    while (total_number_of_queries > 0) {
        addRequest(&query);
        addQuery(&query_collection,query);
        total_number_of_queries--;
    }
    
    for(int i=0; i < query_collection.number_of_queries; i++){
        struct Query current_query = query_collection.queries[i];
        if (current_query.type_of_query == 1) {
            int x = current_query.request[0];
            int y = current_query.request[1];
            total_number_of_pages[x] = (int*)realloc(total_number_of_pages[x], (total_number_of_books[x]+1) * sizeof(int));
            total_number_of_pages[x][total_number_of_books[x]] = y;
            total_number_of_books[x]++;
        } else if (current_query.type_of_query == 2) {
            int x = current_query.request[0];
            int y = current_query.request[1];
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x = current_query.request[0];
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }

    if(query.request == NULL){
        free(query.request);
    }
    if(query_collection.queries == NULL){
        free(query_collection.queries);
    }
    
    return 0;
}