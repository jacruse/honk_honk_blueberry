#include <stdio.h>
#include <stdlib.h>
#include "headers.h"


void print_list(struct node * x) {

  printf("%d\n", x->val);

  if ( x->next ) {
    print_list(x->next);
  }
}


struct node * insert_front(struct node * n, int i) {
  struct node * front = (struct node *) malloc(sizeof(struct node));
  front->val = i;
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

struct node * free_list(struct node * n) {
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
}
nahhh recursion ftw
*/

struct node * insert_rec(struct node * front, int i) {
  if (i <= front->val) {
    struct node * new_node = (struct node *) malloc(sizeof(struct node));
    new_node->val = i;
    new_node->next = front;
    return new_node;
  }

  else if (!front->next) {
    struct node * new_node = (struct node *) malloc(sizeof(struct node));
    new_node->val = i;
    new_node->next = 0;
    front->next = new_node;
    return front;
  }  

  else {
    front->next = insert_rec(front->next, i);
  }
  return front;
}
    


int main() {
  struct node *head;

  head = insert_front( insert_front( insert_front( 0, 2 ), 1 ), 0 );

  printf("--------------start print_list testing-------------------------\n");

  print_list(head);
  printf("\n");

  printf("--------------end print_list testing-------------------------\n");

  printf("--------------start insert_front testing-------------------------\n");

  head = insert_front(head, 0);
  print_list(head);

  printf("--------------end insert_front testing-------------------------\n");

  printf("--------------start insert testing-------------------------\n");

  print_list(head);
  printf("\n");
  head = insert_rec(head, 2);
  print_list(head);
  printf("\n");  
  head = insert_rec(head, 5);
  print_list(head);
  printf("\n");  
  head = insert_rec(head, 3);
  print_list(head);
  printf("\n");  
  head = insert_rec(head, 7);
  print_list(head);
  printf("\n");  
  head = insert_rec(head, 4);
  print_list(head);

  printf("--------------end insert testing-------------------------\n");
  
  printf("--------------start free testing-------------------------\n");

  free_list(head);

  printf("--------------end free testing-------------------------\n");
}

