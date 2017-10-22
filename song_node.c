#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headers.h"

void print_list(struct song_node * x) {
  if (x) {
    printf("%s: %s\n", x->artist, x->name);
    print_list(x->next);
  } 
}

void print_song(struct song_node * x) {
  if (x) {
    printf("%s: %s\n", x->artist, x->name);
  }
}

struct song_node * insert_front(struct song_node * n, char artis[256], char nam[256]) {
  struct song_node * front = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(front->name, nam);
  strcpy(front->artist, artis);
  front->next = n;
  return front;
}

/*
struct node * free_list(struct node * n){
  struct node *old;
  while(n){
    old = n;
    n= n->next;
    free(old);
  }
  return 0;
}
*/

struct song_node * free_list(struct song_node * n) {
  if (n) {
    free(n);
    free_list(n->next);
  }
  return 0;
}

/*
struct node * insert_while(struct node * front, int i) {
  if (i < front->val) {
    insert_front(front, i);
  }
  
  struct node * pointer = front;
  
  while (i > pointer->next->val) {
    pointer = pointer->next;
  }

  struct node * new_node = (struct node *) malloc(sizeof(struct node));
  new_node->val = i;
  new_node->next = pointer->next;
  pointer->next = new_node;
  return front;
2}
nahhh recursion ftw
*/

struct song_node * insert_rec(struct song_node * front, char artis[256], char nam[256]) {
  if ( strcmp(artis, front->artist) < 0 || (strcmp(artis, front->artist) == 0 && (strcmp(nam, front->name) < 0) ) ) {
    struct song_node * new_song_node = (struct song_node *) malloc(sizeof(struct song_node));
    strcpy(new_song_node->artist, artis);
    strcpy(new_song_node->name, nam);    
    new_song_node->next = front;
    return new_song_node;
  }

  else if (!front->next) {
    struct song_node * new_song_node = (struct song_node *) malloc(sizeof(struct song_node));
    strcpy(new_song_node->artist, artis);
    strcpy(new_song_node->name, nam);   
    new_song_node->next = 0;
    front->next = new_song_node;
    return front;
  }  

  else {
    front->next = insert_rec(front->next, artis, nam);
  }
  return front;
}

struct song_node * find_song(struct song_node * head, char artis[256], char nam[256]) {
  if (strcmp(head->artist, artis) == 0 && strcmp(head->name, nam) == 0) {
    printf("found song!\n");
    return head;
  }

  else if (!head->next) {
    printf("song not found\n");
    return 0;
  }

  else {
    return find_song(head->next, artis, nam);
  }
}

struct song_node * find_artist(struct song_node * head, char artis[256]) {
  if (strcmp(head->artist, artis) == 0) {
    printf("found artist!\n");
    return head;
  }

  else if (!head->next) {
    printf("artist not found\n");
    return 0;
  }
  
  else {
    return find_artist(head->next, artis);
  }
}

int get_size(struct song_node * head) {
  if (!head->next) {
    return 1;
  }
  else {
    return 1 + get_size(head->next);
  }
}

struct song_node * get_rand_node(struct song_node * head, int i) {
  if (i) {
    return get_rand_node(head->next, i-1);
  }
  else {
    return head;
  }
}

struct song_node * rand_node(struct song_node * head) {
  //printf("%d\n", rand()%get_size(head));
  return get_rand_node(head, rand()%get_size(head));
}

struct song_node * remove_node(struct song_node * head, char artis[256], char nam[256]) {
  if (strcmp(head->artist, artis) == 0 && strcmp(head->name, nam) == 0) {
    printf("found song!\n");
    struct song_node * new_node = head->next;
    free(head);
    return new_node;
  }

  else if (!head->next) {
    printf("song not found\n");
    return head;
  }

  else {
    head->next = remove_node(head->next, artis, nam);
  }
  return head;
}
  


/*
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
}


*/
