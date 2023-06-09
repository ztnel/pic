set(CMAKE_SYSTEM_NAME xc8)
set(CMAKE_SYSTEM_VERSION 1)

# This avoids running the linker and is intended for use with cross-compiling toolchains
# that cannot link without custom flags or linker scripts.
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(CMAKE_C_COMPILER_WORKS 1)
# set MCU definition for proc headers
set(PIC16F1788_MCU "pic16f1788" CACHE INTERNAL "MCU model")

set(PIC16F1788_COMPILE_FLAGS "-mcpu=${PIC16F1788_MCU} -msummary=file")
set(PIC16F1788_DEBUG_COMPILE_FLAGS "-mdebugger=pickit3")
message(STATUS "Setting compilers.")
set(CMAKE_C_COMPILER ${TOOLCHAIN_ROOT}/bin/xc8-cc CACHE INTERNAL "C Compiler")
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_ROOT}/bin/xc8-ar CACHE INTERNAL "ASM Compiler")

# configure find_program search directives
set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_DIR})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)