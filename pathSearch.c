/* By Patrick Russell  and  Niko Williams
 *    pcrussel@ucsc.edu ||  nijowill@ucsc.edu 
 *
 * NAME: pathSearch.c
 *
 * PURPOSE: Recieve a file, build a graph from said file, and then
 *          find the shortest path between 2 nodes.
 *
 * USAGE: pathSearch [Filename]
 *        File must be formatted as:
 *           - 1st number = number of verticies [EX: 5]
 *           - 2nd number = number of search requests [EX: 2]
 *           - The verts of the graph and its connections[EX: 0 1 3]
 *           - The route requests between verts[EX: 0 4]
 *
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>

int main(int argc, char **argv) {
   if(argc < 2 || argc > 2){
      printf("pathSearch usage: pathSearch FILENAME1\n");
      printf("FILENAME1 contains:\n *size of graph to be made\n");
      printf(" *number of requests\n");
      printf(" *a node number followed by its edges\n");
      printf(" *a search request to go from one node to another\n");
      return 0;
   }

   int size = 0;
   int requests = 0;
   int tmp = 0;
   int index = 0;
   int vert = 0;
   char line[1024], *beg, *end;
   long readvalue = 0;
   
   /*open the file*/
   FILE *input;
   input = fopen(argv[1], "r");
   
   /*read in the size*/
   if(fscanf(input, "%d", &tmp) != NULL){
      size = tmp;
   }else{
      printf("ERROR: first item of file wasn't a number\n");
      return 0;
   }
	
	/*read in the request numbers*/
	if(fscanf(input, "%d", &tmp) != NULL){
       requests = tmp;
    }else{
       printf("ERROR: second item of file wasn't a number\n");
       return 0;
    }
	
   /*build graph*/
   for(index = 0; index < size; index++){
      /*get a whole line*/
      while (fgets(line, sizeof(line), input)) {
         beg = line;
		 /*read in the numbers one at a time until line ends*/
         for (beg = line; ; beg = end) {
            readvalue = strtol(beg, &end, 10);
            if (beg == end){
			   /*this is where it knows that the line ends*/
               printf("\n");
			   break;
            }
            printf("[%d]", readvalue);
		 }
      }
      
   }
   printf("size = %d\n", size);
   printf("requests = %d\n", requests);
   return 0;
}