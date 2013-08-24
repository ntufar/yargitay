/*
 * Paragraph functions
 *
 */

#ifndef _PARAGRAPH_H_NTBD
#define _PARAGRAPH_H_NTBD

#include <thordefs.h>

paragraph* create_paragraph();	/* Creates paragraph with 0 lines */
paragraph* append_paragraph( paragraph* cur, paragraph* p );
paragraph* insert_paragraph( paragraph* cur, paragraph* p );
paragraph* delete_paragraph( paragraph* p );
paragraph* text2paragraphs( char* text );
void dump_paragraphs( paragraph* p );

#endif /* _PARAGRAPH_H_NTBD */
