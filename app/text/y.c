/**
 * y.c --для замены строки от курсора и до конца заданной строкой y
 строка с контролем переполнения
 *
 * Copyright (c) 2017, Daria Gorbunova <gorbunov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */
#include <stdio.h>
#include <assert.h>
#include "_text.h"
#include <string.h>
#include "text.h"



void y(text txt,char *arg)
{
    unsigned int c;
    /*Считаем длину строки от а до конца строки*/
    c = MAXLINE  - pos_return(txt);
    /*Сравниваем длины срок y и contents и ставим y на место contents */
    if (strlen(arg) < c) {
	strcpy(txt->cursor->line->contents+pos_return(txt),arg);
    } else {
	printf("Замена невозможна\n");
    }
   
}

