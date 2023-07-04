cmake_minimum_required(VERSION 3.5)
# add_compile_options("-fconcepts")
# add_compile_options("-Wall")

project(csconfig)

# Specify the output directories for the binary files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/bin)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/release)

# list(FILTER SRC_LIST EXCLUDE REGEX "path")
# aux_source_directory(./src SRC_LIST)
set(MAIN "./exec/main.cc")
file(GLOB CODE_DIRECT "./src" "./src/*")
file(GLOB CODE_HEADER "./src/*.h" "./src/*/*.h")
file(GLOB CODE_SOURCE "./src/*.cc" "./src/*/*.cc")

include_directories(${CODE_DIRECT})
# link_directories(./lib)
# target_link_libraries(csconfig)

add_executable(csconfig ${MAIN} ${CODE_SOURCE})