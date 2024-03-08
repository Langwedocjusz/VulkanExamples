#include "HelloTriangle.h"

#include <stdexcept>
#include <cstdint>
#include <cstring>
#include <vector>

#include <iostream>
#include <optional>


void HelloTriangleApp::Run()
{
    InitWindow();
    InitVulkan();
    MainLoop();
    Cleanup();
}

void HelloTriangleApp::InitWindow()
{
    constexpr uint32_t WIDTH = 800;
    constexpr uint32_t HEIGHT = 600;

    if(!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW!");

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    m_Window = glfwCreateWindow(
        WIDTH, HEIGHT, "Example", nullptr, nullptr
    );
}

void HelloTriangleApp::InitVulkan()
{
    m_Context.Init(m_Window);
}


void HelloTriangleApp::MainLoop()
{
    while(!glfwWindowShouldClose(m_Window))
    {
        glfwPollEvents();
        m_Context.DrawFrame();
    }

    m_Context.WaitIdle();
}

void HelloTriangleApp::Cleanup()
{
    m_Context.Cleanup();

    glfwDestroyWindow(m_Window);
    glfwTerminate();
}
