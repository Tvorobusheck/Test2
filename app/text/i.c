//i.c- вставки строки после курсора.
//Copyright (c) 2017, Denis Shvidko <shvidko@cs.karelia.ru>


#include "_text.h"

void i(text txt, char *text)
{
    int i, j, k = 0;
    node *line = txt->cursor->line;
    for (j = strlen(text) + 1; j >= 0; j--) {
	for (i = strlen(line->contents) + k; i > txt->cursor->position;
	     i--) {
	    line->contents[i] = line->contents[i - 1];
	}
	(line->contents)[txt->cursor->position] = text[j];
    }
}
