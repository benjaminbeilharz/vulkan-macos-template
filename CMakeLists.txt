cmake_minimum_required(VERSION 3.7.1)
project(vulkan-sample)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        #brew headers
        /opt/homebrew/include
        /usr/local/include
)
link_directories(
        #brew lib
        /opt/homebrew/lib
        /usr/local/lib
)

# add the executable
file(GLOB SOURCE_FILES CONFIGURE_DEPENDS "src/*.h" "src/*.cpp" "src/vulkan/*.cpp")
add_executable(
        app
        ${SOURCE_FILES}
)

target_link_libraries(app PRIVATE vulkan glfw)