#include<stdio.h>
#include<stdlib.h>

#define NIL 0
#define BOOL int

typedef unsigned int uint;  // convenient name for unsigned int

// The following defines the TYPES OF FUNCTIONS
typedef int (*fun)(int);  /* fun is the type of functions int->int */
typedef int (*binop)(int,int); /* binary operation on ints */
typedef BOOL (*predicate)(int); /* predicates on integers */
typedef void (*action)(); /* simple action, no return value */
typedef void (*actionon)(int); /* act on an integer */

/* refer to programs written in class for more code and examples */

// Basic linked-list encapsulation
typedef struct cell* list;  // linked list pointer
struct cell
{
  int item;
  list next;
};

list cons(int x, list n) // creates struct on heap
{
  list newcell = (list)malloc(sizeof(struct cell));
  newcell->item = x;
  (*newcell).next = n;
  return newcell;
}
// list m = cons(2,cons(3,cons(5,cons(7,NIL))));
int car(list m) { return m->item; }
list cdr(list m) { return m->next; }
int cadr(list m) { return m->next->item; } // second item
list cddr(list m) { return m->next->next; }




int main (int argc, char * argv[]){





  return 1;
}
