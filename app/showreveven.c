/**
 * showreveven.c -- реализует команду  вывода четных строк в обратном порядке
 *
 * Copyright (c) 2017, Mamedovi Guseyn <mamedovi@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"


static void show_rline(int index, char *contents);

void showreveven(text txt)
{
    /* Применяем функцию show_rline к каждой строке текста, но в обратном порядке следования */
    reversed_process_forward(txt, show_rline);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_rline(int index, char *contents)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемый параметр */
    UNUSED(index);
    /* Выводим строку на экран только четную строку */
    if(!(index&1))
    printf("%s", contents);
}

