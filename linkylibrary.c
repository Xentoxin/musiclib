#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkylibrary.h"
#include "linky.h"

node_t * add_song(node_t * library[] , char * song, char * art){
  library[art[0]-97] = insert_order(library[art[0]-97] , song, art);
  return library[art[0]-97];
}

node_t * searchlibrarybyname(node_t * library[] , char * song, char * art){
  char c=  97;
  node_t * n = 0;
  while(c<123){
    if(n = searchlistbyart([library[c-97] , song, art)){
      return n;
    }
    c++;
  }
  return n;
}

node_t * searchlibrarybyart(node_t * library[] , char * art ){
  return searchlistbyart(library[art[0]-97] , art);
}

void printlibraryletter(node_t * library[] , char letter){
  if(!library[letter-97]){
    return;
  }
  printf("%c list \n" , letter);
  print_list(library[letter-97]);
}

void printlibraryart(node_t * library[] , char * art){
  print_list_art(library[0]-97 , art);
}
void print_lib_random(node_t * library[], int numSongs){
  int libPos = 0;
  while(numSongs--){ //performs operation numSongs times
    while(!library[libPos++ % 26]){} //runs until a non-empty list is found and index is kept under 26 by wrapping around
    print_node(search_list_random(library[(libPos-1)%26])); //libPos-1 used to undo the libPos++ after correct pos was found
  }
}

//delete_lib_song
//deletes song by art by going to list with correct letter of song
//does nothing if song isn't present
void delete_lib_song(node_t * library[], char * song, char * art){
    library[art[0]-97] = delete_list_song(library[art[0]-97], song, art);
}

//free_lib
//frees all library contents
void free_lib(node_t* library[]){
  int libPos = 0;
  while(libPos <26){
    free_list(library[libPos]);
    libPos++;
  }
}
