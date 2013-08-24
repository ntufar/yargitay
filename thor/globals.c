/*************************
 * Thor editor
 *  globals variables
 *  globals.c
 **************************/
#include "thordefs.h"

/* Global variables: */
paragraph *Text = NULL;
int     Curpar = 0;
int     Curline	= 0;
int     Curpos = 0;
int     Upperline = 0;      /* The upper line in the window */
long    Textlines = 0;      /* Number of lines in text */

