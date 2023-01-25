#include <iostream>
#include "vulkan/vulkan.hpp"

int main()
{
	std::vector<const char *> extNames;
	extNames.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
	extNames.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);

	VkInstance  instance;
	VkInstanceCreateInfo instanceInfo = {};
	instanceInfo.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
	instanceInfo.enabledExtensionCount = static_cast<uint32_t>(extNames.size());
	instanceInfo.ppEnabledExtensionNames = extNames.data();

	VkResult result = vkCreateInstance(&instanceInfo, NULL, &instance);

	if (result == VK_SUCCESS) {
		printf("Instance created successfully.");
	} else {
		printf("Instance created failed with error_code %d \n", result);
	}
	return 0;
}
