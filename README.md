Coding Generics in C.

The files contain an array implementation of a heap which takes in Generic Node type

File Structure:
main.c includes:
comparator.h   heap.h  heap.c
                             

            
For anyone that's familiar with interfaces in Java or C++, can think of the comparator.h as the concrete implementation of a interface.
while heap.h is a generic class. If there is another node.h for our node type then it would be the class we want our generic heap to use.    
Here for clarity I put my defined node type and comparator in comparator.h
However best practice would be to split them.


The reason that main includes all three files is to demonstrate that, in order to use heap in many different context(different types of nodes):

Need to 
#include "comparator"
#include "heap.h"
#include "heap.c"

in this exact order, also makefile should not include anything other than comparator.h and main.c, otherwise it would raise error.




Inside heap.h and heap.c

NODE_TYPE and COMPARATOR are not defined.
They are defined in comparator.h

Heap struct

#define HEAP(NODE_TYPE )\
struct heap{\
    NODE_TYPE** tree;\
    int insertPos;\
    int size;\
}
typedef HEAP(NODE_TYPE) heap_t;

A Macro is used in this case and it's typedef to heap_t, as a type that can be referred to by functions inside heap.c

An alternative would to do this, I can't think of why one method might be perferred over another, but there might be a reason.

typedef struct heap{
    NODE_TYPE** tree;
    int insertPos;
    int size;
}heap_t;


Comparator
The below code is in heap.c, COMPARATOR is inside if.
This is so you can define a macro: 
e.g
#COMPARATOR n1->priority < n2->priority

int compareNode(NODE_TYPE* n1, NODE_TYPE* n2){
    if(COMPARATOR) {
        return 1;
    }
    return 0;
}

