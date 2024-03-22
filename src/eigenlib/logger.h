#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <omp.h>
#include <string>
#include <thread>

#ifdef _WIN32 // Windows
    #include <Windows.h>
#endif


using namespace std;

enum class LogLevel {
    TRACE_MSG,
    DEBUG_MSG,
    INFO_MSG,
    WARNING_MSG,
    ERROR_MSG,
    CRTITCAL_MSG,
    PRINT_MSG,
    TEST_PASSED_MSG,
    OUT_MSG
};

void LOGGER(LogLevel level, string& message);

void TRACE_OUT(const string& message);
void DEBUG_OUT(const string& message);
void INFO_OUT(const string& message);
void WARNING_OUT(const string& message);
void ERROR_OUT(const string& message);
void CRTITCAL_OUT(const string& message);
void PRINT(const string& message);
void TEST_PASSED(const string& message);
void DEBUG_OUTFILE(const string& message);

// Console display
enum class ConsoleColor {
#ifdef _WIN32 // Windows
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    YELLOW = 6,
    WHITE = 7,
    GRAY = 8,
    DEFAULT = 7
#else // Linux (and other Unix-like systems)
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    WHITE = 37,
    GRAY = 90,
    DEFAULT = 39
#endif
};

void setColor(ConsoleColor color);

string formatPrecision(double value);

string formatTime(double timeInSeconds);

void sleep(int seconds);

#endif // LOGGER_H
