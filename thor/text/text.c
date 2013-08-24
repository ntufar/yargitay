/*******************************/
/* Text manipulation functions */
/*******************************/

#include <thordefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
#include "line.h"
#include "paragraph.h"

char dummy_buffer[10000];

/*------------------------------------*/
static int dos2iso(c)
	int c;
{
	unsigned char x;

	x = (unsigned char)c;
	if(x == (unsigned char)'˜') x = 'İ';
	else if(x == (unsigned char)'¦') x = 'Ğ';
	else if(x == (unsigned char)'') x = 'Ş';
	else if(x == (unsigned char)'™') x = 'Ö';
	else if(x == (unsigned char)'€') x = 'Ç';
	else if(x == (unsigned char)'š') x = 'Ü';
	else if(x == (unsigned char)'”') x = 'ö';
	else if(x == (unsigned char)'') x = 'ü';
	else if(x == (unsigned char)'‡') x = 'ç';
	else if(x == (unsigned char)'§') x = 'ğ';
	else if(x == (unsigned char)'') x = 'ı';
	else if(x == (unsigned char)'Ÿ') x = 'ş';
	
	return (int)x;
}
/*------------------------------------*/
/*---------------------------------------------------------------------------*/
/* External variables */
line* current_line;
paragraph* current_paragraph;

/*---------------------------------------------------------------------------*/
/* count_lines: counts total number of lines in the Text */
long count_lines() {
	paragraph* cur_par = Text;
	long number=0;
	
	while( cur_par ) {
		number += (long)line_number( cur_par->lines );
		cur_par = cur_par->next;
	}

	return number;
}

/*---------------------------------------------------------------------------*/
/* readfile: reads the text from file
 */

int thorreadfile(filename)
	char *filename;
{
	paragraph *curpar;
	paragraph *nextpar;
	FILE *inf;
	char buf[1024*10];
	int i;
	
	inf = fopen(filename, "r");
	if(inf == NULL)return 0;

	if(Text != NULL){
		curpar = Text;
		while(curpar->next != 0){
			nextpar = curpar;
			curpar = curpar->next;
			delete_paragraph(nextpar);
		}
	}
	Text = create_paragraph();

	
/*	Text->lines = text2lines("");

	while (!feof(inf)){
		fgets(buf, 1024 * 10, inf);
		if(feof(inf))break;
		curpar = append_paragraph( Text, create_paragraph() );
		curpar->lines = text2lines( buf );
	}
	fclose(inf);
*/

/* -- The real core stars here :) -------------------- */
	Text = 0;
	while (!feof(inf)){
		fgets(buf, 1024, inf);
		for(i=0;buf[i];i++){
			if(buf[i]=='\n' || buf[i]=='\r'){
				buf[i]=0;
				break;
			}
			buf[i]=dos2iso(buf[i]);
		}
		if(feof(inf))break;
		Text = append_paragraph( Text, create_paragraph() );
		Text->lines = text2lines( buf );
	}

	while( Text->prev )
		Text=Text->prev;

	fclose(inf);
		
	Textlines = count_lines();
	return 1;
	
}


/*---------------------------------------------------------------------------*/
/* inittext: initialises the Text */
int inittext() {
	int i, t;
	paragraph* cur_par;
	char buf[256];

	if(Text != NULL)return 0;
	Text = create_paragraph();
	
	Text->lines = text2lines("\
This is a first paragraph. It it designed to be long. That it to contain \
several lines of text. I believe these should be on the second line. And now \
let's add a third line! Wow, we did it!");

	append_line(Text->lines, create_line(" "));
	append_line(Text->lines, create_line(" "));
	append_line(Text->lines, create_line(" "));

	for ( i=0; i<100; i++ ) {
		cur_par = append_paragraph( Text, create_paragraph() );
		sprintf( buf, "Paragraph number %d", i );
		strcpy( dummy_buffer, buf );
		for ( t=0; t<50; t++)
			strcat(dummy_buffer, buf);
		cur_par->lines = text2lines( dummy_buffer );
	}
	Textlines = count_lines();
	return 1;
}

/*---------------------------------------------------------------------------*/
char *getline( long linenumber ) {
	paragraph* cur_par = Text;
	line* cur_line = cur_par->lines;

	while( linenumber ) {
		cur_line = cur_line->next;
		if ( !cur_line ) {
			cur_par = cur_par->next;
			cur_line = cur_par->lines;
		}
		linenumber--;
	}
	return cur_line->text;	
	/* It doesn't return anything! */
}

