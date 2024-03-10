cmake_minimum_required(VERSION 3.28.3)

project(VulkanExamples)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(
    Examples
    src/main.cpp
    src/HelloTriangle.h
    src/HelloTriangle.cpp
    src/VulkanContext.h
    src/VulkanContext.cpp
    src/VkHelpers.h
    src/VkHelpers.cpp
    src/Shader.h
    src/Shader.cpp
)


target_compile_definitions(
    Examples 
    PUBLIC 
    "ENABLE_VULKAN_VALIDATION"
    "GLFW_INCLUDE_VULKAN")

find_package(Vulkan REQUIRED)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)

target_link_libraries(Examples PUBLIC Vulkan::Vulkan glfw glm)

#Set Visual Studio start project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Examples)
#Set Visual Studio Debugger working directory
set_property(TARGET Examples PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
