#include <iostream>

#include "test.h"
#include "RenderingTest.h"
#include "DesperationConfig.h"

int main()
{
        TestClass test;
        RenderingTest renderingTest;
        std::cout << "Hello World!" << " Your version number is: " << DesperationEngine_VERSION_MAJOR << "." << DesperationEngine_VERSION_MINOR << " Your test value is: " << test.GetTest() << std::endl;
        std::cout << "RenderingTest works? " << renderingTest.GetRenderingTestInt() << std::endl;
        return 0;
}
