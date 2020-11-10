#include "const/const.h"

typedef struct LongNum {
    bool sign;
    unsigned char integer[DATA_SIZE]{};
    unsigned char fraction[DATA_SIZE]{};
    unsigned char integerSize{};
    unsigned char fractionSize{};

    LongNum() {
        sign = true;
        integerSize = 1;
    }
} LongNum;