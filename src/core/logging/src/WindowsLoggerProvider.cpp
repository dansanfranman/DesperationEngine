#include "WindowsLoggerProvider.h"

#define assertm(exp, msg) assert(((void)msg, exp))

void WindowsLoggerProvider::Init()
{
        consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        assertm(consoleHandle != NULL, "Unable to acquire Windows console handle.");
}

void WindowsLoggerProvider::Log(const char* message) const
{
        const char* file = "";
        WindowsLoggerProvider::Log(message, file, 0);
}

void WindowsLoggerProvider::Log(const char* message, const char* file, int line) const
{
        assertm(consoleHandle != NULL, "No Windows console handle.");
        SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN);
        std::cout << message << " --- " << file << "(" << line << ")" << std::endl;
        SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}

void WindowsLoggerProvider::Error(const char* message, const char* file, int line) const
{
        assertm(consoleHandle != NULL, "No Windows console handle.");
        SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED);
        std::cerr << message << " --- " << file << "(" << line << ")" << std::endl;
        SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}

WindowsLoggerProvider::~WindowsLoggerProvider()
{
        
}
