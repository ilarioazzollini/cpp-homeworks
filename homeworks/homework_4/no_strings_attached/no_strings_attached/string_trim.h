#pragma once

#include <string>

enum class Side { kLeft, kRight, kBoth };

namespace no_strings_attached {
namespace string_trim {
std::string Trim(const std::string& str, char char_to_trim, Side side);
std::string Trim(const std::string& str);
} // namespace string_trim
} // namespace no_strings_attached
