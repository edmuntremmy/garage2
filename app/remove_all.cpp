#include "_text.h"

/**
 * Удаляет весь текст
 *
 * @param txt текст
 * @returns none
 */

void remove_all(text txt)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL) {
        fprintf(stderr, "The text doesn't exist!\n");
        return;
    }

    /* Если список изначально пуст, делать ничего не надо */
    if (txt->lines->size() == 0) {
        return;
    }

    txt->lines->erase(txt->lines->begin(), txt->lines->end());
    txt->cursor->position = 0;
    txt->cursor->line_num = 0;
}
