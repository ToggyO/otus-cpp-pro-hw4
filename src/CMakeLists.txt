cmake_minimum_required(VERSION 3.12)

project(print_ip.src)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

add_executable(${INSTALL_TARGET} ${SOURCES})
set_target_properties(${INSTALL_TARGET} PROPERTIES LINKER_LANGUAGE CXX)

add_library(${INSTALL_TARGET_LIB_BINARY} STATIC ${SOURCES})
set_target_properties(${INSTALL_TARGET_LIB_BINARY} PROPERTIES LINKER_LANGUAGE CXX)
