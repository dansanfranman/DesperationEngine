#include <windows.h>
#include "Logger.h"

class WindowsLoggerProvider : public Logger
{
        public:
                virtual void Init();
                virtual void Log(const char* message) const;
                virtual void Log(const char* message, const char* file, int line) const; 
                virtual void Error(const char* message, const char* file, int line) const;
                ~WindowsLoggerProvider(); 
        private:
                HANDLE consoleHandle;
};
