//
// Created by on 2017/4/6.
//

#include <stdio.h>
#include <stdlib.h>




typedef struct node{
    int priority;
}node_t;

typedef struct linkedNode{
    int priority;
    struct linkedNode* next;
}linked_node;



#define LINKED_NODE linked_node
#include "linkedList.h"

#define TYPE node_t
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


    //To test the extract and peek method as well as isEmpty method which is wrapped within peek
    for(int i = 0;i<length;i++){
        node_t* n = peek_node_t(h);
        printf("peek %d, ", n->priority);
        node_t* m= extractTop_node_t(h);
        printf(" extract %d, \n", m->priority);
        printf("insertPost %d\n", h->insertPos);
    }

    node_t* n = peek_node_t(h);
    if(n==NULL){
        printf("Equal to NULL");
    }




    return 0;
}
