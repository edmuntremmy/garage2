#include <iostream>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text.h"

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран в обратном порядке,
 * нечётные строки игнорируются
 */

void showreveven(text txt)
{
    /* Применяем функцию к каждой строке текста */
    process_backward(txt, show_line, NULL);
}

static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик получает строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(data);
    UNUSED(cursor);

    if(index % 2 == 0) {
        /* Выводим строку на экран */
        std::cout << contents;
    }
}
