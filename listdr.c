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
* This program test all the functions and edge cases
* of those functions for the linked list created by
* raryList.c
*
*This program utilises myinclude.h, list.h
*
*/

 /* 
 * Driver program for the List module.
 * The purpose of this is not to do anything "interesting"
 * but rather to test out and make sure that the List
 * ADT implementation is working properly.
 */

#include "myinclude.h"
#include "list.h"

int main (){

  /***Exercise List constructor***/
  ListHndl List;
  List = NULL;
  List = newList ();

  if(List){
    printf("List Created\n");
  }else{
    printf("List Not Created\n");
  }
  
  printf("isEmpty %d\n",isEmpty(List)); /*should print 1*/
  
  /***Populate with test data***/
  int i;
  for(i=0; i<=4; i++){
    insertAtFront(List,i);
  }
  
  printList(stdout, List);
  
  printf("isEmpty %d\n",isEmpty(List)); /*should print 0*/

  int j;
  for(j=5; j<=9; j++){
    insertAtBack(List,j);
  } 
  printList(stdout, List);
  
  /***Exercise all access functions***/
  printf("offEnd %d\n",offEnd(List));/*should print 0*/
  
  printf("atFirst %d\n",atFirst(List));/*should print 0*/
  
  printf("atLast %d\n",atLast(List));/*should print 0*/
  
  printf("getFirst %d\n", getFirst(List));/*should print 4*/
  
  printf("getLast %d\n", getLast(List));/*should print 9*/
  
  printf("getCurrent %d\n", getCurrent(List));/*should print 0*/
  
  /***Exercise all removal manipulation functions***/
  deleteLast(List);
  printList(stdout, List);
  printf("getLast %d\n", getLast(List));/*should print 8*/
  
  deleteFirst(List);
  printList(stdout, List);
  printf("getFirst 	\n", getFirst(List));/*should print 3*/
  
  deleteCurrent(List);
  printList(stdout, List);
  
  moveLast(List);
  printList(stdout, List);
  movePrev(List);
  printList(stdout, List);
  moveNext(List);
  printList(stdout, List);

  /***Exercise various edge cases***/  
  makeEmpty(List);
  insertAtFront(List, 40);
  moveFirst(List);
  deleteCurrent(List);
  
  insertAtFront(List, 41);
  insertAtBack(List, 42);
  moveFirst(List);
  insertBeforeCurrent(List, 43);
  printList(stdout, List);
  
  /***Exercise List destructors***/
  
  deleteCurrent(List);
  printList(stdout, List);
  
  makeEmpty(List);
  printf("offEnd %d\n",offEnd(List));/*should print 1*/
  

  freeList(&List);
  return(0);
} 