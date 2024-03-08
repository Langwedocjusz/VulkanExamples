#include "HelloTriangle.h"

#include <iostream>

int main()
{
    HelloTriangleApp app;

    try
    {
        app.Run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    return 0;
}
