# Coding Generics in C.
<br/><br/>
There was a tiny bug that didn't show in IDE, but did on vm.Fixed
<br/>
There are two ways to implement "generics" in c,  one is to use Macros and the other is to use void.
<br/><br/>
heap.h includes generic functions of heap, utilizing Macros to achieve the affect.
<br/><br/>
User can define his own type of nodes and how he wish to sort the node.
<br/>
# Use heap.h:
<br/>
#define NODE_TYPE e.g. node_t
<br/>
#define TYPE NODE_TYPE
<br/>
#define COMPARATOR  ....
<br/>
#include "heap.h"
<br/><br/>
#define NODE_TYPE e.g. node_s
<br/>
#define TYPE NODE_TYPE 
<br/>
#define COMPARATOR  ...
<br/>
#include "heap.h"
<br/>
To demonstrate that you can define two types of heap.
<br/> 
There is probably no need for both NODE_TYPE and TYPE to exist, this will be changed later
<br/>
<br/><br/>

# Linked List <br/>
A generic linked list is added this hasn't been tested yet, and is just a prototype <br/>

# To Use: <br/>
#define LINKED_NODE e.g linked_node_s <br/>

# To Preview Your Code Use Preprocessor:
The code can be previewed, using gcc -E main.c. 
<br/>

                        
