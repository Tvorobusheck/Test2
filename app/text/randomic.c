/**
 *randomic.c -- вставка новой строки перед предыдущей
 *
 * Copyright (c) 2017, Gorbunova Daria <gorbunovov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */
#include <stdio.h>
#include "text.h"
#include "_text.h"
#include <string.h>

void randomic(text txt) {

    /* Сохраняем позицию курсора */
    //int old_pos = txt->cursor->position;
    //node* old_line = txt->cursor->line;
    //node* previous_line = txt->cursor->line->previous;

    /* Сохраняем позицию последней строки */
    node* penultimate = txt->end;

    /* Переносим текущую строку в уонец файла*/

    txt->cursor->line->previous->next = txt->cursor->line->next;
    txt->cursor->line->next->previous = txt->cursor->line->previous;


    penultimate->next = txt->cursor->line;
    txt->end = txt->cursor->line;
    txt->cursor->line->previous = penultimate;
    txt->cursor->line->next = NULL;
    /* Возвращаем курсор на место*/
    /* txt->cursor->line = old_line;
       txt->cursor->position = old_pos;*/
}

