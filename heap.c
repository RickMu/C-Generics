//
// Created by 高静 on 2017/3/31.
//
#define SIZE 4




//Compare the order of two processes
int compareNode(NODE_TYPE* n1, NODE_TYPE* n2){
    if(COMPARATOR) {
        return 1;
    }
    return 0;
}

//Safe mallocs
void safeCallocHeap(heap_t* h){
    h->size+= SIZE;
    h->tree= (NODE_TYPE**)realloc ( h->tree,h->size* sizeof(NODE_TYPE));
    if(h->tree ==NULL){
        exit(EXIT_FAILURE);
    }
}

//Makes the heap
heap_t* makeHeap(){
    heap_t* heap =(heap_t*) malloc (sizeof( heap_t));
    heap->tree= (NODE_TYPE**) malloc( SIZE* sizeof (NODE_TYPE));
    heap->insertPos = 0;
    heap->size= SIZE;
    return heap;
}

//Heapify
void bottomUpHeapify(heap_t* h){
    int childPos = h->insertPos;
    int parentPos = (childPos-1)/2;

    while( childPos> 0 ){
        if(compareNode( h->tree[childPos]  , h->tree[parentPos] ) ){
            NODE_TYPE* tmp = h->tree[parentPos];
            h->tree[parentPos]= h->tree[childPos];
            h->tree[childPos] = tmp;
            childPos= parentPos;
            parentPos = (childPos-1)/2;
        }else{
            break;
        }
    }
}
// heapify
void topDownHeapify(heap_t h ){
    int curPos = 0;
    int childPos = curPos*2+1;

    while(curPos < h.insertPos/2){
        NODE_TYPE* largest;
        if(childPos+1 == h.insertPos){
            largest = h.tree[childPos];
        }else{
            if( compareNode( h.tree[childPos], h.tree[childPos+1] )){
                largest = h.tree[childPos];
            }else{
                largest = h.tree[childPos+1];
                childPos+=1;
            }
        }
        if(compareNode( largest, h.tree[curPos] )){
            h.tree[childPos]= h.tree[curPos];
            h.tree[curPos] = largest;
            curPos= childPos;
            childPos = curPos*2 +1;
        }else{
            break;
        }
    }
}

//Inserting a node at the bottom and then heapify bottom up
void insert( heap_t* h, NODE_TYPE* p){
    if(h->insertPos == h->size){
        safeCallocHeap(h);
    }
    (h->tree)[h->insertPos] = p;
    bottomUpHeapify(h);
    (h->insertPos)++;
}

//heapify called when the top node is extracted
void heapify(heap_t *h){

    if( h->tree[0] == NULL){
        int lastItem = h->insertPos-1;
        h->tree[0] = h->tree[lastItem];
        h->tree[lastItem]= NULL;
        h->insertPos--;
    }
    topDownHeapify(*h);
}
//Get top node
NODE_TYPE* extracTop(heap_t *h ){
    NODE_TYPE* p = NULL;
    p = h->tree[0];
    h->tree[0]=NULL;
    heapify(h);
    return p;
}
//Replace top with something else
NODE_TYPE* replaceTop(heap_t *h, NODE_TYPE* replace){
    NODE_TYPE* p =NULL;
    p = h->tree[0];
    h->tree[0]= replace;
    heapify(h);
    return p;
}
//Peek top
NODE_TYPE* peekTop(heap_t* h){
    NODE_TYPE*p = h->tree[0];
    return p;
}

//Is heap empty
int isEmpty(heap_t* h){
    //printf("heap insert %d," ,h.insertPos);
    if( h->insertPos==0){
        return 1;
    }
    return 0;
}


