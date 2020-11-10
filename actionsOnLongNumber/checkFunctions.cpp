#include <iostream>
#include "checkFunctions.h"

// проверка, является ли символ числом восьмеричной СС
bool isDigit(char a, bool withZero = true) {
    return (withZero ? a >= '0' && a <= '7' : a >= '1' && a <= '7');
}

// проверка, удовлетворяет ли строка синтаксису БНФ записи
[[maybe_unused]] bool isParsable(std::string& line) {
    unsigned int len = line.length();
    unsigned int i;
    bool isSign = true;
    bool isInteger = false;
    bool isFraction = false;

    for (i = 0; i < len; ++i) {
        if (isSign && ( line[i] == '-' || isDigit( line[i]) ) ) {
            isSign = false;
            isInteger = true;
        } else if (isInteger && line[i - 1] != '-' && line[i] == '.') {
            isInteger = false;
            isFraction = true;
        } else if ( (isInteger || isFraction) && isDigit(line[i]) ) {
            continue;
        } else {
            break;
        }
    }

    return i == len && line[i - 1] != '-' && line[i - 1] != '.' && isDigit(line[i - 1]);
}

[[maybe_unused]] bool isEqual(LongNum& a, LongNum& b, bool abs) {
    if ( (a.sign == b.sign || abs) && a.integerSize == b.integerSize && a.fractionSize == b.fractionSize) {
        for (int i = a.integerSize - 1; i >= 0; --i) {
            if (a.integer[i] != b.integer[i]) {
                return false;
            }
        }
        for (int i = 0; i < a.fractionSize; ++i) {
            if (a.fraction[i] != b.fraction[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

[[maybe_unused]] bool isLess(LongNum& a, LongNum& b, bool abs) {
    if (a.sign == b.sign || abs) {
        LongNum& lower = a.sign || abs ? a : b;
        LongNum& higher = a.sign || abs ? b : a;
        if (lower.integerSize == higher.integerSize) {
            for (int i = lower.integerSize - 1; i >= 0; --i) {
                if (lower.integer[i] != higher.integer[i]) {
                    return lower.integer[i] < higher.integer[i];
                }
            }
            int maxFractionSize = a.fractionSize > b.fractionSize ? a.fractionSize : b.fractionSize;
            for (int i = 0; i < maxFractionSize; ++i) {
                if (lower.fraction[i] != higher.fraction[i]) {
                    return lower.fraction[i] < higher.fraction[i];
                }
            }
            return false;
        } else {
            return lower.integerSize < higher.integerSize;
        }
    }
    return !a.sign && b.sign;
}