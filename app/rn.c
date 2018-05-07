/**
 * rn.c - удаляет следующую строку, если возможно
 *
 * Copyright (c) 2017, Artem Zaicev <zaicev@cs.karelia.ru>
 *
 * This code licensed under a MIT-style license
 */

#include <stdio.h>
#include "common.h"
#include "text/text.h"

void rn(text txt)
{
    if (tracer(txt, currentline(txt) + 1) != NULL)
	delete_line(txt, currentline(txt) + 1);
    else
	fprintf (stderr, "Cursor on the last line\n");
}
