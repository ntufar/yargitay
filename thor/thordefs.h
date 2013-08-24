/*****************
 *  Thor editor project
 *  data types file
 *  types.h
 *****************/

#ifndef _TYPES_H__NTBD
#define _TYPES_H__NTBD
#include <curses.h>

/* Datatypes: */
struct line_struct {
	char text[80];
	struct line_struct *prev;
	struct line_struct *next;
};

typedef struct line_struct line;

struct paragraph_struct {
	line *lines;	/* pointer to the first line of linked list */
	int linesnum;
	struct paragraph_struct *prev;
	struct paragraph_struct *next;
};

typedef struct paragraph_struct paragraph;

/* Global variables: */
extern	paragraph *Text;
extern	int	Curpar;
extern	int	Curline;
extern	int	Curpos;
extern	int	Upperline;	/* The upper line in the window */
extern	long	Textlines;	/* Number of lines in text */


/***************/
/* Interfaces: */
/***************/

/* Text manipulation: */
char *getline(long linenumber);
int insert(int c);
int delete();
int inittext();

/* Video: */

/* Direcorty: */
char *getfile(WINDOW*, WINDOW*);


#endif  /*_TYPES_H__NTBD*/
