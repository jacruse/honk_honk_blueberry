#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headers.h"

void print_lib(struct song_node * music_lib[27]) {
  int i;
  for (i = 0; i < 26; i += 1) {
    //printf("music_lib[%d]: %d\n", i, music_lib[i]);
    if (music_lib[i]) {
      printf("%c list: \n", i+97);
      print_list(music_lib[i]);
    }
  }
}

struct song_node ** add_song_lib(struct song_node * music_lib[27], char artis[256], char nam[256]) {
  if (!music_lib[(*artis-97)]) {
    //printf("index added at: %d \nadded that to the front\n", *artis-97);
    music_lib[(*artis-97)] = insert_front( music_lib[(*artis)-97], artis, nam);
  }
  
  else {
    //printf("index added at: %d \nadded that somewhere else\n", *artis-97);
    music_lib[(*artis-97)] = insert_rec( music_lib[(*artis)-97], artis, nam);
  }
  return music_lib;
}

struct song_node * find_song_lib(struct song_node * music_lib[27], char artis[256], char nam[256]) {
  if (!music_lib[(*artis-97)]) {
    printf("song not found\n");
    return 0;
  }
  
  else {
    return find_song(music_lib[(*artis-97)], artis, nam);
  }
}

struct song_node * find_artist_lib(struct song_node * music_lib[27], char artis[256]) {
  if (!music_lib[(*artis-97)]) {
    printf("artist not found\n");
    return 0;
  }
  
  else {
    return find_artist(music_lib[(*artis-97)], artis);
  }
}

void print_artist_lib(struct song_node * music_lib[27], char artis[256]) {
  print_list(find_artist_lib(music_lib, artis));
}

void print_lib_letter(struct song_node * music_lib[27], char c) {
  printf("%c list: \n", c);
  print_list(music_lib[c-97]);
}

struct song_node * rand_song_lib(struct song_node * music_lib[27]) {
  struct song_node * song = 0;
  while (!song) {
    song = music_lib[rand() % 26];
  }
  return rand_node(song);
}

void shuffle(struct song_node * music_lib[27]) {
  printf("shuffle\n");
  print_song(rand_song_lib(music_lib));
  print_song(rand_song_lib(music_lib));
  print_song(rand_song_lib(music_lib));
}

struct song_node ** remove_song_lib(struct song_node * music_lib[27], char artis[256], char nam[256]) {
  if (music_lib[(*artis-97)]) {
    music_lib[(*artis-97)] = remove_node( music_lib[(*artis)-97], artis, nam);
  }
  else {
    printf("song not found\n");
  }
  return music_lib;
}

struct song_node ** free_lib(struct song_node * music_lib[27]) {
  int i;
  for (i = 0; i < 26; i += 1) {
    music_lib[i] = free_list(music_lib[i]);
  }
  free(music_lib);
  return 0;
}

/*
int main() {
  srand(time(NULL));
  rand();  

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

  struct song_node * song;
  
  song = find_song_lib(music_lib, "anderson paak", "the city");
  print_list(song);
  printf("\n");

  song = find_song_lib(music_lib, "anderson paak", "lite weight");
  print_list(song);
  printf("\n");

  song = find_song_lib(music_lib, "anderson paak", "your prime");
  print_list(song);
  printf("\n");

  song = find_song_lib(music_lib, "thundercat", "them changes");
  print_list(song);
  printf("\n");

  song = find_song_lib(music_lib, "zeds dead", "too young");
  print_list(song);
  printf("\n");

  song = find_song_lib(music_lib, "kendrick lamar", "untitled08");
  print_list(song);
  printf("\n");

  printf("--------------end find_song_lib testing-------------------------\n");

  printf("--------------start find_artist_lib testing-------------------------\n");

  struct song_node * artist;
  
  artist = find_artist_lib(music_lib, "anderson paak");
  print_list(artist);
  printf("\n");

  artist = find_artist_lib(music_lib, "anderson paak");
  print_list(artist);
  printf("\n");

  artist = find_artist_lib(music_lib, "anderson paak");
  print_list(artist);
  printf("\n");

  artist = find_artist_lib(music_lib, "thundercat");
  print_list(artist);
  printf("\n");

  artist = find_artist_lib(music_lib, "zeds dead");
  print_list(artist);
  printf("\n");

  artist = find_artist_lib(music_lib, "kendrick lamar");
  print_list(artist);
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
*/
