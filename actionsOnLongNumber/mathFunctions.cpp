#include <fstream>
#include "mathFunctions.h"
#include "helperActions.h"
#include "checkFunctions.h"

// складывает целую и дробную части, игнорируя знак (то есть вычитает по модулю)
LongNum absSum(LongNum& a, LongNum& b) {
    LongNum sum;
    int remainder = 0;

    sum.integerSize = a.integerSize > b.integerSize ? a.integerSize : b.integerSize;
    sum.fractionSize = a.fractionSize > b.fractionSize ? a.fractionSize : b.fractionSize;

    for (int i = sum.fractionSize - 1; i >= 0; --i) {
        sumNumbers(sum.fraction[i], remainder, a.fraction[i], b.fraction[i]);
    }
    for (int i = 0; i < sum.integerSize; ++i) {
        sumNumbers(sum.integer[i], remainder, a.integer[i], b.integer[i]);
    }
    if (remainder > 0 && sum.integerSize < DATA_SIZE) {
        sum.integer[sum.integerSize++] = remainder;
    }

    // удаление незначащих нулей, которые могут образоваться
    while (sum.integerSize > 1 && sum.integer[sum.integerSize - 1] == 0) {
        --sum.integerSize;
    }
    while (sum.fractionSize > 0 && sum.fraction[sum.fractionSize - 1] == 0) {
        --sum.fractionSize;
    }

    return sum;
}

// вычитает целую и дробную части, игнорируя знак (то есть складывает по модулю)
LongNum absSub(LongNum& a, LongNum& b) {
    LongNum sub;
    int remainder = 0;

    sub.integerSize = a.integerSize > b.integerSize ? a.integerSize : b.integerSize;
    sub.fractionSize = a.fractionSize > b.fractionSize ? a.fractionSize : b.fractionSize;

    bool less = isLess(a, b, true);
    LongNum& lower = less ? a : b;
    LongNum& higher = less ? b : a;

    while (sub.fractionSize > 0 && higher.fraction[sub.fractionSize - 1] == lower.fraction[sub.fractionSize - 1]) {
        sub.fraction[--sub.fractionSize] = 0;
    }
    for (int i = sub.fractionSize - 1; i >= 0; --i) {
        subNumbers(sub.fraction[i], remainder, higher.fraction[i], lower.fraction[i]);
    }
    for (int i = 0; i < sub.integerSize; ++i) {
        subNumbers(sub.integer[i], remainder, higher.integer[i], lower.integer[i]);
    }

    // удаление незначащих нулей, которые могут образоваться
    while (sub.integerSize > 1 && sub.integer[sub.integerSize - 1] == 0) {
        --sub.integerSize;
    }
    while (sub.fractionSize > 0 && sub.fraction[sub.fractionSize - 1] == 0) {
        --sub.fractionSize;
    }

    return sub;
}

[[maybe_unused]] LongNum sumLongNum(LongNum& a, LongNum& b) {
    LongNum sum;
    if (a.sign == b.sign) {
        sum = absSum(a, b);
        sum.sign = a.sign;
    } else {
        if ( !isEqual(a, b, true) ) {
            bool less = isLess(a, b, true);
            sum = less ? absSub(b, a) : absSub(a, b);
            sum.sign = less ? b.sign : a.sign;
        }
    }
    return sum;
}

[[maybe_unused]] LongNum subLongNum(LongNum& a, LongNum& b) {
    LongNum sub;
    if (a.sign == b.sign) {
        if ( !isEqual(a, b, true) ) {
            bool less = isLess(a, b, true);
            sub = less ? absSub(b, a) : absSub(a, b);
            sub.sign = less ? !b.sign : a.sign;
        }
    } else {
        sub = absSum(a, b);
        sub.sign = a.sign;
    }
    return sub;
}