#ifndef LAB1TLONG_MASSAGES_H
#define LAB1TLONG_MASSAGES_H

#include "massages.h"
#include <iostream>

[[maybe_unused]] std::string fileNotFound(const std::string &path);
[[maybe_unused]] std::string fileIsEmpty(const std::string &path);
[[maybe_unused]] std::string invalidEndOfFile(const std::string &path);
[[maybe_unused]] std::string successfullyCompleted(const std::string &inPath, const std::string &outPath);
[[maybe_unused]] std::string unsuccessfullyCompleted(const std::string &inPath, const std::string &outPath);
[[maybe_unused]] std::string invalidLongNum(unsigned int index);
[[maybe_unused]] std::string invalidSign(unsigned int index);
[[maybe_unused]] std::string dataOverflowed();

#endif //LAB1TLONG_MASSAGES_H
