#include "helper.h"
#include <string>
#include <cctype>
#include <algorithm>
#include <stdlib.h>
#include <random>
#include <time.h>


std::random_device rd;
std::mt19937 gen(rd());

std::string Helper::toLower(const std::string str) {
  std::string copy_str (str);
  std::transform(copy_str.begin(), copy_str.end(), copy_str.begin(), [] (char c) { return std::tolower(c); } );
  return copy_str;
}

int Helper::generateRandomNumber(int min, int max) {
	std::uniform_int_distribution<int> dis(min, max);
	return dis(gen);
}

