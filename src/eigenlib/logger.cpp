#include "logger.h"

string getCurrentTime() {
    time_t rawTime;
    struct tm* timeInfo;

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%H:%M:%S", timeInfo);

    return buffer;
}

inline void setColor(ConsoleColor color) {
#ifdef _WIN32 // Windows
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<WORD>(color));
#else // Linux (and other Unix-like systems)
    switch (color) {
        case ConsoleColor::BLACK:
            cout << "\033[0;30m";
            break;
        case ConsoleColor::RED:
            cout << "\033[0;31m";
            break;
        case ConsoleColor::GREEN:
            cout << "\033[0;32m";
            break;
        case ConsoleColor::YELLOW:
            cout << "\033[0;33m";
            break;
        case ConsoleColor::BLUE:
            cout << "\033[0;34m";
            break;
        case ConsoleColor::MAGENTA:
            cout << "\033[0;35m";
            break;
        case ConsoleColor::CYAN:
            cout << "\033[0;36m";
            break;
        case ConsoleColor::WHITE:
            cout << "\033[0;37m";
            break;
        case ConsoleColor::GRAY:
            cout << "\033[1;30m";
            break;
        case ConsoleColor::DEFAULT:
        default:
            cout << "\033[0m"; // Reset to default color
            break;
    }
#endif
}

string formatPrecision(double value) {
    ostringstream oss;
    oss << fixed << setprecision(8) << value;
    return oss.str();
}

string formatTime(double timeInSeconds) {
    int hours = static_cast<int>(timeInSeconds / 3600);
    int minutes = static_cast<int>((timeInSeconds - hours * 3600) / 60);
    int seconds = static_cast<int>(timeInSeconds - hours * 3600 - minutes * 60);

    if (hours > 0) {
        return to_string(hours) + " hour, " + to_string(minutes) + " minute, " + to_string(seconds) + " second";
    } else if (minutes > 0) {
        return to_string(minutes) + " minute, " + to_string(seconds) + " second";
    } else if (timeInSeconds >= 60) {
        return to_string(static_cast<int>(timeInSeconds / 60)) + " minute";
    } else {
        return formatPrecision(timeInSeconds) + " second";
    }
}

void sleep(int seconds) {
    time_t startTime = time(nullptr);
    time_t targetTime = startTime + seconds;

    while (time(nullptr) < targetTime);
}

void logSystemInfoOnce() {
    static bool systemInfoLogged = false;
    if (!systemInfoLogged) {
        time_t rawTime;
        struct tm* timeInfo;

        time(&rawTime);
        timeInfo = localtime(&rawTime);

        char buffer[80];

        strftime(buffer, sizeof(buffer), "Date %d-%b-%Y   Time %H:%M:%S", timeInfo);

        string systemInfo;
        stringstream ss;

        ss << "CMake Version: " << CMake_VERSION << "\n"
           << "GCC Version: " << gcc_VERSION << "\n"
           << "OMP max threads: " << to_string(omp_get_max_threads()) << "\n";

        systemInfo = ss.str();

        ofstream logFile("vonMises.log", ios::out);
        if (logFile.is_open()) {
            logFile << buffer << "\n\n";
            logFile << "System Information:\n" << systemInfo << "\n\n";
            logFile.close();
        }

        cout << buffer << endl;
        cout << systemInfo << endl;

        ofstream outFile("vonMises.out", ios::out);
        if (outFile.is_open()) {
            outFile << buffer << "\n\n";
            outFile << "System Information:\n" << systemInfo << "\n\n";
            outFile.close();
        }

        systemInfoLogged = true;
    }
}



void LOGGER(LogLevel level, const string& message) {
    logSystemInfoOnce();

    string levelStr;
    ConsoleColor levelColor;

    switch (level) {
        case LogLevel::TRACE_MSG:
            levelStr = "TRACE";
            levelColor = ConsoleColor::GRAY;
            break;
        case LogLevel::DEBUG_MSG:
            levelStr = "DEBUG";
            levelColor = ConsoleColor::MAGENTA;
            break;
        case LogLevel::INFO_MSG:
            levelStr = "INFO";
            levelColor = ConsoleColor::WHITE;
            break;
        case LogLevel::WARNING_MSG:
            levelStr = "WARNING";
            levelColor = ConsoleColor::YELLOW;
            break;
        case LogLevel::ERROR_MSG:
            levelStr = "ERROR";
            levelColor = ConsoleColor::RED;
            break;
        case LogLevel::CRTITCAL_MSG:
            levelStr = "CRITICAL";
            levelColor = ConsoleColor::CYAN;
            break;
        case LogLevel::PRINT_MSG:
            levelStr = "INFO";
            levelColor = ConsoleColor::BLUE;
            break;
        case LogLevel::TEST_PASSED_MSG:
            levelStr = "INFO";
            levelColor = ConsoleColor::GREEN;
            break;
        case LogLevel::OUT_MSG:
            levelStr = "OUT";
            break;
    }

    string logMessage = getCurrentTime() + ": " + levelStr + ": - " + message;

    if (message.length() <= 120 && levelStr != "OUT") {
        ofstream logFile("vonMises.log", ios::app);
        if (logFile.is_open()) {
            logFile << logMessage << endl;
            logFile.close();
        }

        setColor(levelColor);

        if (levelStr == "ERROR") {
            cerr << logMessage << endl;
            throw runtime_error(logMessage);
        }

        else {
            cout << logMessage << endl;
        }
    }

    ofstream outFile("vonMises.out", ios::app);
    if (outFile.is_open()) {
        outFile << message << endl;
        outFile.close();
    }

    setColor(ConsoleColor::DEFAULT);
}


void TRACE_OUT(const string& message) {
    LOGGER(LogLevel::TRACE_MSG, message);
}

// Messages that contain information normally of use only when debugging a program.
void DEBUG_OUT(const string& message) {
    LOGGER(LogLevel::DEBUG_MSG, message);
}

// Confirmation that the program is working as expected.
void INFO_OUT(const string& message) {
    LOGGER(LogLevel::INFO_MSG, message);
}

void WARNING_OUT(const string& message) {
    LOGGER(LogLevel::WARNING_MSG, message);
}

void ERROR_OUT(const string& message) {
    LOGGER(LogLevel::ERROR_MSG, message);
}

// Hard device errors.
void CRTITCAL_OUT(const string& message) {
    LOGGER(LogLevel::CRTITCAL_MSG, message);
}

void PRINT(const string& message) {
    LOGGER(LogLevel::PRINT_MSG, message);
}

void TEST_PASSED(const string& message) {
    LOGGER(LogLevel::TEST_PASSED_MSG, message);
}

void DEBUG_OUTFILE(const string& message) {
    LOGGER(LogLevel::OUT_MSG, message);
}
