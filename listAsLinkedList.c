/** listAsLinkedList.c
 * ===========================================================
 * Name: Caitlyn Budd
 * Section: M3
 * Project: Your CS220 Implementation of Linked List Library
 *          modified slightly for CS483 PEX1
 * Purpose: List ADT as linked list
 * ===========================================================
 */

#include "listAsLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/** linkedListInit()
 * @brief  - initializes the linked list structure
 * @return - pointer to linked list
 */
LinkedList* linkedListInit() {
    LinkedList* newList = malloc(sizeof(LinkedList));
    newList->head = NULL;
    newList->tail = NULL;
    newList->numberOfItems = 0;
    return newList;

}

/** deleteLinkedList(()
 * @brief  - deletes linked list and nodes, freeing all memory used
 * @param list - a ptr to the linked list structure
 */
void deleteLinkedList(LinkedList** list) {
    if ((*list)->head == NULL) return;
    if ((*list)->head == (*list)->tail) {        
    free((*list)->head);        
    (*list)->head = (*list)->tail = NULL;    
    } 
    else { 
    Node* current = (*list)->head;        
    while (current->next != (*list)->tail) {            
        Node* next = current->next; 
        free(current);
        current = next;    
    }   
            
    (*list)->head = NULL;
    (*list)->tail = NULL;   
    (*list)->numberOfItems = 0;
}   
}

/** createNode()
 * @brief - allocates a Node and returns a pointer to it
 * @param type - the type of node to create
 * @param number - the number to store in the node (if applicable)
 * @param operator - the operator to store in the node (if applicable)
 * @return pointer to the allocated node or NULL if fails
 */
Node* createNode(char* comm) {
    Node* newNode = malloc(sizeof(Node));
    newNode->command = comm;
    return newNode;
}

/** appendElementLinkedList()
 * @brief - addes a new node to the end of the linked list
 * @param list - a ptr to the linked list structure
 * @param newNode - a ptr to a Node to append to the list
 */
void appendElementLinkedList(LinkedList* list, Node* newNode) {   
    //newNode->next = NULL;    
    if (list->tail) {              
    list->tail->next = newNode;    
    } 
    else {        
        list->head = newNode;    
    }
    list->tail = newNode;    
    list->numberOfItems++;
}


/** lengthOfLinkedList()
 * @brief  - returns the size of the linked list
 * @param list - a ptr to the linked structure
 * @return - number of items in the linked list
 */
int lengthOfLinkedList(LinkedList* list) {
    int size = list->numberOfItems;
    return size;
}

/** printLinkedList()
 * @brief  - outputs the linked list to the console
 * @param list - the linked list structure
 */
void printLinkedList(LinkedList* list) {
    Node* current = list->head;   
    while (current != NULL) {        
    printf("%s\n", current->command);        
    current = current->next;
    }
}

/** getElementLinkedList()
 * @brief  - Retrieves node at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value requested
 * @return - ptr to Node at 'position', NULL if given an invalid position
 */
Node* getElementLinkedList(LinkedList* list, int position) {
    if (list->numberOfItems < position && position >= 0) {
        printf("Error, position out of range\n");
        exit(0);
     }
  
     Node* currentNode = malloc(sizeof(Node));
     currentNode = list->head;
     int currentPosition = 0;
  
     while(currentPosition != position){
      currentNode= currentNode->next;
      currentPosition ++;
     }
     //free(currentNode);
     return currentNode;
     
    /*
    Node* currentnode = list->head;
    for(int i = 0; i < position; i++){
        currentnode = currentnode->next;
    }
    return currentnode;
    */

}

/** deleteElementLinkedList()
 * @brief  - Deletes (i.e., frees) node at a given position.  Function will print an error message
 *           if given an invalid position.
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to delete
 */
void deleteElementLinkedList(LinkedList* list, int position) {
    if (list->numberOfItems < position && position >= 0) {
        printf("Error, position out of range\n");
        exit(0);
     }
    if(list == NULL){
        printf("list empty\n");
        return;
    }
    Node* nodeToDelete = list->head;
  
    if (position == 0) {
        list->head = list->head->next;
        if(list->head == NULL){
            list->tail = NULL;
        }

        //free(nodeToDelete);
    } 
    else {
        Node* nodeBefore = list->head;
        int currentPosition = 0;

        while (currentPosition < position - 1) {
            nodeBefore = nodeBefore->next;
            currentPosition++;
        }

        nodeToDelete = nodeBefore->next;
        nodeBefore->next = nodeToDelete->next;

        if(nodeToDelete->next == NULL){
            list->tail = nodeBefore;
        }
        //free(nodeToDelete);
    }

      list->numberOfItems --;
}


/** insertElementLinkedList()
 * @brief  - Inserts a node at a given position.  Function should print an error message
 *           if given an invalid position.
 * @param  list - a ptr to the linked list structure
 * @param  position - index of node to add
 * @param  newNode - ptr to Node to be added
 */
void insertElementLinkedList(LinkedList* list, int position, Node* newNode) {
    if (list->numberOfItems < position && position > 0) {
        printf("Error, position out of range\n");
        exit(0);
     }
     if(list == NULL || newNode == NULL){
        printf("no list or node");
        exit(0);
     }

    Node* nodetoAdd = newNode;
    
    if (position == 0) {
        nodetoAdd->next = list->head;
        list->head = nodetoAdd;
        if(list->numberOfItems == 0){
            list->tail = nodetoAdd;
        }
    } else {
        Node* nodeBefore = list->head;
        for(int i = 0; i < position -1; i++){
            if(nodeBefore == NULL){
                printf("nodebefore is null\n");
                exit(0);
            }
            nodeBefore = nodeBefore->next;
        }

        nodetoAdd->next = nodeBefore->next;
        nodeBefore->next = nodetoAdd;

        if(nodetoAdd->next == NULL){
            list->tail = nodetoAdd;
        }

        
    }
    list->numberOfItems++;
}

