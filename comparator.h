//
// Created by 高静 on 2017/4/6.
//

#ifndef GENERICS_COMPARATOR_H
#define GENERICS_COMPARATOR_H
#include <stdio.h>
#include <stdlib.h>

#define COMPARATOR  n1->priority > n2->priority

typedef struct simpleNode{
    int priority;
}node_t;

#define NODE_TYPE node_t


#endif //GENERICS_COMPARATOR_H
