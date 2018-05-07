/**
 * showlastnonspace.c -- программа для вывода последнего символа в 
 * строке, который не является пробелом"
 *
 * Copyright (c) 2017, Denis Shvidko <shvidko@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void show_last_nonspace (int index, char *text);

void
showlastnonspace (text txt)
{
  process_forward (txt, show_last_nonspace);
}

static void
show_last_nonspace (int index, char *text)
{
  assert (text != NULL);
  UNUSED (index);
  int c = strlen (text) - 2;
  if (text[c] != ' ')
    printf ("%c\n", text[c]);
}
