/**
 * paste.c -- реализует команду вставки строки после заданной позиции
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include "text/_text.h"

static node *create_node(const char *contents);

void paste(text txt,int num, char*t)
{
    node *current = txt->begin;
    int index = 1;
    
    /* проходим по связному списку ищем нужную строку */
    while (current) {
	//заданная позиция совпадает с заданной
	if(index==num)
	{
	    current->next->previous=create_node(t);
	    current->next->previous->next=current->next;
	    current->next=current->next->previous;
	    current->next->previous=current;
	    break;
	}
	current=current->next;
	index++;
    }
}
 static node *create_node(const char *contents)
{  
    assert(contents != NULL);
    
    node *nd;

    if ((nd = (node *) malloc(sizeof(node))) == NULL) {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }
    if (strlen(contents) > MAXLINE) {
        fprintf(stderr, "Too long line!\n");
        exit(EXIT_FAILURE);
    }    

    strncpy(nd->contents, contents, MAXLINE);
    nd->contents[strlen(contents)]='\n';
    nd->contents[MAXLINE] = '\0';
    nd->previous = NULL;
    nd->next = NULL;   
    
    return nd;
}



 
