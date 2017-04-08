Coding Generics in C.

There are two ways to implement "generics" in c,  one is to use Macros and the other is to use void.

heap.h includes generic functions of heap, utilizing Macros to achieve the affect.

User can define his own type of nodes and the wish to sort the node.
To do this:
#define NODE_TYPE
#define TYPE NODE_TYPE
#define COMPARATOR  ....
#include "heap.h"

#define NODE_TYPE
#define TYPE NODE_TYPE 
#define COMPARATOR  ...
#include "heap.h"
....

There is no issue including heap.h twice or more. 
So if there are two or more classes that need to use heap with different node type,
there will be no issue.

The code can be previewed, using gcc -E main.c. 
Preprocessor

                        
