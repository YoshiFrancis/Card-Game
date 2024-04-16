#ifndef HELPER_H
#define HELPER_H

#include <string>

namespace Helper {
    std::string toLower(const std::string str);
	int generateRandomNumber(int min, int max); // non-inclusive of the end, inclusive of beginning
}


#endif
