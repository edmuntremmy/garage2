#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include <iostream>
#include <sstream>

#include "common.h"
#include "text.h"
#include "_text.h"


TEST(showreveven_content, multiple_lines)
{
    text txt = create_text();
    txt->lines->push_back("Line 0\n");
    txt->lines->push_back("Line 1\n");
    txt->lines->push_back("Line 2\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    testing::internal::CaptureStdout();

    showreveven(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), "Line 2\nLine 0\n");

    free(txt);
}

TEST(showreveven_content, one_line)
{
    text txt = create_text();
    txt->lines->push_back("Line 0\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    testing::internal::CaptureStdout();

    showreveven(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), "Line 0\n");

    free(txt);
}

TEST(showreveven_content, no_lines)
{
    text txt = create_text();
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    testing::internal::CaptureStdout();

    showreveven(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_EQ(text.length(), 0);

    free(txt);
}
