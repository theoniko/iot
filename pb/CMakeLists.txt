find_package(Protobuf REQUIRED)

set(PROTO_FILES position.proto)

add_library(myproto STATIC ${PROTO_FILES} )
target_include_directories(myproto INTERFACE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(myproto
    PUBLIC
        protobuf::libprotobuf
)

protobuf_generate(TARGET myproto LANGUAGE cpp)