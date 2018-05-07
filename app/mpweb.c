/**
 * mpweb.c -- программа для перемещения курсора
 * в конец предыдущего слова
 *
 * Copyright (c) 2017, Artem Zaicev <zaicev@cs.karelia.ru>
 *
 * This code licensed under a MIT-style license
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "text/text.h"
#include "common.h"


//проверяет, является ли символ пробельным разделителем
bool is_sep(char c);

//по возможности перемещаем курсор в конец
//предыдущего слова
void mpweb(text txt)
{
    int crsr_pos = pos_return(txt);
    int crsr_line  = currentline(txt);
    char* crsr_line_contents = line_contents(txt, crsr_line);

    if (crsr_line_contents == NULL){
	fprintf (stderr, "Cursor not found\n");
	return;
    }


    while (crsr_line >= 0){
	while (crsr_pos > 0){
	    if (is_sep(crsr_line_contents[crsr_pos - 1]))
		break;
	    crsr_pos--;
	}

	while (crsr_pos > 0){
	    if (!is_sep(crsr_line_contents[crsr_pos - 1])){
		c_to_pos(txt, crsr_line, crsr_pos);
		return;
	    }
	    crsr_pos--;
	}
	crsr_line--;
	if (crsr_line >= 0){
	    crsr_line_contents = line_contents(txt, crsr_line);
	    crsr_pos = strlen(crsr_line_contents);
	}
    }
    
    fprintf (stderr, "Previous word not found\n");
    c_to_pos(txt, 0, 0);
    return;
}

bool is_sep(char c)
{
    if (c == ' ' || c == '\n' || c == '\t')
	return true;
    return false;
}
	
		
		




		
