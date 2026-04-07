/** listAsLinkedList.h
 * ======================================================================
  * Name: Caitlyn Budd
 * Section: M3
 * Project: PEX 1 - Air Force Shell (afsh)
 * ======================================================================
 */
#ifndef LISTASLINKEDLIST_H
#define LISTASLINKEDLIST_H
#include <stdbool.h>

// define a node of the linked list
typedef struct Node_struct {
    char* command;
    struct Node_struct* next;
} Node;

// Define the type (meta-data) that manages the linked list of nodes
typedef struct LinkedList_struct {
    Node* head;
    Node* tail;
    int numberOfItems;
} LinkedList;

/** linkedListInit()
 * @brief  - initializes the linked list structure
 * @return - pointer to linked list
 * @pre    - nothing
 * @post   - new empty linked list returned
 */
LinkedList* linkedListInit();

/** deleteLinkedList(()
 * @brief  - deletes linked list, freeing all memory used
 * @param list - the addres of the linked list structure
 * @pre    - unmodified linked list
 * @post   - the linked list is erased, all nodes freed
 *         - and list is set to NULL
 */
void deleteLinkedList(LinkedList** list);

/** appendElementLinkedList()
 * @brief - addes a new node to the end of the linked list
 * @param list - a ptr to the linked list structure
 * @param newNode - a ptr to a Node to append to the list
 * @pre   - 1. A new Node created dynamically is passed with values
 *               type and data already set
 *          2. linked list before node added
 * @post  - modified linked list; new node added; numberOfItems increased
 */
void appendElementLinkedList(LinkedList* list, Node* newNode);

/** createNode()
 * @brief - allocates a Node and returns a pointer to it
 * @param command - the command string to store
 * @return pointer to the allocated node or NULL if fails
 */
Node* createNode(char* command);

/** printLinkedList()
 * @brief  - outputs the linked list to the console
 * @param list - the linked list structure
 * @pre    - linked list unmodified
 * @post   - linked list unmodified; linked list items printed
 */
void printLinkedList(LinkedList* list);

/** getElementLinkedList()
 * @brief  - retrieves node at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value requested (starts at 0)
 * @return - ptr to Node at 'position', NULL on failure
 * @pre    - unmodified linked list
 * @post   - unmodified linked list; pointer to Node at 'position' returned
 */
Node* getElementLinkedList(LinkedList* list, int position);

/** deleteElementLinkedList()
 * @brief  - deletes node at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to delete (starts at 0)
 * @pre    - unmodified linked list
 * @post   - 1. modified linked list; node at 'position' removed;
 *              node data and node being removed are freed
 *           2. Print error message, and do nothing else if out of bounds
 */
void deleteElementLinkedList(LinkedList* list, int position);

/** insertElementLinkedList()
 * @brief  - adds node at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of node to add (starts at 0)
 * @param  newNode - ptr to Node to be added
 * @pre   - 1. A new Node created dynamically is passed with values
 *               type and data already set
 *          2. linked list before node added
 * @post   - 1. modified linked list; node with pointer to node added at 'position'
 *           2. Print error message, and do nothing else if out of bounds
 */
void insertElementLinkedList(LinkedList* list, int position, Node* newNode);

#endif  // LISTASLINKEDLIST_H
