#pragma once

#include "VulkanContext.h"

class HelloTriangleApp{
public:
    void Run();
private:
    void InitWindow();
    void InitVulkan();

    void MainLoop();
    void Cleanup();

    GLFWwindow* m_Window;
    VulkanContext m_Context;
};
