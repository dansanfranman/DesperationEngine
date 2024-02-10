#include "ServiceLocator.h"

Logger* ServiceLocator::loggerService = nullptr;

Logger* ServiceLocator::GetLogger()
{
        return loggerService;
}

void ServiceLocator::SetLogger(Logger* logger)
{
        logger->Init();
        ServiceLocator::loggerService = logger;
}

void ServiceLocator::ClearRegisteredServices()
{
        delete loggerService;
}
