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
* This program is the h file for list.c
*/

/* 
 *     Header (.h) file for doubly linked list ADT
 *
 * This contains the operations and types exported
 * by the module. The module implements the ADT list
 * using dynamic memory allocation.  The state of a Linked List
 * is a (possibly empty) list cotaining a sequence of nodes 
 * containing ints, with the "front" of the list
 * at the beginning (left), and the "back" of the 
 * list at the end (right).
 * 
 * USE OF THIS ADT ALSO REQUIRES THAT "myinclude.h" be
 * included.
 */
 
 
 /* 
 * The following defines the list handle type.
 * Users should declare (and initialize to null)
 * one variable of type "ListHndl" for each List they
 * want to have.  After declaration (and initialization
 * to null), the "newList" procedure must be called before
 * any list operations can be performed.
 */
 
 #include "myinclude.h"
 
typedef struct ListStruct* ListHndl;

/*** Constructors-Destructors ***/

/*
 * The procedure "newList" creates a new list object
 * and returns a pointer to it.  This function should be used
 * to initialize each list before any other operations are performed
 * on that list.  There is no precondition.
 * The postcondition is that the list is initialized to an empty list.
 */

ListHndl newList( void );


/* 
 * The procedure "freeList" should be called once on each
 * list when the list is no longer. Its purpose is to free up 
 * the storage used by the list.  
 * Precondition: list has been initialized by "newList",
 *               list need not be empty.
 * Postcondition: list is set to null
 * Note: "Boolean" is defined in myinclude.h
 */

void freeList(ListHndl* L);
 
 
/* NOTE: all Access functions and Manipulation procedures also have the
precondition that L has been initialized by newList().
*/
/*** Access functions ***/

/* The access function isEmpty returns true if the sequence
 * represented by the List is the empty sequence.
 * Postcondition: returns true if the sequence is empty,
 *                and false otherwise.
 */
Boolean isEmpty(ListHndl L);

/* The access function offEnd returns true if
 * there is no current node.
 * Postcondition: returns true if there is no current node,
 *                and false otherwise.
 */
Boolean offEnd(ListHndl L);

/* The access function atFirst returns true if
 * the current node is the first node and the list 
 * is not offEnd.
 * Postcondition: returns true if current == first and !offEnd(),
 *                and false otherwise.
 */
Boolean atFirst(ListHndl L);

/* The access function atLast returns true if
 * the current node is the last node and the list 
 * is not offEnd.
 * Postcondition: returns true if current == last and !offEnd(),
 *                and false otherwise.
 */
Boolean atLast(ListHndl L);

/* The access function getFirst returns the
 * first element in the list.
 * Precondition: the list is not empty
 * Postcondition: returns the first element             
 */
int getFirst(ListHndl L);

/* The access function getLast returns the
 * last element in the list.
 * Precondition: the list is not empty
 * Postcondition: returns the last element             
 */
int getLast(ListHndl L);

/* The access function getCurrent returns the
 * Current element in the list.
 * Precondition: the list is not empty and not offEnd
 * Postcondition: returns the current element             
 */
int getCurrent(ListHndl L);

/*** Manipulation procedures ***/

/* The manipulation procedure makeEmpty 
 * deletes all elements from the list, making it empty.
 * Postcondition: isEmpty(), offEnd() are both true            
 */
void makeEmpty(ListHndl L);

/* The manipulation procedure moveFirst without changing
 * list order, makes the first element the current one.
 * Precondition: !isEmpty()
 * Postcondition: !offEnd()           
 */
void moveFirst(ListHndl L);

/* The manipulation procedure moveLast without changing
 * list order, makes the last element the current one.
 * Precondition: !isEmpty()
 * Postcondition: !offEnd()           
 */
void moveLast(ListHndl L);

/* The manipulation procedure movePrev without changing
 * list order, moves the current marker one element earlier in the list
 * Precondition: !offEnd() 
 * Postcondition: offEnd() only if atFirst() was true        
 */
void movePrev(ListHndl L);

/* The manipulation procedure moveNext without changing
 * list order, moves the current marker one element later in the list
 * Precondition: !offEnd() 
 * Postcondition: offEnd() only if atLast() was true        
 */
void moveNext(ListHndl L);

/* The manipulation procedure insertAtFront 
 * Inserts new element before first.
 * Postcondition: !isEmpty(); doesn’t change current element
 */
void insertAtFront(ListHndl L, int data);

/* The manipulation procedure insertAtBack
 * Inserts new element after the last one.
 * Postcondition: !isEmpty(); doesn’t change current element
 */
void insertAtBack(ListHndl L, int data);

/* The manipulation procedure insertBeforeCurrent
 * Inserts new element before the current one
 * Precondition: !offEnd
 * Postcondition: !isEmpty(), !offEnd(), !atFirst()
 *               doesn’t change current element
 */
void insertBeforeCurrent(ListHndl L, int data);

/* The manipulation procedure deleteFirst
 * deletes the first element.
 * Precondition: !isEmpty()
 */
void deleteFirst(ListHndl L);

/* The manipulation procedure deleteLast
 * deletes the last element.
 * Precondition: !isEmpty()
 */
void deleteLast(ListHndl L);

/* The manipulation procedure deleteCurrent
 * deletes the current element.
 * Precondition: !isEmpty() and !offEnd()
 * Postcondition: offEnd()
 */
void deleteCurrent(ListHndl L); 


/*** Other operations ***/

/* The printList operation
 * prints out the list with the current element marked
 */
void printList(FILE* out, ListHndl L);