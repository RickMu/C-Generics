//
// Created by 高静 on 2017/4/6.
//

#include<stdio.h>
#include <stdlib.h>


#include "comparator.h"
#include "heap.h"
#include "heap.c"

int main(){

    heap_t* h = makeHeap();
    h->size= 7;
    h->tree = (node_t**) malloc( h->size* sizeof(node_t*));

    int tmp[7] = {8,4,-1,3,1,9,10};
    for(int i = 0;i<h->size;i++){
        node_t* n = (node_t*) malloc (sizeof(node_t));
        n->priority=tmp[i];
        insert(h, n);
    }

    int size=  h->size;
    for(int i =0;i<size;i++ ){
        printf("%d  ", h->tree[i]->priority);
    }
    printf("\nStored order\n");

    while(!isEmpty(h)){
        node_t* ret= extracTop(h);
        printf("%d ", ret->priority);
    }
    printf("Extraction");

   return 0;
}
