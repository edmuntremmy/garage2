#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(save_content, multiple_lines)
{
    text txt_inp = create_text();
    txt_inp->lines->push_back("Line 0\n");
    txt_inp->lines->push_back("Line 1\n");
    txt_inp->lines->push_back("Line 2\n");
    txt_inp->lines->push_back("Line 3\n");
    txt_inp->cursor->line_num = 0;
    txt_inp->cursor->position = 0;
    save(txt_inp, "save_content.test.txt");

    text txt_outp = create_text();
    load(txt_outp, "save_content.test.txt");

    EXPECT_EQ(txt_inp->lines->size(), txt_outp->lines->size());

    string* txt_inp_arr = new string[txt_inp->lines->size()];
    string* txt_outp_arr = new string[txt_outp->lines->size()];

    copy(txt_inp->lines->begin(), txt_inp->lines->end(), txt_inp_arr);
    copy(txt_outp->lines->begin(), txt_outp->lines->end(), txt_outp_arr);

    for(unsigned int i = 0; i < txt_inp->lines->size(); i++)
        EXPECT_STREQ(txt_inp_arr[i].c_str(), txt_outp_arr[i].c_str());

    free(txt_inp);
    free(txt_outp);
}

TEST(save_content, one_line)
{
    text txt_inp = create_text();
    txt_inp->lines->push_back("Line 0\n");
    txt_inp->cursor->line_num = 0;
    txt_inp->cursor->position = 0;
    save(txt_inp, "save_content.test.txt");

    text txt_outp = create_text();
    load(txt_outp, "save_content.test.txt");

    EXPECT_EQ(txt_inp->lines->size(), txt_outp->lines->size());

    string* txt_inp_arr = new string[txt_inp->lines->size()];
    string* txt_outp_arr = new string[txt_outp->lines->size()];

    copy(txt_inp->lines->begin(), txt_inp->lines->end(), txt_inp_arr);
    copy(txt_outp->lines->begin(), txt_outp->lines->end(), txt_outp_arr);

    for(unsigned int i = 0; i < txt_inp->lines->size(); i++)
        EXPECT_STREQ(txt_inp_arr[i].c_str(), txt_outp_arr[i].c_str());

    free(txt_inp);
    free(txt_outp);
}

TEST(save_content, empty_file)
{
    text txt_inp = create_text();
    txt_inp->cursor->line_num = 0;
    txt_inp->cursor->position = 0;
    save(txt_inp, "save_content.test.txt");

    text txt_outp = create_text();
    load(txt_outp, "save_content.test.txt");

    EXPECT_EQ(txt_inp->lines->size(), txt_outp->lines->size());

    string* txt_inp_arr = new string[txt_inp->lines->size()];
    string* txt_outp_arr = new string[txt_outp->lines->size()];

    copy(txt_inp->lines->begin(), txt_inp->lines->end(), txt_inp_arr);
    copy(txt_outp->lines->begin(), txt_outp->lines->end(), txt_outp_arr);

    for(unsigned int i = 0; i < txt_inp->lines->size(); i++)
        EXPECT_STREQ(txt_inp_arr[i].c_str(), txt_outp_arr[i].c_str());

    free(txt_inp);
    free(txt_outp);
}
