
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

enable_testing()
file(GLOB_RECURSE SOURCES   "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(
  test
  ${SOURCES}
)

target_link_libraries(
  test
  PRIVATE
  GTest::gtest
  GTest::gmock
  server
)
option(TESTING ON)