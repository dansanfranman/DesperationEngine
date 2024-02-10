#include "ServiceLocator.h"

const Logger* ServiceLocator::loggerService = nullptr;

const Logger* ServiceLocator::GetLogger()
{
        return loggerService;
}

void ServiceLocator::SetLogger(const Logger& logger)
{
        ServiceLocator::loggerService = &logger;
}

void ServiceLocator::ClearRegisteredServices()
{
        delete &loggerService;
}
