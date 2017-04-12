

#define TOKENPASTE(x,y) x##y
#define LIST(T) TOKENPASTE(list_,T)
#define STRUCT(T) TOKENPASTE(linked_,T)
typedef struct LIST(LINKED_NODE){
    LINKED_NODE* head;
}STRUCT(LINKED_NODE);

#define makeList(T) TOKENPASTE(makeList_,T)
STRUCT(LINKED_NODE)* makeList(LINKED_NODE) (){
    STRUCT(LINKED_NODE) list = ( STRUCT(LINKED_NODE)*   ) malloc(sizeof(STRUCT(LINKED_NODE)));
    list->head=null;
    return list;
}

#define searchNode(T) TOKENPASTE(searchNode_,T)
LINKED_NODE* searchNode(LINKED_NODE)( LINKED_NODE* node, STRUCT(LINKED_NODE) * list){
    LINKED_NODE* c = list->head;
    while(c != node){
        c= c->next;
    }
    return c;
}
#define removeNode(T) TOKENPASTE(removeNode_,T)
LINKED_NODE* removeNode(LINKED_NODE) (LINKED_NODE* node, STRUCT(LINKED_NODE) * list){
    LINKED_NODE* c1 = list->head, *c2=c1;
    if(c1==node){
        list->head=c1->next;
        return c1;
    }
    while(c2!= node && c2!=NULL){
        c1=c2;
        c2=c2->next;
    }
    c1->next = c2->next;
    return c2;
}
#define insertNode(T) TOKENPASTE(insertNode_, T)
void insertNode(LINKED_NODE) (LINKED_NODE* node, STRUCT(LINKED_NODE)* list){
    node->next = list->head;
    list->head = node;
}


#ifdef LINKED_NODE
#undef LINKED_NODE
#endif
#ifdef NODE_TYPE
#undef NODE_TYPE
#endif
#ifdef STRUCT
#undef STRUCT
#endif
