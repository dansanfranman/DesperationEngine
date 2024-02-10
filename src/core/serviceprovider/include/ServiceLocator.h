#pragma once

#include "Logger.h"

class ServiceLocator
{
        public:
                static const Logger* GetLogger();
                static void SetLogger(const Logger& logger);
                static void ClearRegisteredServices();
        private:
                static const Logger* loggerService;
};
                
