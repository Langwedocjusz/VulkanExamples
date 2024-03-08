mkdir -p spirv
glslc shaders/HelloTriangle.vert -o spirv/vert.spv
glslc shaders/HelloTriangle.frag -o spirv/frag.spv
