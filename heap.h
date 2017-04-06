//
// Created by 高静 on 2017/4/6.
//

#ifndef GENERICS_HEAP_H
#define GENERICS_HEAP_H

#include "comparator.h"

/*
 * Using Macro to enable a struct to store a type of user's choice
 * */
#define HEAP(NODE_TYPE )\
struct heap{\
    NODE_TYPE** tree;\
    int insertPos;\
    int size;\
}
typedef HEAP(NODE_TYPE) heap_t;


heap_t* makeHeap();
void insert( heap_t* h, NODE_TYPE* p);
NODE_TYPE* extracTop(heap_t *h );
int isEmpty(heap_t* h);
NODE_TYPE* peekTop(heap_t* h);

#endif //GENERICS_HEAP_H
