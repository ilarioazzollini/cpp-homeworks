#include <string>
#include <vector>

#include <no_strings_attached/string_split.h>

// https://en.cppreference.com/w/cpp/string/basic_string/find

namespace no_strings_attached {
namespace string_split {
std::vector<std::string> Split(const std::string& str, const std::string& delimiter) {
    std::string::size_type n;
    n = str.find(delimiter);
}
std::vector<std::string> Split(const std::string& str, const std::string& delimiter, int number_of_chunks_to_keep) {

}
} // namespace string_split
} // namespace no_strings_attached