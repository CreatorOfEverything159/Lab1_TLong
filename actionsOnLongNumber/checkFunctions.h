#ifndef LAB1TLONG_CHECKFUNCTIONS_H
#define LAB1TLONG_CHECKFUNCTIONS_H

#include "../type.h"

[[maybe_unused]] bool isEqual(LongNum& a, LongNum& b, bool abs = false);
[[maybe_unused]] bool isLess(LongNum& a, LongNum& b, bool abs = false);

bool isDigit(char a, bool);
bool isLess(LongNum& a, LongNum& b, bool abs);
bool isParsable(std::string& line);

#endif //LAB1TLONG_CHECKFUNCTIONS_H
