#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List *list =(List*)malloc(sizeof(List));
    if(list == NULL) return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;    

    return list;
}

void * firstList(List * list) {
    if(!list || !list->head) return NULL;
    list->current = list->head;
    return list->head->data;
}

void * nextList(List * list) {
    if(!list || !list->current || !list->current->next) return NULL;
    list->current = list ->current->next;
    return list->current->data;
}

void * lastList(List * list) {
    if(!list || !list->tail) return NULL;
    list->current = list ->tail;
    return list->tail->data;
}

void * prevList(List * list) {
    if(!list || !list->current || !list->current->prev) return NULL;
    list->current = list ->current->prev;
    return list->current->data;
}

void pushFront(List * list, void * data) {
    if(!list) return;
    Node *new = createNode(data);
    if(!new)return;

    new->next = list->head;

    if(list ->head){
        list->head->prev = new;
    } else {
        list->tail = new;
    }
    list->head = new;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    if(!list || !list->current) return;
    Node *new = createNode(data);
    if(!new) return;

    new->next = list->current->next;
    new->prev = list->current;

    if(list->current->next)
        list->current->next->prev = new;
    
    list->current->next = new;

    if(list->current == list->tail)
     list -> tail = new;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}