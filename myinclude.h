/*
* Nico Williams 
* nijowill
* 4/18/2014
*
* Samuel Reha
* sreha
* 4/18/2014
*  
* This .h file was created by Professor D. Hembold
* It was modified by Nico Williams and Samuel Reha
* Spring 2014 for use in asg2, and by Nico Williams
* and Joseph Rogers for use in asg2 05/02/2014. 
*/


#include        <stdio.h>
#include        <strings.h>
#include        <string.h>
#include        <stdlib.h>   /* this includes malloc, free, rand, etc. */
#include        <assert.h>

#define EQ ==
#define NEQ !=
#define LEQ <=
#define GEQ >=
/* I try to use these in boolean expressions.  One of the problems with C */
/* is that "(x = y)" when you mean "(x == y)" is almost always is true    */
/* AND also assigns the value of y to x.  Since this is almost impossible */
/* to debug, I try to use the above abbreviations for comparison operators. */

#define AND &&
#define OR ||

#define streq(s, t) (! strcmp(s, t))
#define strneq(s, t) (strcmp(s, t))

typedef int     Boolean;
#define TRUE 1
#define FALSE 0
/* these three things give me a "poor man's" boolean type */
/* with constants TRUE and FALSE */

typedef char *  String;
typedef FILE *  FilePtr;
/* these are two other commonly used types. */

