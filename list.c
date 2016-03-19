/*
* ORIGINALLY CREATED BY 
*
* Nico Williams AND Samuel Reha
* nijowill          sreha
* 4/18/2014         4/18/2014
*
* Modified by Nico Williams 
* and Joseph Rogers on 5/02/2014
*
* Modified by Nico Williams on
* 5/23/2014
*
* Modified by Nico Williams (nijowill) and
* Patrick Russell (pcrussel) on
* 06/06/2014
*
* This program creates a doubly linked list of ints
* as per the instructions of assignment 4.
*
* This program utilises myinclude.h, list.h, assert.h
*
*
*/

/* 
 *     Source code (.c) file for doubly linked list ADT
 *
 * This contains the implementation of the operations and types 
 * exported by the raryList.h file.
 */

#include "myinclude.h"   /* Some C defines provided to us by the Professor */
#include "list.h"       /* The ADT header file */
#include <assert.h>      /* This allows me to use the "assert" macro */

/* 
 * The file List.h contains the following:
 *
 * typedef struct ListStruct* ListHndl;
 * void freeList(ListHndl* L);
 * Boolean isEmpty(ListHndl L); 
 * Boolean offEnd(ListHndl L); 
 * Boolean atFirst(ListHndl L);
 * Boolean atLast(ListHndl L); 
 * int getFirst(ListHndl L); 
 * int getLast(ListHndl L); 
 * int getCurrent(ListHndl L); 
 * void makeEmpty(ListHndl L); 
 * void moveFirst(ListHndl L); 
 * void moveLast(ListHndl L); 
 * void movePrev(ListHndl L); 
 * void moveNext(ListHndl L); 
 * void insertAtFront(ListHndl L, int data); 
 * void insertAtBack(ListHndl L, int data); 
 * void insertBeforeCurrent(ListHndl L, int data); 
 * void deleteFirst(ListHndl L); 
 * void deleteLast(ListHndl L); 
 * void deleteCurrent(ListHndl L); 
 * void printList(FILE* out, ListHndl L); 
 */
 
 /* 
 * Additional types used throughout the ADT implementation:
 * NodePtr: a pointer to a struct containing  
 *             NodeStruct pointers and a int.
 */
 
typedef struct NodeStruct* NodePtr;

typedef struct ListStruct {
  int Length;           /*The length of a list*/
  NodePtr first;        /* The beginning of the list */
  NodePtr last;         /* The end of the list */ 
  NodePtr current;      /* The current marker in the list */
} ListStruct;

typedef struct NodeStruct {
  int data;                 /* The data within the nodes */
  struct NodeStruct* next;   /* the next pointer */
  struct NodeStruct* prev;   /* the previous pointer */
} NodeStruct;


/*** Constructors-Destructors ***/

 /*
 * EXPORTED FUNCTIONS
 */

/*
 * The procedure "newList" creates a new list object
 * and returns a pointer to it.  This function should be used
 * to initialize each List before any other operations are performed
 * on that List.  There is no precondition.
 * The postcondition is that the List is initialized to an empty List.
 */

ListHndl newList (){
  ListHndl tempList = malloc ( sizeof(ListStruct) );
  assert(tempList != NULL);
  
  tempList->Length = 0;
  tempList->current = NULL;
  tempList->first = NULL;
  tempList->last = NULL;
  
  return (tempList);
}  

/* 
 * The procedure "freeList" should be called once on each
 * List when the List is no longer. Its purpose is to free up 
 * the storage used by the List.  
 * Precondition: List has been initialized by "newList",
 *               List need not be empty.
 * Postcondition: List is set to NULL
 * Note: "Boolean" is defined in myinclude.h
 */
void freeList (ListHndl *List){
  assert ((*List) != NULL && List != NULL); 
  while (! isEmpty((*List))) {
    deleteLast(*List); 
  }
  free (*List);
  *List = NULL;
}
/* 
 * The procedure "newNode" 
 * creates a new node to be put in the list  
 */
NodePtr newNode(int someData) {
	NodePtr tempNode = malloc(sizeof(NodeStruct));
	assert(tempNode != NULL);
	
	tempNode->data = someData;
	tempNode->next = NULL;
	tempNode->prev = NULL;
	return(tempNode);
}
/* 
 * The procedure "freeNode" frees up 
 * the storage used by the node.
 * Precondition:*Node != NULL && Node != NULL,.
 * Postcondition: Node is set to NULL
 */
