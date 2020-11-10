#include "massages.h"
#include <iostream>


[[maybe_unused]] std::string fileNotFound(const std::string &path) {
    return "Невозможно найти входной файл по адресу: \"" + path + "\"";
}


[[maybe_unused]] std::string fileIsEmpty(const std::string &path) {
    return "Входной файл \"" + path + "\" пуст";
}


[[maybe_unused]] std::string invalidEndOfFile(const std::string &path) {
    return "Файл \"" + path + "\" неверно завершен (последней строкой должно быть число)";
}


[[maybe_unused]] std::string successfullyCompleted(const std::string &inPath, const std::string &outPath) {
    return "Файл \"" + inPath + "\" успешно обработан\nРезультат можно просмотреть в файле \"" + outPath + "\"";
}


[[maybe_unused]] std::string unsuccessfullyCompleted(const std::string &inPath, const std::string &outPath) {
    return "В файле \"" + inPath + "\" были найдены ошибки\nОшибки можно просмотреть в файле \"" + outPath + "\"";
}


[[maybe_unused]] std::string invalidLongNum(unsigned int index) {
    return "Строка " + std::to_string(index) + " - неверно введено число LongNum (проверьте правильность синтаксиса " +
           "числа LongNum и убедитесь, что в начале и в конце строки не присутствуют лишние пробелы)";
}


[[maybe_unused]] std::string invalidSign(unsigned int index) {
    return "Строка " + std::to_string(index) + " - неверно введен арифметический знак (поддерживаются только знаки " +
           "\"+\" и \"-\", и также убедитесь, что в начале и в конце строки не присутствуют лишние пробелы)";
}


[[maybe_unused]] std::string dataOverflowed() {
    return "Произошло переполнение памяти под число, итоговое вычисление будет неверным";
}