#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"


void print_list(struct song_node * x) {

  printf("%s: %s\n", x->artist, x->name);

  if ( x->next ) {
    print_list(x->next);
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
  if (n->next) {
    free_list(n->next);
  }
  free(n);
  return n;
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

struct song_node * find_node(struct song_node * head, char artis[256], char nam[256]) {
  
    


int main() {
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
  
  printf("--------------start free testing-------------------------\n");

  head = free_list(head);
  print_list(head);

  printf("--------------end free testing-------------------------\n");
}

