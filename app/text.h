#ifndef TEXT_H
#define TEXT_H

#define MAXLINE 255

#include <string>

/**
 * Коды возврата для функций библиотеки text
 */
#define SUCCESS 0
#define FAILED_NO_LINE 1

using namespace std;

typedef struct _list *text;
/**
 * Абстрактный тип курсора
 */
typedef struct _crsr *cursor;


/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text();

/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(text txt, string contents);


/**
 * Обрабатывает текст, применяя заданную функцию к каждой строке
 *
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_forward(
    text txt,
    void (*process)(int index, char *contents, int cursor_position, void *data),
    void *data
);

/**
 * Обрабатывает список, применяя заданную функцию к каждой строке
 *
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_backward(
    text txt,
    void (*process)(int index, char *contents, int cursor_position, void *data),
    void *data
);


/**
 * Удаляет весь текст
 *
 * @param txt текст
 * @returns none
 */
void remove_all(text txt);

/**
 * Перемещаем курсор в заданную позицию
 * @param txt текст
 * @param line_num номер строки
 * @param cursor_pos номер позиции в строке
 * @returns код исполнения
 */
int m(text txt, int line_num, int cursor_pos);

/**
 * Перемещаем курсор в заданную позицию
 * @param txt текст
 * @returns код исполнения
 */
int move_next_line_begin(text txt);

/**
 * Добавляет одну строку к тексту после строки с указанным номером
 * @param txt текст
 * @param line_number номер строки, после которой нужно вставить новую строку
 * @param contents текст новой строки
 * @returns статус
 */
int add_line_after(text txt, int line_number, string to_add);

#endif
