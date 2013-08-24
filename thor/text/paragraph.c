/************************************/
/* paragraph manipulation functions */
/************************************/

#include <thordefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "paragraph.h"


paragraph* create_paragraph() {
	paragraph* new_para;
	
	new_para = (paragraph*)malloc( sizeof( paragraph ) );
	if ( !new_para )
		return 0;
	
	new_para->prev = 0;
	new_para->next = 0;

	new_para->linesnum = 0;
	
	return new_para;	
}

paragraph* append_paragraph( paragraph* cur, paragraph* p ) {
	paragraph* last = cur;
	
	if ( !cur )	/* paragraph list is empty */
		return p;

	/* Find the last line */
	while ( last->next )
		last = last->next;
		
	last->next = p;
	p->prev = last;
	p->next = 0;
	
	return p;
}

paragraph* insert_paragraph( paragraph* cur, paragraph* p ) {
	if ( !cur )	/* Line list is empty */
		return p;

	p->next = cur->next;
	p->prev = cur;
	cur->next = p;
	p->next->prev = p;
	
	return p;
}

paragraph* delete_paragraph( paragraph* p ) {
	paragraph* prev = p->prev;
	paragraph* next = p->next;
	
	if ( p->lines ) {
		while ( p->lines ) {
			p->lines = delete_line( p->lines );
		}
	}
	
	free( p );
	
	if ( !next ) {
		if ( prev ) {
			prev->next = 0;
			return prev;
		}
		
		return 0;
	}
		
	next->prev = prev;
	if ( prev )
		prev->next = next;
	
	return next;
}

paragraph* text2paragraphs( char* text ) {
	paragraph* p = 0;
	char* s;
	char* b;
	
	if ( !text )
		return 0;

	s = text;
	
	while( s ) {
		b = strchr( s, '\n' );	/* \n ia paragraph separator */
	
		if ( b )
			*b = 0;
		
		p = append_paragraph( p, create_paragraph() );
		
		p->lines = text2lines( s );
	
		s = b ;
	}
	
	while( p->prev )
		p = p->prev;
		
	return p;
}

void dump_paragraphs( paragraph* p ) {
	int i = 0;

	while ( p ) {
		printf("*** Paragraph# %d. %d lines ***\n", i, line_number(p->lines) );
		while ( p->lines ) {
			printf("%s\n", p->lines->text );
			p->lines = p->lines->next;
		}
		p = p->next;
		i++;
	}
}
