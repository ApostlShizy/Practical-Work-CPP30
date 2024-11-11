cmake_minimum_required(VERSION 3.5.0)
project(CaptureTitle VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_CRP_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG bb01c8db702fb41e5497aee9c0559ddf4bf13749) 
FetchContent_MakeAvailable(cpr)

add_executable(CaptureTitle main.cpp)
target_link_libraries(CaptureTitle PRIVATE cpr::cpr)
