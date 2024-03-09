#pragma once

#include <iostream>
#include <cassert>

#ifndef DEBUG
#define DELOG(message)
#define DELOGF(message, file, line)
#define DEERROR(message, file, line)
#else
#define DELOG(message) ServiceLocator::GetLogger()->Log(message)
#define DELOGF(message, file, line) ServiceLocator::GetLogger()->Log(message, file, line)
#define DEERROR(message, file, line) ServiceLocator::GetLogger()->Error(message, file, line)
#endif

class Logger
{
        public:
                virtual void Init() = 0;
                virtual void Log(const char* message) const = 0;
                virtual void Log(const char* message, const char* file, int line) const = 0;
                virtual void Error(const char* message, const char* file, int line) const = 0;
                virtual ~Logger() {};
};
