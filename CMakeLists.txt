cmake_minimum_required(VERSION 3.22)

# Load toolchain files
set(TOOLCHAIN_ROOT "/Applications/microchip/xc8/v2.41")
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchains/pic16f1788.cmake)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# For debug, no change detected ...
set(CMAKE_VERBOSE_MAKEFILE ON)
# global project name
set(EXECUTABLE "demo")
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# cmake build guard
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.")
endif()

project(
  ${EXECUTABLE}
  LANGUAGES C ASM
  VERSION 0.1.0
  DESCRIPTION "PIC toolchain demo"
)

include(xc8)

set(CMAKE_C_FLAGS "${PIC16F1788_COMPILE_FLAGS} ${GCC_FLAGS}")
set(CMAKE_ASM_FLAGS "${PIC16F178_COMPILE_FLAGS} ${GCC_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${PIC16F178_LINKER_FLAGS}")

configure_xc8()

# set default build type if none specified
if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type was set. Setting build type to 'Release'")
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose cmake build type: Debug Release" FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()

# Options for DEBUG build
set(CMAKE_C_FLAGS_DEBUG "-D__DEBUG -O0 ${PIC16F1788_DEBUG_COMPILE_FLAGS}" CACHE INTERNAL "C Compiler options for debug build type")
set(CMAKE_ASM_FLAGS_DEBUG "-O0" CACHE INTERNAL "ASM Compiler options for debug build type")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "-O0" CACHE INTERNAL "Linker options for debug build type")

# Options for RELEASE build
set(CMAKE_C_FLAGS_RELEASE "-Os" CACHE INTERNAL "C Compiler options for release build type")
set(CMAKE_ASM_FLAGS_RELEASE "-Os" CACHE INTERNAL "ASM Compiler options for release build type")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "-Os" CACHE INTERNAL "Linker options for release build type")

# project config
message(STATUS "Configuring config.h header")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.in config.h @ONLY)

add_executable(
  ${EXECUTABLE}
  src/main.c
  src/interrupts.c
  src/configuration.c
)

target_include_directories(${EXECUTABLE} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(${EXECUTABLE} PRIVATE ${XC8_PIC_INCLUDE})
target_include_directories(${EXECUTABLE} PRIVATE include)
