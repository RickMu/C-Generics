//
// Created by on 2017/4/6.
//

#include <stdio.h>
#include <stdlib.h>




typedef struct node{
    int priority;
}node_t;
typedef struct nodeS{
    int priority;
}node_s;


#define TYPE node_t
#define NODE_TYPE TYPE
#define COMPARATOR n1->priority>n2->priority
#include "heap.h"

#define TYPE node_s
#define NODE_TYPE TYPE
#define COMPARATOR n1->priority>n2->priority
#include "heap.h"


int main(){
    heap_node_t* h = makeHeap_node_t();

    for(int i =0;i<10; i++){
        node_t* n = (node_t*) malloc (sizeof(node_t));
        n->priority=i;
        insert_node_t(h,n);
    }
    int length = h->insertPos;
    for(int i = 0;i<length;i++){
        node_t* m= extractTop_node_t(h);
        printf("%d, ", m->priority);
    }



    return 0;
}
