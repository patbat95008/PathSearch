#include "myinclude.h"
#include "graph.h"
#include "list.h"


int main(){
  Graph G;
  G = NULL;
  G = newGraph (6);

  if(G){
    printf("Graph Created\n");
  }else{
    printf("Graph Not Created\n");
  }
  
  addEdge(G,0,1);
  addEdge(G,1,2);
  addEdge(G,1,3);
  addEdge(G,3,4);
  addEdge(G,4,2);
  
  doBFS(G,0);
 
  printf("%d\n", getDistance(G,0));
  printf("%d\n", getDistance(G,1));
  printf("%d\n", getDistance(G,2));
  printf("%d\n", getDistance(G,3));
  printf("%d\n", getDistance(G,4));
  printf("%d\n", getDistance(G,5));
  
  printList(stdout,getPathTo(G,4));
  
  

  
 /*  freeGraph(&G); */
  return(0);
 
}