#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <strings.h>
//#include "linky.h"

  typedef struct node {
    char * artist;
    char * songname;
    struct node * next;
  } node_t;
//print list
   void print_list(node_t* head){
  node_t * temp = head;
  int i = 0;
  while(temp!=NULL){
    printf("Element #%d : %s : %s\n" ,i , temp->artist , temp-> songname);
    temp =temp->next;
    i++;
  }
}

//count elements
int return_size(node_t * node){
  int i = 0;
  while(node->next != NULL){
    node = node->next;
    i++;
  }
  return i+1 ;
}
//insert at the front
  node_t * insert_front(node_t *head, char* art , char * song){
    if(head == NULL){
      head->artist = art;
      head->songname = song;
      head->next= NULL;
      return head;
    }
    else{
    node_t * temp = malloc(sizeof(node_t));
    temp->artist = art;
    temp->songname = song;
    temp->next = head;
    return temp;
  }
  }
node_t * insert_last(node_t * node, char * art , char * song){
    node_t * temp = malloc(sizeof(node_t));
    temp->artist = art;
    temp->songname = song;
    temp->next= NULL;
    node_t *temp2 = node;
  while(temp2->next != NULL){
      temp2 = temp2->next;
    }
    temp2->next = temp;
  return node;
}

//insert after indth element
node_t * insert_after(node_t* node , char * art, char* song, int ind){
if(ind == 0 ){
  node = insert_front(node ,art, song );
}
if(ind < return_size(node)){
  node_t * current = node;
  int i = 0;
  while(i < ind-1 ){
    current = current->next;
    i++;
  }
  node_t * right = current->next;
  right = insert_front(right, art, song);
  current->next = right;
}
else{
  node = insert_last(node, art, song);
}
return node;
}
// returns the address of the first appearence of an artist
node_t * find_artist(node_t * node , char * art){
while(node->next != NULL){
  if(*(node->artist) == *(art)){
    return node;
  }
  node = node->next;
}
  }

  //find element by songname
  node_t * find_song(node_t* node, char * song){
    while(node->next!= NULL){
      if(*(node->songname) == * (song)){
        return node;
      }
      node = node->next;
    }
  }

  //find element by song & artist'
  node_t * find(node_t * node , char * art , char * song){
    while(node->next != NULL){
      if(*(node->artist) == *(art) && *(node->artist) == *(art)){
        return node;
      }
      node = node->next;
  }
  if(node->next = NULL){
    return NULL;
  }
}

//return a random element from the list
void return_rand(node_t* head){
srand(time(NULL));
int r = rand();
printf("%d \n" , r);
}

//delete a node_t
node_t * delete(node_t * list, int ind){
  int i = 0;
  node_t * temp = list;
  node_t * current;
  node_t * right;
  while(i < ind-1){
      temp = temp->next;
      i++;
  }
  current = temp->next;
  right = current->next;
  free(current);
  temp->next = right;
  return list;

}


//free the list
node_t * free_list(node_t * head){
  node_t * current = head;
  node_t * temp;
  while(current != NULL){
    temp = current->next;
    free(current);
    current = temp;
  }
  return current;

}

//generate a random number within the range to get a element
node_t * get_random(node_t * list){
  int r = rand() % return_size(list);
  while(r > 0){
    list = list-> next;
    r--;
  }
return list;
}
