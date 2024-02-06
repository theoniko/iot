# Top-level CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(Rtls)

# Set output paths (if needed)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_CFLAGS} -g")
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

## apt-get install libzmq3-dev
# Add ZeroMQ dependency
find_package(ZeroMQ REQUIRED)

add_subdirectory(pb)
add_subdirectory(test)

add_executable(clientApp src/client/Client.cpp)
target_compile_definitions(clientApp PRIVATE cxx_std_20)
target_link_libraries(clientApp PRIVATE myproto zmq)

file(GLOB_RECURSE SERVER_SRC "src/server/*.h" "src/server/*.cpp")


add_library(server  ${SERVER_SRC})
target_link_libraries(server PRIVATE myproto zmq)
option(TESTING OFF)
#target_compile_definitions(server PRIVATE TESTING=0)

# Create an executable named "my_app" using the specified source files.
add_executable(serverApp "src/server/main.cpp")
# Define private compile definitions for the target "my_app".
# In this case, set the C++ standard to C++11.
target_compile_definitions(serverApp PRIVATE cxx_std_20)
# Link the "my_app" target with my protobuf lib.
# this imports the dependencies
target_link_libraries(serverApp PRIVATE myproto zmq server)


