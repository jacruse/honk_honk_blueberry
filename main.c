#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headers.h"

int main() {
  srand(time(NULL));
  rand();  

  struct song_node *head;

  head = insert_front( insert_front( insert_front( 0, "thundercat", "them changes" ), "kendrick lamar", "u" ), "jack johnson", "better together" );

  printf("--------------start print_list testing-------------------------\n");

  print_list(head);
  printf("\n");

  printf("--------------end print_list testing-------------------------\n");

  printf("--------------start insert_front testing-------------------------\n");

  head = insert_front(head, "anderson paak", "lite weight");
  print_list(head);

  printf("--------------end insert_front testing-------------------------\n");

  printf("--------------start insert testing-------------------------\n");

  head = insert_rec(head, "anderson paak", "the city");
  print_list(head);
  printf("\n");
  
  head = insert_rec(head, "brockhampton", "junky");
  print_list(head);
  printf("\n");
  
  head = insert_rec(head, "anderson paak", "am i wrong");
  print_list(head);
  printf("\n");
  
  printf("--------------end insert testing-------------------------\n");
  
  printf("--------------start find_song testing-------------------------\n");

  struct song_node * song = find_song(head, "anderson paak", "lite weight");
  print_list(song);
  printf("\n");
    
  song = find_song(head, "anderson paak", "your prime");
  //print_list(song);
  printf("\n");

  song = find_song(head, "thundercat", "them changes");
  print_list(song);
  printf("\n");
  
  printf("--------------end find_song testing-------------------------\n");

  printf("--------------start find_artist testing-------------------------\n");

  struct song_node * artist = find_artist(head, "anderson paak");
  print_list(artist);
  printf("\n");
    
  artist = find_artist(head, "thundercat");
  print_list(artist);
  printf("\n");
  
  printf("--------------end find_artist testing-------------------------\n");


  printf("--------------start rand_node testing-------------------------\n");

  print_list(head);
  int size = get_size(head);
  printf("%d\n", size);
  
  song = rand_node(head);
  print_list(song);
  printf("\n");

  song = rand_node(head);
  print_list(song);
  printf("\n");
  
  printf("--------------end rand_node testing-------------------------\n");
  
  printf("--------------start remove testing-------------------------\n");
  printf("og list\n");
  print_list(head);
  printf("\n");

  head = remove_node(head, "anderson paak", "lite weight");
  print_list(head);
  printf("\n");
  
  head = remove_node(head, "brockhampton", "junky");
  print_list(head);
  printf("\n");
  
  head = remove_node(head, "anderson paak", "am i wrong");
  print_list(head);
  printf("\n");

  head = remove_node(head, "thundercat", "them changes");
  print_list(head);
  printf("\n");
  
  printf("--------------end remove testing-------------------------\n");
  
  printf("--------------start free testing-------------------------\n");

  head = free_list(head);
  //print_list(head);
  //works a-okay
  
  printf("--------------end free testing-------------------------\n");

  struct song_node ** music_lib = (struct song_node **) calloc(27,sizeof(struct song_node *));
  
  //struct song_node *head;
  //head = insert_front( 0, "thundercat", "them changes" );

  printf("--------------start add_song_lib testing-------------------------\n");

  //printf("sizeof(struct song_node *): %lu\n", sizeof(struct song_node *));
  add_song_lib(music_lib, "anderson paak", "the city");
  print_lib(music_lib);
  printf("\n");

  add_song_lib(music_lib, "anderson paak", "lite weight");
  print_lib(music_lib);
  printf("\n");

  add_song_lib(music_lib, "anderson paak", "your prime");
  print_lib(music_lib);
  printf("\n");

  add_song_lib(music_lib, "thundercat", "them changes");
  print_lib(music_lib);
  printf("\n");

  add_song_lib(music_lib, "zeds dead", "too young");
  print_lib(music_lib);
  printf("\n");

  printf("--------------end add_song_lib testing-------------------------\n");
  
  printf("--------------start find_song_lib testing-------------------------\n");

  struct song_node * sung;
  
  sung = find_song_lib(music_lib, "anderson paak", "the city");
  print_list(sung);
  printf("\n");

  sung = find_song_lib(music_lib, "anderson paak", "lite weight");
  print_list(sung);
  printf("\n");

  sung = find_song_lib(music_lib, "anderson paak", "your prime");
  print_list(sung);
  printf("\n");

  sung = find_song_lib(music_lib, "thundercat", "them changes");
  print_list(sung);
  printf("\n");

  sung = find_song_lib(music_lib, "zeds dead", "too young");
  print_list(sung);
  printf("\n");

  sung = find_song_lib(music_lib, "kendrick lamar", "untitled08");
  print_list(sung);
  printf("\n");

  printf("--------------end find_song_lib testing-------------------------\n");

  printf("--------------start find_artist_lib testing-------------------------\n");

  struct song_node * artest;
  
  artest = find_artist_lib(music_lib, "anderson paak");
  print_list(artest);
  printf("\n");

  artest = find_artist_lib(music_lib, "anderson paak");
  print_list(artest);
  printf("\n");

  artest = find_artist_lib(music_lib, "anderson paak");
  print_list(artest);
  printf("\n");

  artest = find_artist_lib(music_lib, "thundercat");
  print_list(artest);
  printf("\n");

  artest = find_artist_lib(music_lib, "zeds dead");
  print_list(artest);
  printf("\n");

  artest = find_artist_lib(music_lib, "kendrick lamar");
  print_list(artest);
  printf("\n");

  printf("--------------end find_artist_lib testing-------------------------\n");

  printf("--------------start print_artist_lib testing-------------------------\n");

  print_artist_lib(music_lib, "anderson paak");
  printf("\n");

  print_artist_lib(music_lib, "anderson paak");
  printf("\n");

  print_artist_lib(music_lib, "anderson paak");
  printf("\n");

  print_artist_lib(music_lib, "thundercat");
  printf("\n");

  print_artist_lib(music_lib, "zeds dead");
  printf("\n");

  print_artist_lib(music_lib, "kendrick lamar");
  printf("\n");

  printf("--------------end print_artist_lib testing-------------------------\n");

  printf("--------------start print_lib_letter testing-------------------------\n");

  print_lib_letter(music_lib, 'a');
  printf("\n");

  print_lib_letter(music_lib, 'g');
  printf("\n");  

  print_lib_letter(music_lib, 'z');
  printf("\n");  
  
  printf("--------------end print_lib_letter testing-------------------------\n");

  printf("--------------start shuffle testing-------------------------\n");

  shuffle(music_lib);
  printf("\n");

  shuffle(music_lib);
  printf("\n");  

  shuffle(music_lib);
  printf("\n");  
  
  printf("--------------end shuffle testing-------------------------\n");

  printf("--------------start remove_song_lib testing-------------------------\n");

  //printf("sizeof(struct song_node *): %lu\n", sizeof(struct song_node *));
  remove_song_lib(music_lib, "anderson paak", "the city");
  print_lib(music_lib);
  printf("\n");

  remove_song_lib(music_lib, "anderson paak", "the city");
  print_lib(music_lib);
  printf("\n");
  printf("\n");

  remove_song_lib(music_lib, "anderson paak", "lite weight");
  print_lib(music_lib);
  printf("\n");

  remove_song_lib(music_lib, "anderson paak", "your prime");
  print_lib(music_lib);
  printf("\n");

  remove_song_lib(music_lib, "thundercat", "them changes");
  print_lib(music_lib);
  printf("\n");

  remove_song_lib(music_lib, "zeds dead", "too young");
  print_lib(music_lib);
  printf("\n");

  remove_song_lib(music_lib, "zeds dead", "too young");
  print_lib(music_lib);
  printf("\n");

  printf("--------------end remove_song_lib testing-------------------------\n");

  printf("--------------start add_song_lib testing-------------------------\n");

  //printf("sizeof(struct song_node *): %lu\n", sizeof(struct song_node *));
  add_song_lib(music_lib, "anderson paak", "the city");
  print_lib(music_lib);
  printf("\n");

  add_song_lib(music_lib, "anderson paak", "lite weight");
  print_lib(music_lib);
  printf("\n");

  add_song_lib(music_lib, "anderson paak", "your prime");
  print_lib(music_lib);
  printf("\n");

  add_song_lib(music_lib, "thundercat", "them changes");
  print_lib(music_lib);
  printf("\n");

  add_song_lib(music_lib, "zeds dead", "too young");
  print_lib(music_lib);
  printf("\n");

  printf("--------------end add_song_lib testing-------------------------\n");
  
  printf("--------------start free_lib testing-------------------------\n");

  music_lib = free_lib(music_lib);
  //print_lib(music_lib);

  printf("--------------end free_lib testing-------------------------\n");

}
