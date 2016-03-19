#include "list.h"
#include "graph.h" 
#include "myinclude.h"


typedef struct graphStruct {
  int size;
  int* parents;
  int* colors;
  int* distances;
  int* adjList;
  ListHndl list;
  
  }graphStruct;
  
Graph newGraph(int n){

  Graph tempGraph = calloc(n, sizeof(int));
  assert(tempGraph != NULL); 
  
  tempGraph->size = n;  
  tempGraph->parents = calloc(n, sizeof(int));
  tempGraph->colors = calloc(n, sizeof(int));
  tempGraph->distances = calloc(n, sizeof(int));
  tempGraph->adjList = calloc(n, sizeof(ListHndl)); 
  int i = 0;
  while(i<n){
    ListHndl list;           
	list = NULL;
	list = newList();
	tempGraph->adjList[i] = list;
	i++;
  }	
 int j = 0;
 while(j<n){
   tempGraph->distances[j] = -1;
   j++;
 }
  return(tempGraph);
}  

void addEdge(Graph G, int from, int to){
  insertAtBack((G->adjList[from]), to);
}

void freeGraph(Graph *G){
/*   assert ((*G) != NULL && G != NULL); 
  Graph tmp = *G;
  
  free (tmp->parents);
  free (tmp->colors);
  free (tmp->distances);
  
  int i = 0;
  for(i = 0; i<tmp->size; i++){
    freeList(&(tmp->adjList[i]));
  }
  free (tmp->adjList);
  free (*G);
  *G = NULL; */
}

/* 0== white, 1==grey 2==black*/
void doBFS(Graph G, int source){
  ListHndl queue;           
  queue = NULL;
  queue = newList();
  
  int i=0;
  for(i=0;i<(G->size);i++){
    G->colors[i] = 0;
  }
  G->colors[source] = 1;
  G->distances[source] = 0;
  insertAtBack(queue, source);

  while(!isEmpty(queue)){
    int u = getFirst(queue);
	while(!offEnd(G->adjList[u])){
	  int v = getCurrent((G->adjList[u]));
	  if((G->colors[v]) == 0){
	    G->distances[v] = G->distances[u]+1;
		G->parents[v] = u;
	    insertAtBack(queue,v);
	    G->colors[v] = 1;
      }
	  moveNext(G->adjList[u]);
	}
	G->colors[u] = 2;
    deleteFirst(queue);
  }
}


int getDistance(Graph G, int destination){
  /*if there is no path return -1*/
  int dist = G->distances[destination];
  return (dist);
}

ListHndl getPathTo(Graph G, int destination){
  ListHndl path;
  path = NULL;
  path = newList();
  int dist = G->distances[destination];
  if(dist==-1){
    return NULL;
  }
  insertAtBack(path, destination);
  int parent = G->parents[destination];
  while(dist>0){
    insertAtFront(path, parent);
	dist = G->distances[parent];
	parent = G->parents[parent];
  }
  
  return path;
}
  