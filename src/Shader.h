#pragma once

#include <GLFW/glfw3.h>

#include <vector>
#include <string>

namespace Shader{
    std::vector<char> ReadFile(const std::string& filename);

    VkShaderModule CreateShaderModule(VkDevice device, 
            const std::vector<char>& code);
}
