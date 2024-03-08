#include "Shader.h"

#include <fstream>
#include <stdexcept>

std::vector<char> Shader::ReadFile(const std::string& filename)
{
    std::ifstream file(filename, std::ios::ate | std::ios::binary);

    if (!file)
    {
        const std::string message = "Failed to open file: " + filename + "!";
        throw std::runtime_error(message);
    }

    size_t fileSize = static_cast<size_t>(file.tellg());
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);

    return buffer;
}

VkShaderModule Shader::CreateShaderModule(VkDevice device, 
        const std::vector<char>& code)
{
    VkShaderModuleCreateInfo createInfo{};

    createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    createInfo.codeSize = code.size();
    createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

    VkShaderModule shaderModule;

    auto result = vkCreateShaderModule(
        device, &createInfo, nullptr, &shaderModule        
    );

    if (result != VK_SUCCESS)
        throw std::runtime_error("Failed to create a shader module!");

    return shaderModule;
}
