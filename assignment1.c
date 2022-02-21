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


//problem 2

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


list reverse(list m)
{
  // need a stack, initially null
  list irev(list m, list stack)
  {
    if (m==NIL) return stack; 
    else return irev(cdr(m), cons(car(m),stack));
  }
  return irev(m,NIL);
}

list map(fun f, list m)
{
  list imap(list m, list stack)
  {
    if (m==NIL) return stack;
    else return imap(cdr(m), cons(f(car(m)),stack));
  }
  return reverse(imap(m,NIL));
} 


//problem 1 - doubleup 
list doubleup(list m)
{
  list inner(list m, list stack)
  {
    if(m==NULL) return stack;
    else return cons(car(m),cons(car(m),inner(cdr(m),stack)));
  }
  return inner(m,NIL);
}

void output(int x)
{
  printf("%d",x);
}

//problem 2 

list foreach (list m, actionon f)
{
  if(m==NIL)
  {
    printf("\n");
    return NIL;
  }
  else
  {
    f(car(m));
    return foreach(cdr(m),f);
  }
}

int main ()
{

  printf("entering main\n");
  list l = cons(1,cons(2,cons(3,NIL)));

  //printf("%d",car(l));
  list l1 = cons(1,cons(2,cons(3,NIL)));
  foreach(l,output);
  foreach(doubleup(l1),output);


  return 1;
}
