/**
 * move_cursor.c -- реализует обобщенную функцию обработки текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "text/_text.h"

void move_cursor(text txt)
{
    if(txt->cursor->line->next!=NULL)
    {
	txt->cursor->line=txt->cursor->line->next;
	txt->cursor->position=0;
    }	
}

