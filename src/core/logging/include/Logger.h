#pragma once

#include <iostream>
#include <cassert>

class Logger
{
        public:
                virtual void Init() = 0;
                virtual void Log(const char* message) const = 0;
                virtual void Log(const char* message, const char* file, int line) const = 0;
                virtual void Error(const char* message, const char* file, int line) const = 0;
                virtual ~Logger() {};
};
