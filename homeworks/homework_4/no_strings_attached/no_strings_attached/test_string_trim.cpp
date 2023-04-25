#include <string>

#include <no_strings_attached/string_trim.h>
#include <gtest/gtest.h>

TEST(StringTrim, LeftTest) {
    std::string input{" hello world "};
    char char_to_trim = ' ';
    no_strings_attached::Side side = no_strings_attached::Side::kLeft;
    std::string expected_result{"hello world "};
    std::string result = no_strings_attached::Trim(input, char_to_trim, side);
    EXPECT_EQ(expected_result, result);
}

TEST(StringTrim, RightTest) {
    std::string input{" hello world "};
    char char_to_trim = ' ';
    no_strings_attached::Side side = no_strings_attached::Side::kRight;
    std::string expected_result{" hello world"};
    std::string result = no_strings_attached::Trim(input, char_to_trim, side);
    EXPECT_EQ(expected_result, result);
}

TEST(StringTrim, ApplicationTest) {
    std::string input{" hello world  "};
    std::string expected_result{"hello world"};
    std::string result = no_strings_attached::Trim(input);
    EXPECT_EQ(expected_result, result);
}