void freeNode(NodePtr *Node) {
	assert(*Node != NULL && Node != NULL);
	free(*Node);
	*Node = NULL;
	
}
  
/*** Access functions ***/

/* The access function isEmpty returns true if the sequence
 * represented by the List is the empty sequence.
 * Postcondition: returns true if the sequence is empty,
 *                and false otherwise.
 */
Boolean isEmpty(ListHndl List){
   assert (List != NULL);

   return (List->Length == 0);
}

/* The access function offEnd returns true if
 * there is no current node.
 * Postcondition: returns true if there is no current node,
 *                and false otherwise.
 */
Boolean offEnd(ListHndl List) {
  assert(List != NULL);
  
  return (List->current == NULL);
}

/* The access function atFirst returns true if
 * the current node is the first node and the list 
 * is not offEnd.
 * Postcondition: returns true if current == first and !offEnd(),
 *                and false otherwise.
 */
Boolean atFirst(ListHndl List) {
  assert (List != NULL);
  
  return (List->current == List->first && !offEnd(List));
}

/* The access function atLast returns true if
 * the current node is the last node and the list 
 * is not offEnd.
 * Postcondition: returns true if current == last and !offEnd(),
 *                and false otherwise.
 */
Boolean atLast(ListHndl List) {
  assert (List != NULL);
  
  return (List->current == List->last && !offEnd(List));
}

/* The access function getFirst returns the
 * first element in the list.
 * Precondition: the list is not empty
 * Postcondition: returns the first element             
 */
int getFirst(ListHndl List) {
  assert (List != NULL);
  assert (!isEmpty(List));
  
  return (List->first->data);
}

/* The access function getLast returns the
 * last element in the list.
 * Precondition: the list is not empty
 * Postcondition: returns the last element             
 */
int getLast(ListHndl List) {
  assert (List != NULL);
  assert (!isEmpty(List));
  
  return (List->last->data);
}

/* The access function getCurrent returns the
 * Current element in the list.
 * Precondition: the list is not empty and not offEnd
 * Postcondition: returns the current element             
 */
int getCurrent(ListHndl List) {
  assert (List != NULL);
  assert (!isEmpty(List));
  assert (List->current != NULL);
  
  return (List->current->data);
}

/*** Manipulation procedures ***/

/* The manipulation procedure makeEmpty 
 * deletes all elements from the list, making it empty.
 * Postcondition: isEmpty(), offEnd() are both true            
 */
void makeEmpty(ListHndl List){
  while(List->Length > 0){
    deleteFirst(List);
  }
  assert(isEmpty(List));
  assert(offEnd(List));
}

/* The manipulation procedure moveFirst without changing
 * list order, makes the first element the current one.
 * Precondition: !isEmpty()
 * Postcondition: !offEnd()           
 */
void moveFirst(ListHndl List){
  assert(!isEmpty(List));
  
  List->current = List->first;
}

/* The manipulation procedure moveLast without changing
 * list order, makes the last element the current one.
 * Precondition: !isEmpty()
 * Postcondition: !offEnd()           
 */
void moveLast(ListHndl List){
  assert(!isEmpty(List));
  
  List->current = List->last;
}

/* The manipulation procedure movePrev without changing
 * list order, moves the current marker one element earlier in the list
 * Precondition: !offEnd() 
 * Postcondition: offEnd() only if atFirst() was true        
 */
void movePrev(ListHndl List){
  assert(!offEnd(List));
  
  List->current = List->current->prev;
}

/* The manipulation procedure moveNext without changing
 * list order, moves the current marker one element later in the list
 * Precondition: !offEnd() 
 * Postcondition: offEnd() only if atLast() was true        
 */
void moveNext(ListHndl List){
  assert(!offEnd(List));
  
  List->current = List->current->next;
}

/* The manipulation procedure insertAtFront 
 * Inserts new element before first.
 * Postcondition: !isEmpty(); doesn’t change current element
 */
void insertAtFront(ListHndl List, int data){
  assert (List != NULL);
  
  NodePtr tmp = newNode(data);
  if (isEmpty(List)) {
    List->first = tmp;
    List->current = tmp;
    List->last = tmp;
  } else {
    tmp->next = List->first;
    List->first->prev = tmp;
    List->first = tmp;
  }
  List->Length++;
}

