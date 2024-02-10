#include "WindowsLoggerProvider.h"

#define assertm(exp, msg) assert(((void)msg, exp))

void WindowsLoggerProvider::Init()
{
        consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        assertm(consoleHandle != NULL, "Unable to acquire Windows console handle.");
}

void WindowsLoggerProvider::Log(const char* message) const
{
        WindowsLoggerProvider::Log(message, nullptr, 0);
}

void WindowsLoggerProvider::Log(const char* message, const char* file, int line) const
{
        assertm(consoleHandle != NULL, "No Windows console handle.");
        SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN);
        std::cout << message << " --- in file: " << file << " --- on line: " << line << std::endl;
        SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}

void WindowsLoggerProvider::Error(const char* message, const char* file, int line) const
{
        assertm(consoleHandle != NULL, "No Windows console handle.");
        SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED);
        std::cerr << message << " --- in file: " << file << " --- on line: " << line << std::endl;
        SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}

WindowsLoggerProvider::~WindowsLoggerProvider()
{
        
}
