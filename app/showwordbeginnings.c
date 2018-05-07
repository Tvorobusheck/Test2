/**
 * showwordbeginnings.c -- реализует вывод буквенных символов 
каждой строки, которым предшествует пробельный символ или начало 
строки
 *
 * Copyright (c) 2017, Daria Gorbunova <gorbunov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */
#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include <string.h>
#include <ctype.h>
/**
 * Выводит содержимое указанного файла на экран
 */
void show_word_beginnings(int j, char *contents) {
    int i;
    /* Функция обработчик получает существующую строку */
    assert(contents != NULL);
    /* Определяем количество символов в строке*/
    j= strlen(contents);
    for(i=0;i<=j-1;i++){
	if (contents[i]==' ' && isalpha(contents[i+1]))
	    printf("%c", contents[i+1]);
	if (i==0 && isalpha(contents[i]))
	    printf("%c", contents[i]);
    }
    printf("\n");
}
void showwordbeginnings(text txt) {
    /* Применяем функцию show_word_beginnings к каждой строке 
текста */
    process_forward(txt,show_word_beginnings);
}
