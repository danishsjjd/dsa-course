cmake_minimum_required(VERSION 3.16)

project(cpp_dsa
  VERSION 0.1.0
  DESCRIPTION "C++ Data Structures and Algorithms Practice"
  LANGUAGES CXX
)

# Options
option(DSA_BUILD_TESTS "Build tests" ON)
option(DSA_WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)

# Global compile options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
  add_compile_options(/W4)
  if(DSA_WARNINGS_AS_ERRORS)
    add_compile_options(/WX)
  endif()
else()
  add_compile_options(-Wall -Wextra -pedantic)
  if(DSA_WARNINGS_AS_ERRORS)
    add_compile_options(-Werror)
  endif()
endif()

# Header-only interface library for shared include path
add_library(dsa INTERFACE)
target_include_directories(dsa INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

add_subdirectory(src)
if(DSA_BUILD_TESTS)
  add_subdirectory(tests)
endif()
