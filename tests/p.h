#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(add_line_after, normal)
{
    text txt = create_text();
    txt->lines->push_back("Line 0\n");
    txt->lines->push_back("Line 1\n");
    txt->lines->push_back("Line 2\n");
    txt->lines->push_back("Line 3\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    add_line_after(txt, 2, "New line 2\n");

    string* txt_arr = new string[txt->lines->size()];
    copy(txt->lines->begin(), txt->lines->end(), txt_arr);

    EXPECT_EQ(txt->lines->size(), 5);
    EXPECT_STREQ(txt_arr[0].c_str(), "Line 0\n");
    EXPECT_STREQ(txt_arr[1].c_str(), "Line 1\n");
    EXPECT_STREQ(txt_arr[2].c_str(), "Line 2\n");
    EXPECT_STREQ(txt_arr[3].c_str(), "New line 2\n");
    EXPECT_STREQ(txt_arr[4].c_str(), "Line 3\n");

    free(txt);
}

TEST(add_line_after, empty_text)
{
    text txt = create_text();
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    add_line_after(txt, 0, "New line 0\n");

    string* txt_arr = new string[txt->lines->size()];
    copy(txt->lines->begin(), txt->lines->end(), txt_arr);

    EXPECT_EQ(txt->lines->size(), 1);
    EXPECT_STREQ(txt_arr[0].c_str(), "New line 0\n");

    free(txt);
}
