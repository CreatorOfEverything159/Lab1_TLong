#include <fstream>
#include "checkFunctions.h"

// разворачивает строку ("4321" -> "1234")
std::string reverse(std::string& line) {
    std::string reversed;
    for (int i = static_cast<int>( line.length() ) - 1; i >= 0; --i) {
        reversed += line[i];
    }
    return reversed;
}

// возвращает целую часть числа, отбрасывая незначащие нули
[[maybe_unused]] std::string getInteger(std::string& line) {
    std::string integer;
    bool hasSignificantDigit = false;
    unsigned int len = line.length();
    int startPosition = line[0] == '-' ? 1 : 0;
    int dotPosition = static_cast<int>( line.find('.') );
    int endPosition = dotPosition > -1 ? dotPosition - 1 : static_cast<int>(len) - 1;

    // сохраняет в integer только значащие цифры
    for (int i = startPosition; i <= endPosition; ++i) {
        if (!hasSignificantDigit && isDigit(line[i], false) || i == endPosition) {
            hasSignificantDigit = true;
        }
        if (hasSignificantDigit) {
            integer += line[i];
        }
    }

    return integer;
}

// возвращает дробную часть числа, отбрасывая незначащие нули
[[maybe_unused]] std::string getFraction(std::string& line) {
    std::string fraction;
    bool hasSignificantDigit = false;
    unsigned int len = line.length();
    int startPosition = static_cast<int>(len) - 1;
    int dotPosition = static_cast<int>( line.find('.') );
    int endPosition = dotPosition > -1 ? dotPosition + 1 : startPosition + 1;

    // сохраняет в fraction только значащие цифры
    for (int i = startPosition; i >= endPosition; --i) {
        if (!hasSignificantDigit && isDigit(line[i], false) ) {
            hasSignificantDigit = true;
        }
        if (hasSignificantDigit) {
            fraction += line[i];
        }
    }

    return reverse(fraction);
}


// если remainder получился 1, тогда произошло переполнение десятков и единиц в сумме
[[maybe_unused]] void sumNumbers(unsigned char& sum, int& remainder, int a, int b) {
    int units, tens, q1, q2;
    units = a % 10 + b % 10 + remainder;
    tens = a / 10 + b / 10 + (units >= 8 ? 1 : 0);
    q2 = units % 8;
    q1 = tens % 8;
    remainder = tens >= 8 ? 1 : 0;
    sum = q1 * 10 + q2;
}

// если remainder получился -1, тогда произошла нехватка десятков и единиц в разности
[[maybe_unused]] void subNumbers(unsigned char& sub, int& remainder, int a, int b) {
    int units, tens, q1, q2;
    units = a % 10 - b % 10 + remainder;
    tens = a / 10 - b / 10 - (units >= 0 ? 0 : 1);
    q2 = units >= 0 ? units : 8 + units;
    q1 = tens >= 0 ? tens : 8 + tens;
    remainder = tens >= 0 ? 0 : -1;
    sub = q1 * 10 + q2;
}
