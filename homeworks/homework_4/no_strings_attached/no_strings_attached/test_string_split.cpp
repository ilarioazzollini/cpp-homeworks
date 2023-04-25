#include <iostream>
#include <string>
#include <vector>

#include <no_strings_attached/string_split.h>
#include <gtest/gtest.h>

TEST(StringSplit, DelimiterNotFound) {
    std::string input = "This is a string";
    std::string delimiter = "z";
    std::vector<std::string> result = no_strings_attached::string_split::Split(input, delimiter);
    EXPECT_EQ(input, result[0]);
}

TEST(StringSplit, DelimiterFound) {
    std::string input = "This is a string";
    std::string delimiter = "is";
    std::vector<std::string> expected_result{"Th", " ", " a string"};
    std::vector<std::string> result = no_strings_attached::string_split::Split(input, delimiter);
    EXPECT_EQ(expected_result, result);
}

TEST(StringSplit, SpaceDelimiter) {
    std::string input = "This is a string";
    std::string delimiter = " ";
    std::vector<std::string> expected_result{"This", "is", "a", "string"};
    std::vector<std::string> result = no_strings_attached::string_split::Split(input, delimiter);
    EXPECT_EQ(expected_result, result);
}

TEST(StringSplit, ApplicationTest) {
    std::string input = "hello world";
    std::string delimiter = " ";
    std::vector<std::string> expected_result{"hello", "world"};
    std::vector<std::string> result = no_strings_attached::string_split::Split(input, delimiter);
    EXPECT_EQ(expected_result, result);
}

TEST(StringSplitWithExtraInput, DelimiterNotFound) {
    std::string input = "This is a string";
    std::string delimiter = "z";
    std::vector<std::string> result = no_strings_attached::string_split::Split(input, delimiter, 10);
    EXPECT_EQ(input, result[0]);
}

TEST(StringSplitWithExtraInput, DelimiterFound) {
    std::string input = "This is a string";
    std::string delimiter = "is";
    std::vector<std::string> expected_result{"Th", " ", " a string"};
    std::vector<std::string> result = no_strings_attached::string_split::Split(input, delimiter, 3);
    EXPECT_EQ(expected_result, result);
}

TEST(StringSplitWithExtraInput, SpaceDelimiter) {
    std::string input = "This is a string";
    std::string delimiter = " ";
    std::vector<std::string> expected_result{"This", "is"};
    std::vector<std::string> result = no_strings_attached::string_split::Split(input, delimiter, 2);
    EXPECT_EQ(expected_result, result);
}

TEST(StringSplitWithExtraInput, ApplicationTest) {
    std::string input = "hello world";
    std::string delimiter = " ";
    std::vector<std::string> expected_result{"hello"};
    std::vector<std::string> result = no_strings_attached::string_split::Split(input, delimiter, 1);
    EXPECT_EQ(expected_result, result);
}

// EXPECT_EQ will always continue the execution of the tests while ASSERT_EQ will not (if it fails)
