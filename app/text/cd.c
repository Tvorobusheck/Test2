//cd.c- программа для перемещения строки с курсором в начало текста.
//Copyright (c) 2017, Denis Shvidko <shvidko@cs.karelia.ru>



#include "_text.h"

void cd(text txt)
{   printf("1\n");
    txt->cursor->line->previous->next=txt->cursor->line->next;
    printf("2\n");
    txt->cursor->line->previous=NULL;
    printf("3\n");
    txt->cursor->line->next=txt->begin;
    printf("4\n");
    txt->begin=txt->cursor->line;
}
