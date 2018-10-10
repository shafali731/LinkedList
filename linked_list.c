#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct node {
  int i;
  struct node *next;
};

void print_list(struct node *a){
  printf("integer: %d \n point: %p \n", a->i, a->next);
}

struct node * insert_front(struct node *b, int it){
  struct node *new_front = malloc(sizeof(struct node));
  new_front->i = it;
  new_front->next = b;
  return new_front;
}
struct node * free_list(struct node *n){
  while(n){
  struct node *p = n->next;
  free(n);
  n = p;
}
return n;
}
int main(){
   struct node *test = malloc(sizeof(struct node));
   struct node *a = malloc(sizeof(struct node));
   test->i = 5;
   test->next = a;
   printf("Printing list\n");
   print_list(test);
   struct node *newer = malloc(sizeof(struct node));
   printf("inserted 10 in front of list\n");
   printf("newer: %p\n", insert_front(newer, 10));
   printf("free list\n");
   printf("free_list(): %p\n", free_list(newer));
  return 0;
}
