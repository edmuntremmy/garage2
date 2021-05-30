#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(move, normal)
{
    text txt = create_text();
    txt->lines->push_back("Line 0\n");
    txt->lines->push_back("Line 1\n");
    txt->lines->push_back("Line 2\n");
    txt->lines->push_back("Line 3\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    m(txt, 0, 0);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);

    m(txt, 1, 5);
    EXPECT_EQ(txt->cursor->line_num, 1);
    EXPECT_EQ(txt->cursor->position, 5);

    free(txt);
}

TEST(move, going_out_of_bounds)
{
    text txt = create_text();
    txt->lines->push_back("Line 0\n");
    txt->lines->push_back("Line 1\n");
    txt->lines->push_back("Line 2\n");
    txt->lines->push_back("Line 3\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    m(txt, 0, 100);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);

    m(txt, 100, 0);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);

    m(txt, 100, 100);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);

    free(txt);
}
