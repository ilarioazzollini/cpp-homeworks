#include <string>
#include <vector>

#include <no_strings_attached/string_split.h>
#include <gtest/gtest.h>

TEST(StringSplit, DelimiterNotFound) {
    std::string input = "This is a string";
    std::string delimiter = "z";
    std::vector<std::string> result = no_strings_attached::Split(input, delimiter);
    EXPECT_EQ(input, result[0]);
}

TEST(StringSplit, DelimiterFound) {
    std::string input = "This is a string";
    std::string delimiter = "is";
    std::vector<std::string> expected_result{"Th", " ", " a string"};
    std::vector<std::string> result = no_strings_attached::Split(input, delimiter);
    EXPECT_EQ(expected_result, result);
}

TEST(StringSplit, SpaceDelimiter) {
    std::string input = "This is a string";
    std::string delimiter = " ";
    std::vector<std::string> expected_result{"This", "is", "a", "string"};
    std::vector<std::string> result = no_strings_attached::Split(input, delimiter);
    EXPECT_EQ(expected_result, result);
}

TEST(StringSplit, ApplicationTest) {
    std::string input = "hello world";
    std::string delimiter = " ";
    std::vector<std::string> expected_result{"hello", "world"};
    std::vector<std::string> result = no_strings_attached::Split(input, delimiter);
    EXPECT_EQ(expected_result, result);
}

TEST(StringSplitWithExtraInput, DelimiterNotFound) {
    std::string input = "This is a string";
    std::string delimiter = "z";
    std::vector<std::string> result = no_strings_attached::Split(input, delimiter, 10);
    EXPECT_EQ(input, result[0]);
}

TEST(StringSplitWithExtraInput, DelimiterFound) {
    std::string input = "This is a string";
    std::string delimiter = "is";
    std::vector<std::string> expected_result{"Th", " ", " a string"};
    std::vector<std::string> result = no_strings_attached::Split(input, delimiter, 3);
    EXPECT_EQ(expected_result, result);
}

TEST(StringSplitWithExtraInput, SpaceDelimiter) {
    std::string input = "This is a string";
    std::string delimiter = " ";
    std::vector<std::string> expected_result{"This", "is"};
    std::vector<std::string> result = no_strings_attached::Split(input, delimiter, 2);
    EXPECT_EQ(expected_result, result);
}

TEST(StringSplitWithExtraInput, ApplicationTest) {
    std::string input = "hello world";
    std::string delimiter = " ";
    std::vector<std::string> expected_result{"hello"};
    std::vector<std::string> result = no_strings_attached::Split(input, delimiter, 1);
    EXPECT_EQ(expected_result, result);
}

// Add Igor's Validation tests
TEST(SplitValidationTest, SplitDelimeterNotFound) {
  auto test_string = "";
  const auto split_on_empty = no_strings_attached::Split("", " ");
  ASSERT_FALSE(split_on_empty.empty())
      << "Failed to split: '" << test_string << "'";
  EXPECT_EQ("", split_on_empty.front())
      << "Failed to split: '" << test_string << "'";
  test_string = "hello";
  const auto split_no_space = no_strings_attached::Split(test_string, " ");
  ASSERT_FALSE(split_no_space.empty())
      << "Failed to split: '" << test_string << "'";
  EXPECT_EQ("hello", split_no_space.front())
      << "Failed to split: '" << test_string << "'";
}

TEST(SplitValidationTest, SplitTwoWordsOnString) {
  const auto test_string = "hello world";
  const auto split = no_strings_attached::Split(test_string, " ");
  ASSERT_EQ(2UL, split.size()) << "Failed to split: '" << test_string << "'";
  EXPECT_EQ("hello", split.front())
      << "Failed to split: '" << test_string << "'";
  EXPECT_EQ("world", split.back())
      << "Failed to split: '" << test_string << "'";
}

TEST(SplitValidationTest, SplitMoreWords) {
  const auto test_string = "some_string__split__with_underscores";
  const auto split = no_strings_attached::Split(test_string, "__");
  ASSERT_EQ(3UL, split.size()) << "Failed to split: '" << test_string << "'";
  EXPECT_EQ("some_string", split[0])
      << "Failed to split: '" << test_string << "'";
  EXPECT_EQ("split", split[1]) << "Failed to split: '" << test_string << "'";
  EXPECT_EQ("with_underscores", split[2])
      << "Failed to split: '" << test_string << "'";
}

TEST(SplitValidationTest, RepeatedString) {
  const auto test_string = "split_me__and_me";
  const auto split = no_strings_attached::Split(test_string, "_");
  ASSERT_EQ(5UL, split.size()) << "Failed to split: '" << test_string << "'";
  EXPECT_EQ("split", split[0]) << "Failed to split: '" << test_string << "'";
  EXPECT_EQ("me", split[1]) << "Failed to split: '" << test_string << "'";
  EXPECT_EQ("", split[2]) << "Failed to split: '" << test_string << "'";
  EXPECT_EQ("and", split[3]) << "Failed to split: '" << test_string << "'";
  EXPECT_EQ("me", split[4]) << "Failed to split: '" << test_string << "'";
}
