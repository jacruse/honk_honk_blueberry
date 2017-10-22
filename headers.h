struct node { int val; struct node * next; };
struct song_node { char name[256]; char artist[256]; struct song_node * next; };

void print_list(struct song_node * x);

void print_song(struct song_node * x);

//song_node fxns
  
struct song_node * insert_front(struct song_node * n, char artis[256], char nam[256]);

struct song_node * free_list(struct song_node * n);

struct song_node * insert_rec(struct song_node * front, char artis[256], char nam[256]);

struct song_node * find_song(struct song_node * head, char artis[256], char nam[256]);

struct song_node * find_artist(struct song_node * head, char artis[256]);

int get_size(struct song_node * head);

struct song_node * get_rand_node(struct song_node * head, int i);

struct song_node * rand_node(struct song_node * head);

struct song_node * remove_node(struct song_node * head, char artis[256], char nam[256]);


//music_lib fxns
  
void print_lib(struct song_node * music_lib[27]);

struct song_node ** add_song_lib(struct song_node * music_lib[27], char artis[256], char nam[256]);

struct song_node * find_song_lib(struct song_node * music_lib[27], char artis[256], char nam[256]);

struct song_node * find_artist_lib(struct song_node * music_lib[27], char artis[256]);

void print_artist_lib(struct song_node * music_lib[27], char artis[256]);

void print_lib_letter(struct song_node * music_lib[27], char c);

struct song_node * rand_song_lib(struct song_node * music_lib[27]);

void shuffle(struct song_node * music_lib[27]);

struct song_node ** remove_song_lib(struct song_node * music_lib[27], char artis[256], char nam[256]);

struct song_node ** free_lib(struct song_node * music_lib[27]);

  
  
  
  
  
  
  

  
  

  
  


 
