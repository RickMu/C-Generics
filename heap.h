#define TOKENPASTE(x,y) x##y

#define SIZE 4
#define STRUCT(T) TOKENPASTE(heap_,T)

#define HEAP(T) TOKENPASTE(h_,T)
typedef struct HEAP(TYPE){
    NODE_TYPE** tree;
    int insertPos;
    int size;
}STRUCT(NODE_TYPE);

#define compareNode(T) TOKENPASTE(compareNode_,T)

int compareNode(TYPE) (NODE_TYPE* n1, NODE_TYPE* n2){
    if(COMPARATOR) {
        return 1;
    }
    return 0;
}

#define safeRealloc(T) TOKENPASTE(safeRealloc_,T)
void safeRealloc(TYPE) ( STRUCT(TYPE)* h){
    h->size+= SIZE;
    h->tree= (TYPE **) realloc ( h->tree,h->size* sizeof(TYPE *));
    if(h->tree ==NULL){
        exit(EXIT_FAILURE);
    }
}


#define MAKE_HEAP(T) TOKENPASTE(makeHeap_,T)

STRUCT(TYPE)* MAKE_HEAP(TYPE)(){
    STRUCT(TYPE)* heap =(STRUCT(TYPE)*) malloc (sizeof( STRUCT(TYPE)));
    heap->tree= (TYPE**) malloc( SIZE*sizeof (TYPE *));
    heap->insertPos = 0;
    heap->size=SIZE;
    return heap;
}

#define bottomUp(T) TOKENPASTE(bottomUpHeapify_,T)

void bottomUp(TYPE)( STRUCT(TYPE) * h){
    int childPos = h->insertPos;
    int parentPos = (childPos-1)/2;

    while( childPos> 0 ){
        if(compareNode(TYPE)( h->tree[childPos]  , h->tree[parentPos] ) ){
            TYPE* tmp = h->tree[parentPos];
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

//Inserting a node at the bottom and then heapify bottom up
#define insert(T) TOKENPASTE(insert_,T)

void insert(TYPE)( STRUCT(TYPE)* h, NODE_TYPE* p){
    if(h->insertPos == h->size){
        h->size+=SIZE;
        //h->tree = (TYPE**) realloc (h->tree, h->size * sizeof(TYPE*));
        safeRealloc(TYPE)(h);
    }
    (h->tree)[h->insertPos] = p;
    bottomUp(TYPE) (h);
    (h->insertPos)++;
}

#define topDown(T) TOKENPASTE (topDownHeapify_,T)
void topDown(TYPE)( STRUCT(TYPE) h ){
    int curPos = 0;
    int childPos = curPos*2+1;

    while(curPos < h.insertPos/2){
        TYPE* largest;
        if(childPos+1 == h.insertPos){
            largest = h.tree[childPos];
        }else{
            if( compareNode(TYPE)( h.tree[childPos], h.tree[childPos+1] )){
                largest = h.tree[childPos];
            }else{
                largest = h.tree[childPos+1];
                childPos+=1;
            }
        }
        if(compareNode(TYPE)( largest, h.tree[curPos] )){
            h.tree[childPos]= h.tree[curPos];
            h.tree[curPos] = largest;
            curPos= childPos;
            childPos = curPos*2 +1;
        }else{
            break;
        }
    }
}


#define heapify(T) TOKENPASTE(heapify_,T)
void heapify(TYPE) (STRUCT(TYPE) *h){
    if( h->tree[0] == NULL){
        int lastItem = h->insertPos-1;
        h->tree[0] = h->tree[lastItem];
        h->tree[lastItem]= NULL;
        h->insertPos--;
    }
    topDown(TYPE)(*h);
}
#define extractTop(T) TOKENPASTE(extractTop_,T)
TYPE* extractTop(TYPE)(STRUCT(TYPE) *h ){
    TYPE* p = NULL;
    p = h->tree[0];
    h->tree[0]=NULL;
    heapify(TYPE) (h);
    return p;
}
//Is heap empty

#define isEmptyHeap(T) TOKENPASTE(isEmptyHeap_,T )
int isEmptyHeap(TYPE)(STRUCT(TYPE)* h){
    //printf("heap insert %d," ,h.insertPos);
    if( h->insertPos==0){
        return 1;
    }
    return 0;
}

//Peek top
#define peek(T) TOKENPASTE(peek_, T)
TYPE* peek(TYPE)(STRUCT(TYPE)* h){
    if( isEmptyHeap(TYPE)(h) ){
        return NULL;
    }

    NODE_TYPE*p = h->tree[0];
    return p;
}



/*

//heapify called when the top node is extracted

//Get top node

//Replace top with something else
NODE_TYPE* replaceTop(STRUCT(TYPE) *h, NODE_TYPE* replace){
    NODE_TYPE* p =NULL;
    p = h->tree[0];
    h->tree[0]= replace;
    heapify(h);
    return p;
}

*/


#ifdef COMPARATOR
#undef COMPARATOR
#endif
#ifdef TYPE
#undef TYPE
#endif
#ifdef NODE_TYPE
#undef NODE_TYPE
#endif
#ifdef STRUCT
#undef STRUCT
#endif