/* The manipulation procedure insertAtBack
 * Inserts new element after the last one.
 * Postcondition: !isEmpty(); doesn’t change current element
 */
void insertAtBack(ListHndl List, int data){
  assert (List != NULL);
  
  NodePtr tmp = newNode(data);
  if (isEmpty(List)) {
    List->first = tmp;
    List->current = tmp;
    List->last = tmp;
  } else {
    tmp->prev = List->last;
    List->last->next = tmp;
    List->last = tmp;
  }
  List->Length++;
}

/* The manipulation procedure insertBeforeCurrent
 * Inserts new element before the current one
 * Precondition: !offEnd
 * Postcondition: !isEmpty(), !offEnd(), !atFirst()
 *               doesn’t change current element
 */
void insertBeforeCurrent(ListHndl List, int data){
  assert(!offEnd(List));
  assert(List != NULL);
   
  if ((List->current) == (List->first)) {
    insertAtFront(List, data);
  } else {
    NodePtr tmp = newNode(data);
    tmp->next=List->current;
	tmp->prev=List->current->prev;
	List->current->prev=tmp;
	tmp->prev->next=tmp;
	List->Length++;
  }

}

/* The manipulation procedure deleteFirst
 * deletes the first element.
 * Precondition: !isEmpty()
 */
void deleteFirst(ListHndl List){
  assert (List != NULL);
  assert (!isEmpty(List));
  
  if (List->Length == 1) {
    assert(List->first != NULL);
	freeNode(&List->first);
    List->current = NULL;
    List->first = NULL;
    List->last = NULL;
  } else {
    if(atFirst(List)){
	  NodePtr tmp = List->first;
      NodePtr tmp2 = tmp->next;
      tmp->next = NULL;
      tmp2->prev = NULL;
      List->first = tmp2;
      freeNode(&tmp);
      tmp = NULL;
	  List->current = NULL;
	}else{
      NodePtr tmp = List->first;
      NodePtr tmp2 = tmp->next;
      tmp->next = NULL;
      tmp2->prev = NULL;
      List->first = tmp2;
      freeNode(&tmp);
      tmp = NULL;
	}
  }
  List->Length--;
}

/* The manipulation procedure deleteLast
 * deletes the last element.
 * Precondition: !isEmpty()
 */
void deleteLast(ListHndl List){
  assert (List != NULL);
  assert (!isEmpty(List));
  
  if (List->Length == 1) {
	freeNode(&List->last);
    List->current = NULL;
    List->first = NULL;
    List->last = NULL;
  } else {
    if(atLast(List)){
      NodePtr tmp = List->last;
      NodePtr tmp2 = tmp->prev;
      tmp->prev = NULL;
      tmp2->next = NULL;
      List->last = tmp2;
      freeNode(&tmp);
      tmp = NULL;
	  List->current = NULL;
	}else{
	  NodePtr tmp = List->last;
      NodePtr tmp2 = tmp->prev;
      tmp->prev = NULL;
      tmp2->next = NULL;
      List->last = tmp2;
      freeNode(&tmp);
      tmp = NULL;
	}
  }
  List->Length--;
}

/* The manipulation procedure deleteCurrent
 * deletes the current element.
 * Precondition: !isEmpty() and !offEnd()
 * Postcondition: offEnd()
 */
void deleteCurrent(ListHndl List){
  assert (List != NULL);
  assert (!isEmpty(List));
  assert (!offEnd(List));
  
  if (List->Length == 1) {
    freeNode(&List->first);
    List->current = NULL;
    List->first = NULL;
    List->last = NULL;
	List->Length--;
  } else {
    if (atFirst(List)) {
      deleteFirst(List);
      List->current = NULL;
    } else if (atLast(List)) {
      deleteLast(List);
      List->current = NULL;
    } else {
      List->current->prev->next = List->current->next;
      List->current->next->prev = List->current->prev;
      freeNode(&List->current);
      List->current = NULL;
	  List->Length--;
    }
  }  

}

/*** Other operations ***/

/* The printList operation
 * prints out the list with the current element marked
 */
void printList(FILE* out, ListHndl List){
  assert (List != NULL);
  assert (!isEmpty(List));

  NodePtr tmp = List->first;
  while (tmp != NULL){
    if (tmp == List->current){
      printf("{%d} ",tmp->data);
    } else {
      printf("%d ", tmp->data);
    }
    tmp = tmp->next;
  }
  printf("\n");
}