/*
 * Line functions header file
 */

#ifndef _LINE_H_NTBD
#define _LINE_H_NTBD

#include <thordefs.h>

line* create_line( char* value );
line* append_line( line* cur, line* l );
line* insert_line( line* cur, line* l );
line* delete_line( line* l );
line* text2lines( char* text );
char* lines2text( line* l );
int line_number( line* l );

#endif /* _LINE_H_NTBD */
