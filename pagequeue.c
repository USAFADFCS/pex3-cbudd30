/** pagequeue.c
 * ===========================================================
 * Name: Caitlyn Budd, 23 April 2026
 * Section: CS483 / M3
 * Project: PEX3 - Page Replacement Simulator
 * Purpose: Implementation of the PageQueue ADT — a doubly-linked
 *          list for LRU page replacement.
 *          Head = LRU (eviction end), Tail = MRU end.
 * =========================================================== */
#include <stdio.h>
#include <stdlib.h>

#include "pagequeue.h"

/**
 * @brief Create and initialize a page queue with a given capacity
 */
PageQueue *pqInit(unsigned int maxSize) {
    // TODO: malloc a PageQueue, set head and tail to NULL,
    //       size to 0, maxSize to maxSize, and return the pointer
    PageQueue* newpq = malloc(sizeof(PageQueue));
    newpq->head = NULL;
    newpq->tail = NULL;
    newpq->size = 0;
    newpq->maxSize = maxSize;
    return newpq;
}

/**
 * @brief Access a page in the queue (simulates a memory reference)
 */
long pqAccess(PageQueue *pq, unsigned long pageNum) {
    // TODO: Search the queue for pageNum (suggest searching tail->head
    //       so you naturally count depth from the MRU end).
    //
    // HIT path (page found at depth d):
    //   - Remove the node from its current position and re-insert
    //     it at the tail (most recently used).
    //   - Return d.
    if(pq->tail == NULL){
        return -1;
    }
    
    
    PqNode* currentnode = malloc(sizeof(PqNode));
    currentnode = pq->tail;
    for(int depth = 0; depth <= pq->size; depth ++){
        if(currentnode->pageNum != pageNum){
            currentnode = currentnode->prev;
        }
        else{
            //remove from queue, relinked prev/next nodes
            if(currentnode->prev == NULL){
                pq->head = currentnode->next;
            }
            else{
            currentnode->prev->next = currentnode->next;
            }

            if(currentnode->next == NULL){
            pq->tail = currentnode->prev;
            }
            else{
            currentnode->next->prev = currentnode->prev;
            }

            //append to end
            if (pq->tail) {              
                pq->tail->next = currentnode;
            } 
            else {        
                pq->head = currentnode;    
            }
            pq->tail = currentnode;

            //return depth of node
            return depth;
            
        }
    }
    free(currentnode);


    //
    // MISS path (page not found):
    //   - Allocate a new node for pageNum and insert it at the tail.
    PqNode* newNode = malloc(sizeof(PqNode));
    newNode->pageNum = pageNum;

    if (pq->tail) {              
    pq->tail->next = newNode;    
    } 
    else {        
        pq->head = newNode;    
    }
    pq->tail = newNode;    
    pq->size++;

    //   - If size now exceeds maxSize, evict the head node (free it).
    if(pq->size > pq->maxSize){
        PqNode* temp = pq->head;
        pq->head = pq->head->next;
        free(temp);
        pq->size --;
    }
    

    //   - Return -1.
    return -1;
}

/**
 * @brief Free all nodes in the queue and reset it to empty
 */
void pqFree(PageQueue *pq){
    // TODO: Walk from head to tail, free each node, then free
    //       the PageQueue struct itself.
    if(pq->head == NULL) return;
    if (pq->head == pq->tail) {        
    free(pq->head);

    pq->head = pq->tail = NULL;    
    } 
    else { 
    PqNode* current = pq->head;        
    while (current->next != pq->tail) {            
        PqNode* next = current->next; 
        free(current);
        current = next;    
    }   
            
    pq->head = NULL;
    pq->tail = NULL;   
    pq->size = 0;
    }
}

/**
 * @brief Print queue contents to stderr for debugging
 */
void pqPrint(PageQueue *pq) {
    // TODO (optional): Print each page number from head to tail,
    //                  marking which is head and which is tail.
    //                  Useful for desk-checking small traces.
    PqNode* current = pq->head;   
    while (current != NULL) {        
    printf("%lu\n", current->pageNum);        
    current = current->next;
    }
}
