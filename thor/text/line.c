/*******************************/
/* Line manipulation functions */
/*******************************/

#include <thordefs.h>
#include <stdio.h>
#include "line.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*---------------------------------------------------------------------------*/
line* create_line( char* value ) {
	line* new_line;
	
	new_line = (line*)malloc( sizeof( line ) );
	if ( !new_line )
		return 0;
	strncpy( new_line->text, value, 80 );
	new_line->text[79] = 0;
	
	new_line->prev = 0;
	new_line->next = 0;
	
	return new_line;	
}

/*---------------------------------------------------------------------------*/
line* append_line( line* cur, line* l ) {
	line* last = cur;
	
	if ( !cur )	/* Line list is empty */
		return l;

	/* Find the last line */
	while ( last->next )
		last = last->next;
		
	last->next = l;
	l->prev = last;
	l->next = 0;
	
	return l;
}

/*---------------------------------------------------------------------------*/
line* insert_line( line* cur, line* l ) {
	if ( !cur )	/* Line list is empty */
		return l;

	l->next = cur->next;
	l->prev = cur;
	cur->next = l;
	if ( l->next )
		l->next->prev = l;
	
	return l;
}

/*---------------------------------------------------------------------------*/
line* delete_line( line* l ) {
	line* prev = l->prev;
	line* next = l->next;
	
	free( l );
	
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

/*---------------------------------------------------------------------------*/
line* text2lines_old( char* text ) { /* an old version */
/* Just a simple implementation waiting for improvements! */
	int len;
	int i;
	char* b;
	char* b1;
	char* s;
	line* res = 0;
	int c;
	char* dup;
	
	if ( !(*text) ) { /* Line is empty */
		return create_line("");
	}

	dup = strdup( text );
	s = dup;
	
	while ( *s ) {
		len = strlen( s );
		if ( len < 77 ) {
			res = append_line( res, create_line( s ) );
			break;
		}			
		b = s + 78;
		if ( *b!=' ' ) {
			c = *b;
			*b = 0;
			b1 = strrchr( s, ' ' );
			*b = c;
			
			if ( !b1 ) { /* it's a one long word */
				c = *(b-1);
				*(b-1) = 0;
				res = append_line( res, create_line( s ) );
				/* strcat( res->text, "-" ); */
				*(b-1) = c;
				s = b-1;
				continue;
			}
			
			c=*(b1+1);
			
			*(b1+1) = 0;
			res = append_line( res, create_line( s ) );
			*(b1+1) = c;
			s = b1+1;
			continue;
		}
		c = *(b+1);
		*(b+1) = 0;
		res = append_line( res, create_line( s ) );
		*(b+1) = c;
		s = b+1;
	}
	
	while ( res->prev )
		res = res->prev;
		
	free( dup );
		
	return res;
}

/*---------------------------------------------------------------------------*/
static char* strip(char* str) {
	char* b = str+strlen(str)-1;
	
	while ( b>=str && *b==' ' ) {
		*b=0;
		b--;
	}
	
	return str;
}

/*---------------------------------------------------------------------------*/
line* text2lines( char* text ) {
	char* dup = strdup( text );
	line* res = 0;
	char* s;
	char* b;
	char* b1;
	
	char buf[80];
	
	s = dup;
	
	while( 1 ) {	/* Up to the end of line */
	
		bzero( buf, 80 );
		strncpy( buf, s, 78 );

/* Last line */
		if ( buf[77]==0) { /* last line */
			res = append_line( res, create_line(buf) );
			break;
		}
	
/* Wrapping at word */
		if ( buf[77]!=' ' ) {	/* wrapping a word */
			b = strrchr( buf, ' ' );	/* Find the lasy space */
			
			if ( !b ) { /* long word */
				res = append_line( res, create_line(buf) );
				s+=78;
				continue;
			}
			
			s += (78-(strlen(b)-1));	/* Set new pointer to the beginning of the word */
			*b = 0;
			strip( buf );
			if ( strlen(buf) )
				strcat(buf, " ");
			
			res = append_line( res, create_line(buf) );
			continue;
		}

/* Wrapping at space */
		b = buf+76;

		strip( buf );
		if ( strlen(buf) )
			strcat(buf, " ");

		res = append_line( res, create_line(buf) );
		s+=78;
	}
	
	while ( res->prev )
		res = res->prev;
		
	free(dup);
	return res;
}

/*---------------------------------------------------------------------------*/
char* lines2text( line* l ) {
	int len=0;
	line* cur = l;
	char* buffer;
	
	while ( cur ) {
		len += strlen( cur->text );
		cur = cur->next;
	}
	
	cur = l;
	buffer = (char*)malloc( len+1 );
	if ( !buffer )
		return 0;
		
	*buffer = 0;
	
	while ( cur ) {
		strcat( buffer, cur->text );
		cur = cur->next;
	}
	
	return buffer;
}

/*---------------------------------------------------------------------------*/
int line_number( line* l ) {
	int i = 0;
	
	while ( l ) {
		l = l->next;
		i++;
	}
	
	return i;
}
