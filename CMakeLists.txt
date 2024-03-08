cmake_minimum_required(VERSION 3.28.3)

project(VulkanExamples)

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
