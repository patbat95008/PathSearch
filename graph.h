#include "list.h"

typedef struct graphStruct* Graph;

Graph newGraph(int n);

void addEdge(Graph G, int from, int to);

void freeGraph(Graph *G);

void doBFS(Graph G, int source);

int getDistance(Graph G, int destination);

ListHndl getPathTo(Graph G, int destination);