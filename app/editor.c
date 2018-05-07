/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text/text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed> ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }
	
        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }
            /* Сохраняем в файл, заданный параметром */
	    if (strcmp(cmd, "save") == 0) {
		if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
	    if(tracer(txt, 0) != NULL)
		show(txt);
	    else
		fprintf(stderr, "No file\n");
            continue;
        }

	/* Выводим текст с нумирацией */
	if (strcmp(cmd, "shownum") == 0) {
            if(tracer(txt, 0) != NULL)
                shownum(txt);
            else
                fprintf(stderr, "No file\n");
            continue;
        }
        /* Удалить строку*/
	if (strcmp(cmd, "deleteline")== 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "No arguments\n");
            } else {
		int num;
		sscanf(arg, "%d", &num);
		if(delete_line(txt, num))
		    fprintf(stderr, "Out of lines\n");
	    }
            continue;
        }

        /* Вставляем курсор в текст */
        if (strcmp(cmd, "ctp") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "No arguments\n");
            } else {
		int line, pos;
		sscanf(arg, "%d", &line);
	       	if((arg = strtok(NULL, " \n")) == NULL)
		    fprintf(stderr, "No 2nd argument\n");
		else{
		    sscanf(arg, "%d", &pos);
		    switch(c_to_pos(txt, line, pos)){
		    case 1:
			fprintf(stderr, "Out of lines\n");
			break;
		    case 2:
			fprintf(stderr, "Out of length\n");
			break;
		    case 3:
			fprintf(stderr, "No file\n");
			break;
		    }
		}
	    }
            continue;
        }
	
	 /* Выводим текст в обратном порядке */
         if (strcmp(cmd, "showrev") == 0) {
            if(tracer(txt, 0) != NULL)
                showrev(txt);
            else
                fprintf(stderr, "No file\n");
            continue;
        }

	 /* Перемещаем курсор влево на один символ */
	 if (strcmp(cmd, "mcb") == 0) {
	     if(tracer(txt, 0) != NULL)
                mcb(txt);
            else
                fprintf(stderr, "No file\n");
            continue;
        }

	 /* Удаляем последнюю строку */
	 if (strcmp(cmd, "rt") == 0) {
	     if(tracer(txt, 0) != NULL)
                rt(txt);
            else
                fprintf(stderr, "No file\n");
            continue;
        }
	 
	/* Выводим нечётные строки текста*/
	 if (strcmp(cmd, "showodd") == 0) {
	     if(tracer(txt, 0) != NULL)
		 showodd(txt);
	     else
		 fprintf(stderr, "No file\n");
	     continue;
	 }
        /* переместить курсор в заданную позицию текущей строки*/
	if (strcmp(cmd, "mp") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "No arguments\n");
            } else {
		int cpos;
		sscanf(arg, "%d", &cpos);
		switch(r_in_cur(txt, cpos)){
		    case 1:
			fprintf(stderr, "Out of lines\n");
			break;
		    case 2:
			fprintf(stderr, "Out of length\n");
			break;
		    case 3:
			fprintf(stderr, "No file\n");
			break;
		    }
	    }
            continue;
        }
	/* совместить строку с курсором со следующей строкой */
        if (strcmp(cmd, "j") == 0){
          if(tracer(txt, 0) != NULL)
		  j(txt);
		   else
		 fprintf(stderr, "No file\n");
	     continue;
	}
	/* Выводим длину строк */
	if (strcmp(cmd, "showlengths") == 0) {
            if(tracer(txt, 0) != NULL)
                showlengths(txt);
            else
                fprintf(stderr, "No file\n");
            continue;
        }

	/* Удалить строку перед текущей */
	if(strcmp(cmd, "rp") == 0){
		if(tracer(txt, 0) != NULL)
			rp(txt);
		else
			fprintf(stderr, "No file\n");
		continue;
	}
	
        /* Переносим курсор в начало следующего слова */
        if (strcmp(cmd, "mnwbf") == 0) {
            if(tracer(txt, 0) != NULL)
                mnwbf(txt);
            else
                fprintf(stderr, "No file\n");
            continue;
        }

	
        /* Выводим текст в прямом порядке без учета пустых строк */
        if (strcmp(cmd, "shownonempty") == 0) {
            if (tracer(txt, 0) != NULL)
                shownonempty(txt);
            else
                fprintf(stderr, "No file\n");
            continue;
        }

        /* Перемещаем курсор на начало текущего слова */
        if (strcmp(cmd, "mwbb") == 0) {
            if (tracer(txt, 0) != NULL)
                mwbb(txt);
            else
                fprintf(stderr, "No file\n");
            continue;
        }

        /* Удаляем текущую строку */
        if (strcmp(cmd, "rc") == 0) {
            if (tracer(txt, 0) != NULL)
                rc(txt);
            else
                fprintf(stderr, "No file\n");
            continue;
        }
	/* Перемещение курсора вправо */
	if (strcmp(cmd, "mcf") == 0) {
	    if(tracer(txt, 0) != NULL)
		mcf(txt);
	    else
		fprintf(stderr, "No file\n");
	    continue;
	}
	
	/* Вывод строк с цифрами */
	if (strcmp(cmd, "showdigits") == 0) {
	    if(tracer(txt, 0) != NULL)
		showdigits(txt);
	    else
		fprintf(stderr, "No file\n");
	    continue;
	}
	/* Удаление первой строки */
	if (strcmp(cmd, "rh") == 0)
	{
	    if(tracer(txt, 0) != NULL)
		rh(txt);
	    else
		fprintf(stderr, "No file\n");
	    continue;
	}
	/* Меняем текущую строку со строкой y */
        if (strcmp(cmd, "ystring") == 0) {
           if(tracer(txt, 0) != NULL)
                mnwbf(txt);
            else
                fprintf(stderr, "No file\n");
            continue;
        }

        /* Переместить строку в конец файла */
        if(strcmp(cmd, "ce") == 0){
                if(tracer(txt, 0) != NULL)
                        rp(txt);
                else
                        fprintf(stderr, "No file\n");
                continue;
        }

    /* Меняем строки местами в порядке 2-1 4-3 */

    if (strcmp(cmd, "showevenbeforodd") == 0) {
        if(tracer(txt, 0) != NULL)
        showevenbeforodd(txt);
        else
        fprintf(stderr, "No file\n");
            continue;
    }
	/* Переводим курсор в начало предыдущей строки */
	if (strcmp(cmd, "mplb") == 0) {
	    if(tracer(txt, 0) != NULL)
		mplb(txt);
	    else
		fprintf(stderr, "No file\n");
 
	   continue;
	}
	  /* Вставляем новую строку перед текущей */
        if (strcmp(cmd, "pp") == 0) {
	    if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "No arguments\n");
            }
	    else{
                pp(txt, arg);
	    }
            continue;
	}
	/* Выводим текст, начиная слова с заглавных букв*/
	 if (strcmp(cmd, "showupfirst") == 0) {
	     if(tracer(txt, 0) != NULL)
		 showupfirst(txt);
	     else
		 fprintf(stderr, "No file\n");
	     continue;
	 }

	 /* Перемещаем курсор в конец текущей строки */
	 if (strcmp(cmd, "mle") == 0) {
	     if(tracer(txt, 0) != NULL)
		 mle(txt);
	     else
		 fprintf(stderr, "No file\n");
	     continue;
	 }

	 /* Удаляем первую непустую строку */
	 if (strcmp(cmd, "r1ne") == 0) {
	     if(tracer(txt, 0) != NULL)
		 r1ne(txt);
	     else
		 fprintf(stderr, "No file\n");
	     continue;
	 }

	 /* Выводим текст с заменой пробелов 
	    символами нижнего подчёркивания */
	 if (strcmp(cmd, "showunderscores") == 0){
	     if(tracer(txt, 0) != NULL)
		 showunderscores(txt);
	     else
		 fprintf(stderr, "No file\n");
	     continue;
	 }	
	 
	 /* Перемещаем курсор в конец предыдущего
	    слова, если возможно */
	 if (strcmp(cmd, "mpweb") == 0){
	     mpweb(txt);
	     continue;
	 }
	 
	 /* Удаляем следующую после строки с курсором
	    строку, если возможно */
	 if (strcmp(cmd, "rn") == 0){
	     if (tracer(txt, 0) != NULL)
		 rn(txt);
	     else
		 fprintf (stderr, "No file\n");
	     continue;
	 }

	/* Переместить строку в конец файла */
        if(strcmp(cmd, "randomic") == 0){
                if(tracer(txt, 0) != NULL)
                      randomic(txt);
                else
                        fprintf(stderr, "No file\n");
                continue;
        }
      	/* Меняем текущую строку со строкой y */
        if (strcmp(cmd, "y") == 0) {
	    if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: y string\n");
            } else {
		if(tracer(txt, 0) != NULL)
		    y(txt, arg);

		else
		    fprintf(stderr, "No file\n");
            }
            continue;
        }
         /* Выводим первые буквы слов и строк */
         if (strcmp(cmd, "showwordbeginnings") == 0) {
            if(tracer(txt, 0) != NULL)
                showwordbeginnings(txt);
            else
                fprintf(stderr, "No file\n");
            continue;
        }

	//функция вставки строки
	if(strcmp(cmd,"p") == 0){
	    if (tracer(txt, 0) == NULL){
		fprintf(stderr, "No file\n");
		continue;
	    }
	    char *arg1 = strtok(NULL, " \n");
	    char *arg2 = strtok(NULL, " \n") ;
	    int num = strtol(arg1,NULL, 10);
	    paste(txt, num, arg2);
	    continue;
	}
	//функция вывода строк с нечетными номерами в обратном порядке
	if (strcmp(cmd, "showreveven") == 0) {
	    if (tracer(txt, 0) == NULL){
		fprintf(stderr, "No file\n");
		continue;
	    }
            showreveven(txt);
            continue;
        }
	
	//функция переноса курсора в следующую строку
	if (strcmp(cmd, "mnlb") == 0) {
	    if (tracer(txt, 0) == NULL){
		fprintf(stderr, "No file\n");
		continue;
	    }
            move_cursor(txt);
            continue;
        }
	/*вставляет строку после курсора*/
	if(strcmp(cmd,"i")==0){
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: строка для вставки\n");
            } else {
                i(txt, arg);
            }
            continue;

       }
		/* Выводит последний непробельный символ строки */
	if(strcmp(cmd,"showlastnonspace")==0){
	    if(tracer(txt, 0)!=NULL)
	        showlastnonspace(txt);
	    else
		 fprintf(stderr, "No file\n");
            continue;
        }
       //перемещает строку с курсором в начало текста
	if(strcmp(cmd,"cd")==0){
	   if(tracer(txt,0)!=NULL)
		cd(txt);
	   else
                fprintf(stderr, "No file\n");
            continue;
	}

	 
	 /* Если команда не известна */
	 fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
