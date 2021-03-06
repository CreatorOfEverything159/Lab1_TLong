#include <iostream>
#include <fstream>
#include "const/const.h"
#include "dialog/massages.h"
#include "dialog/readWrite.h"
#include "actionsOnLongNumber/mathFunctions.h"

bool process(std::ifstream& inFile, std::ofstream& outFile) {
    bool isFileCorrect = inFile.is_open();

    if (!isFileCorrect) {
        outFile << fileNotFound(IN_PATH);
    } else {
        LongNum sum;
        bool sign = true;
        unsigned int index = 1;

        while ( !inFile.eof() ) {
            if (index % 2 == 1) {
                LongNum num;
                if ( !readLongNum(inFile, num) ) {
                    outFile << invalidLongNum(index) << std::endl;
                    isFileCorrect = false;
                }
                if (isFileCorrect) {
                    if (index == 1) {
                        sum = num;
                    } else {
                        sum = sign ? sumLongNum(sum, num) : subLongNum(sum, num);
                    }
                }
            } else if ( !readSign(inFile, sign) ) {
                outFile << invalidSign(index) << std::endl;
                isFileCorrect = false;
            }
            ++index;
        }

        if (index == 1) {
            outFile << fileIsEmpty(IN_PATH);
            isFileCorrect = false;
        } else if (index % 2 == 1 && isFileCorrect) {
            outFile << invalidEndOfFile(IN_PATH);
            isFileCorrect = false;
        } else if (isFileCorrect) {
            writeLongNum(outFile, sum);
        }
    }

    return isFileCorrect;
}


int main() {
    std::ifstream inFile(IN_PATH);
    std::ofstream outFile(OUT_PATH);
    bool isSuccessfullyCompleted = process(inFile, outFile);

    inFile.close();
    outFile.close();

    if (isSuccessfullyCompleted) {
        std::cout << successfullyCompleted(IN_PATH, OUT_PATH) << std::endl;
    } else {
        std::cout << unsuccessfullyCompleted(IN_PATH, OUT_PATH) << std::endl;
    }

    return 0;
}