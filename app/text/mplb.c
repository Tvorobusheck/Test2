/**
 * mplb.c -- переводит курсор на начало предыдущей строки
 *
 * Copyright (c) 2017, Vlad Markov <markov@petrsu.ru>
 *
 * This code is licensed under a MIT-stile license.
 */
#include <stdio.h>
#include <assert.h>
#include "text.h"
#include "_text.h"

void mplb(text txt)
{
	/* Меняем позицию курсора на начало пердыдущей строки */
	if(txt->cursor->line->previous != NULL)
	{
		txt->cursor->line = txt->cursor->line->previous;
		txt->cursor->position = 0;
	}
	else
		fprintf(stderr,"Function cannot called\n");
}