/*---------------------------------------------------------------------------*/
/* getlineinfo */
/* Gets information about the line and sets variables to their respective */
/* values. */
void getlineinfo( long linenumber ) {
	paragraph* cur_par = Text;
	line* cur_line = cur_par->lines;

	while( linenumber ) {
		cur_line = cur_line->next;
		if ( !cur_line ) {
			cur_par = cur_par->next;
			cur_line = cur_par->lines;
		}
		linenumber--;
	}
	
	current_line = cur_line;
	current_paragraph = cur_par;
	
	/* It doesn't return anything! */
}

/*---------------------------------------------------------------------------*/
paragraph* reformat_paragraph( paragraph* p ) {
	char* buf;
	line* l;

	buf = lines2text( p->lines );
	l = p->lines;
	while ( l=delete_line(l) );
	p->lines = text2lines( buf );
	free(buf);
	
	return p;
}

/*---------------------------------------------------------------------------*/
int insert(int c) {
	char sb[2]=" ";
	char* buf;
	line* l;
	int i;
	int last_line = 0;
	paragraph* p;

	getlineinfo( Curline );
	/* Current paragraph is now in 'current_paragraph' and current line is */
	/* in 'current_line' */
	
	if ( !current_line->next )
		last_line = 1;
	i = strlen( current_line->text );

	switch ( c ) {
		case '\n':	/* Add a new paragraph! */
/* beginning of paragraph */
			if ( !current_line->prev )	{
				if ( current_paragraph==Text ) { /* first paragraph */
					Text = create_paragraph();
					Text->lines = create_line("* A new line!!! *");
					Text->next = current_paragraph;
					current_paragraph->prev = Text;
					
					reformat_paragraph(Text);
					Textlines = count_lines();
					
					Curline++;
					break;
				}
				
				p = insert_paragraph(current_paragraph->prev, create_paragraph());
				p->lines = create_line("* A new line *");
				
				reformat_paragraph(p);
				Textlines = count_lines();

				Curline++;
				break;
			}
			
			break;	/* Up to here so far*/
			
			if ( i<Curpos ) {
				current_paragraph->lines=create_line("");
			} else {
				current_paragraph->lines=create_line( current_line->text+Curpos);
				current_line->text[Curpos] = 0;
				
				current_paragraph->lines->next = current_line->next;
				current_line->next->prev = current_paragraph->lines;
				current_line->next = 0;
			}

			Curline++;
			Curpos=0;
					
			reformat_paragraph( current_paragraph->prev );
			reformat_paragraph( current_paragraph );
			Textlines = count_lines();
			
			break;
			
		case '\t':
			i=Curpos%8;
			if ( i==0 )
				i = 8;
			while( i-- )
				insert( ' ' );
			break;
		default:	/* Default behavior is to add a symbol to the paragraph text */
			if ( i<Curpos ) {
				i = Curpos - i;
				buf = malloc( i+2 );
				memset( buf, ' ', i );
				buf[i]=c;
				buf[i+1]=0;
				insert_line( current_line, create_line(buf) );
				free(buf);
				
				goto recompile_the_text;
			}
			
			insert_line(current_line, create_line( current_line->text+Curpos ));
			current_line->text[Curpos] = c;
			current_line->text[Curpos+1] = 0;

recompile_the_text:
			reformat_paragraph( current_paragraph );

			Textlines = count_lines();
			Curpos++;
			if ( Curpos>78 ) {
				if ( last_line ) {
					l = current_paragraph->lines;
					while ( l->next )
						l = l->next;
					if ( strlen( l->text ) >78 )
						append_line(current_paragraph->lines, create_line("") );
				}
					
				Curline++;
				Curpos -= 79;
			}
	}		
	return 1;
}

/*---------------------------------------------------------------------------*/
int delete() {
	char* buf;
	line* l;
	int i;
	int last_line = 0;

	getlineinfo( Curline );
	/* Current paragraph is now in 'current_paragraph' and current line is */
	/* in 'current_line' */
	
	if ( !current_line->next )
		last_line = 1;
	i = strlen( current_line->text );

	if ( i<Curpos && last_line ) {
		current_line->next = current_paragraph->next->lines;
		current_paragraph->next->lines->prev = current_line;
		current_paragraph->next->lines = create_line("");
		delete_paragraph( current_paragraph->next );
	}

	reformat_paragraph( current_paragraph );
	Textlines = count_lines();
	
	return 1;
}
