# https://github.com/sohneg/Protobuf_basics_cpp/blob/main/proto/CMakeLists.txt
find_package(Protobuf REQUIRED)
#
# Protobuf/Grpc source files
#
set(PROTO_FILES position.proto)

#
# Add Library target with protobuf sources
#

add_library(myproto STATIC ${PROTO_FILES} )
target_include_directories(myproto INTERFACE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(myproto
    PUBLIC
        protobuf::libprotobuf
)

protobuf_generate(TARGET myproto LANGUAGE cpp)