#include <fstream>
#include "iostream"
#include "readWrite.h"
#include "../actionsOnLongNumber/checkFunctions.h"
#include "../actionsOnLongNumber/helperActions.h"
#include "massages.h"

// парсит строку, в которой должно находиться число LongNum, и при успехе преобразует строку в num
[[maybe_unused]] bool readLongNum(std::ifstream& inFile, LongNum& num) {
    std::string line;
    getline(inFile, line);
    if (static_cast<int>( line.find('\r') ) > -1) {
        line.erase(line.length() - 1);
    }
    if ( isParsable(line) ) {
        std::string element;
        bool isOverflowed = false;

        num.sign = line[0] != '-';
        std::string integerString = getInteger(line);
        std::string fractionString = getFraction(line);
        int integerLength = static_cast<int>( integerString.length() );
        int fractionLength = static_cast<int>( fractionString.length() );

        num.integerSize = 0;
        element = "";
        for (int i = integerLength - 1; i >= 0; --i) {
            element += integerString[i];
            if (element.length() == 2 || i == 0) {
                element = reverse(element);
                num.integer[num.integerSize++] = std::stoi(element);
                element.clear();
                if (num.integerSize == DATA_SIZE) {
                    std::cout << dataOverflowed() << std::endl;
                    isOverflowed = true;
                    break;
                }
            }
        }

        num.fractionSize = 0;
        element = "";
        for (int i = 0; i < fractionLength; ++i) {
            element += fractionString[i];
            if (element.length() == 2 || i == fractionLength - 1) {
                num.fraction[num.fractionSize] = std::stoi(element);
                if (i == fractionLength - 1 && element.length() == 1) {
                    num.fraction[num.fractionSize] *= 10;
                }
                ++num.fractionSize;
                element.clear();
                if (num.fractionSize == DATA_SIZE && !isOverflowed) {
                    std::cout << dataOverflowed() << std::endl;
                    break;
                }
            }
        }

        return !(!num.sign && num.integerSize == 1 && num.integer[0] == 0 && num.fractionSize == 0);
    }
    return false;
}

// выводит число LongNum в читаемом виде в конец файла outFile
[[maybe_unused]] void writeLongNum(std::ofstream& outFile, LongNum& num) {
    if (!num.sign) {
        outFile << '-';
    }
    for (int i = num.integerSize - 1; i >= 0; --i) {
        if (num.integer[i] < 10 && i < num.integerSize - 1) {
            outFile << '0';
        }
        outFile << static_cast<short>(num.integer[i]);
    }
    if (num.fractionSize > 0) {
        outFile << '.';
        for (int i = 0; i < num.fractionSize; ++i) {
            if (i < num.fractionSize - 1 || i == num.fractionSize - 1 && num.fraction[i] % 10 > 0) {
                if (num.fraction[i] < 10) {
                    outFile << '0';
                }
                outFile << static_cast<short>(num.fraction[i]);
            } else {
                outFile << static_cast<short>(num.fraction[i] / 10);
            }
        }
    }
    outFile << std::endl;
}

[[maybe_unused]] bool readSign(std::ifstream& inFile, bool& sign) {
    std::string line;
    getline(inFile, line);
    if (static_cast<int>( line.find('\r') ) > -1) {
        line.erase(line.length() - 1);
    }
    if (line.length() == 1 && (line[0] == '+' || line[0] == '-') ) {
        sign = line[0] == '+';
        return true;
    }
    return false;
}