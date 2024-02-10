#pragma once

#include "Logger.h"

class ServiceLocator
{
        public:
                static Logger* GetLogger();
                static void SetLogger(Logger* logger);
                static void ClearRegisteredServices();
        private:
                static Logger* loggerService;
};

