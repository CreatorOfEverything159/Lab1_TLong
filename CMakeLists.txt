cmake_minimum_required(VERSION 3.17)
project(Lab1TLong)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab1TLong main.cpp dialog/readWrite.cpp dialog/readWrite.h actionsOnLongNumber/checkFunctions.cpp actionsOnLongNumber/checkFunctions.h actionsOnLongNumber/mathFunctions.cpp actionsOnLongNumber/mathFunctions.h actionsOnLongNumber/helperActions.cpp actionsOnLongNumber/helperActions.h dialog/massages.cpp dialog/massages.h const/const.cpp const/const.h type.h)