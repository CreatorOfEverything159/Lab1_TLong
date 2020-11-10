#ifndef LAB1TLONG_READWRITE_H
#define LAB1TLONG_READWRITE_H

#include "../type.h"

[[maybe_unused]] bool readLongNum(std::ifstream& inFile, LongNum& num);
[[maybe_unused]] void writeLongNum(std::ofstream& outFile, LongNum& num);
[[maybe_unused]] bool readSign(std::ifstream& inFile, bool& sign);

#endif //LAB1TLONG_READWRITE_H
