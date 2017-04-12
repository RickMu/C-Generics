Coding Generics in C.
<br/><br/>
There was a tiny bug that didn't show in IDE, but did on vm.Fixed
<br/>
There are two ways to implement "generics" in c,  one is to use Macros and the other is to use void.
<br/><br/>
heap.h includes generic functions of heap, utilizing Macros to achieve the affect.
<br/>
heap.c doesn't contain anything useful yet, all functions written in heap.h
<br/><br/>
User can define his own type of nodes and how he wish to sort the node.
<br/>
To do this:
<br/>
#define NODE_TYPE
<br/>
#define TYPE NODE_TYPE
<br/>
#define COMPARATOR  ....
<br/>
#include "heap.h"
<br/><br/>
#define NODE_TYPE
<br/>
#define TYPE NODE_TYPE 
<br/>
#define COMPARATOR  ...
<br/>
#include "heap.h"
<br/>
....
<br/><br/>

There is no issue including heap.h twice or more. 
<br/>
So if there are two or more classes that need to use heap with different node type,
<br/>
there will be no issue.
<br/><br/>
The code can be previewed, using gcc -E main.c. 
<br/>
Preprocessor

                        
