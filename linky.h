#include <stdio.h>
#include <stdlib.h>
int main(){}
void print_list(node_t * );
int return_size(node_t * );
node_t * insert_front(node_t *, char*  , char * );
node_t * insert_last(node_t * , char *  , char * );
node_t * insert_after(node_t*  , char * , char* , int );
node_t * find_artist(node_t *  , char * );
node_t * find_song(node_t* , char * );
node_t * find(node_t *  , char *  , char * );
void return_rand(node_t* );
node_t * delete(node_t * , int );
node_t * free_list(node_t * );
node_t * get_random(node_t * );
