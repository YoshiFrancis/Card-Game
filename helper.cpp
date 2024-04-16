#include "helper.h"
#include <string>
#include <cctype>
#include <algorithm>

std::string Helper::toLower(const std::string str) {
  std::string copy_str (str);
  std::transform(copy_str.begin(), copy_str.end(), copy_str.begin(), [] (char c) { return std::tolower(c); } );
  return copy_str;
}
