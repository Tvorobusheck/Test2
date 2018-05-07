/**
 * pp.c -- вставка новой строки перед предыдущей
 *
 * Copyright (c) 2017,  Vlad Markov <markov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */
#include <stdio.h>
#include "text.h"
#include "_text.h"
#include <string.h>

void pp(text txt, char *new_str) {
    char line[MAXLINE + 1];
    strncpy(line, new_str, MAXLINE);
    strncat(line, "\n", MAXLINE - strlen(line));
    
    /* Сохраняем позицию курсора */
    int old_pos = txt->cursor->position;
    node* old_line = txt->cursor->line;
    node* previous_line = txt->cursor->line->previous;

    /* Сохраняем позицию последней строки */
    node* penultimate = txt->end;

    /* Добавляем новую строку*/
    append_line(txt, line);

    /* Ставим новую строку между предыдущей и текущей */
    if(txt->begin == old_line){
	txt->end->next = txt->begin;
	txt->begin->previous = txt->end;
	txt->begin = txt->end;
	txt->begin->previous = NULL;

	txt->end = penultimate;
	txt->end->next = NULL;
    }
    else{
	previous_line->next = txt->cursor->line;
	txt->cursor->line->next = old_line;
	txt->cursor->line->previous = previous_line;
	old_line->previous = txt->cursor->line;

	txt->end = penultimate;
	txt->end->next = NULL;
    }

    /* Возвращаем курсор на место*/
    txt->cursor->line = old_line;
    txt->cursor->position = old_pos;
}
