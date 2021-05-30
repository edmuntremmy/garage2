/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include <assert.h>
#include "common.h"
#include "text.h"

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */

void show(text txt)
{
    /* Применяем функцию к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/**
 * Отображает содержимое указанного файла на экран
 */

static void show_line(int index, char* contents, int cursor, void *data)
{
    /* Объявляем используемые переменные */
    int i;
    char line[MAXLINE + 2];
    /* Функция обработчик всегда получает существующую строку */

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);

    /* Проверяем положение курсора */
    if (cursor > -1) {
    	/* Копируем первую часть строки */
    	for (i = 0; i < cursor; i++) {
    	    if (contents[i] == '\n')
    		break;
    	    line[i] = contents[i];
    	}
    	line[i++] = '|';
    	/* Копируем вторую часть строки */
    	for (; contents[i-1] != '\0'; i++)
    	    line[i] = contents[i-1];
    	line[i] = '\0';
    	/* Выводим строку на экран */
        std::cout << line;
    } else {
        /* Выводим строку на экран */
        std::cout << contents;
    }
}
