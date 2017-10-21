struct song_node * add_song(node_t *[], char*, char*);
struct song_node * search_lib_name(node_t *[], char*);
struct song_node * search_lib_artist(node_t *[], char*);
void print_lib_letter(node_t *[], char);
void print_lib_artist(node_t *[], char*);
void print_lib(node_t *[]);
void print_random(node_t *[], int);
void delete_lib_song(node_t *[], char*);
void free_lib(node_t *[]);
