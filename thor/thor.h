/*******************************************************************
 *                                Thor Editor
 *    main include file - thor.h    
 *    here we declare what people from outside shoud know
 *    about Thor
 *******************************************************************/

#ifndef _THOR_H_
#define _THOR_H_

int initthor(int,int,int,int);	/* in vi/vi.c initializes the video system */
int shutthor();	/* in vi/vi.c shuts down the video system */
int edit(int);	/* in vi/vi.c the main engine */
int repaintthor();	/* in vi/vi.c */
int thorreadfile(char*);	/* int text/text.c */
char **initfilelist(char*);	/* in dir/dir.c */
int thorsetloft(char*);		/* in vi/vi.c */
extern int Totalfiles;		/* in vi/dir.c */

#endif
