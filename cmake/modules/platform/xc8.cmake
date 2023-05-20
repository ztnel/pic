cmake_minimum_required(VERSION 3.22)

if(NOT TOOLCHAIN_ROOT)
  message(FATAL_ERROR
    "No Microchip XC8 compiler was found. Please provide the path"
    " to an XC8 installation on the command line, for example:\n"
    "    cmake -DTOOLCHAIN_ROOT=/opt/microchip/xc8/v2.00 .."
  )
endif()

set(CMAKE_FIND_ROOT_PATH "${TOOLCHAIN_ROOT}")
message(STATUS "Discovering XC8 executables.")
find_program(CMAKE_C_COMPILER "xc8-cc"
  PATHS "${TOOLCHAIN_ROOT}"
  PATH_SUFFIXES "bin"
)

find_program(CMAKE_AR "xc8-ar"
  PATHS "${TOOLCHAIN_ROOT}"
  PATH_SUFFIXES "bin"
)

find_program(XC8_OBJCPY "avr-objcopy"
  PATHS "${TOOLCHAIN_ROOT}"
  PATH_SUFFIXES "bin"
)
find_program(XC8_OBJDUMP "avr-objdump"
  PATHS "${TOOLCHAIN_ROOT}"
  PATH_SUFFIXES "bin"
)

set(CMAKE_C_COMPILER_ID_RUN 1)
set(CMAKE_C_COMPILER_ID "XC8-CC")
set(CMAKE_C_OUTPUT_EXTENSION ".p1")

set(CMAKE_C_COMPILE_OBJECT)
string(APPEND CMAKE_C_COMPILE_OBJECT
  "<CMAKE_C_COMPILER> <FLAGS> <DEFINES> <INCLUDES>"
  "   -o<OBJECT>   -c <SOURCE>"
)

set(CMAKE_C_LINK_EXECUTABLE)
string(APPEND CMAKE_C_LINK_EXECUTABLE
  "<CMAKE_C_COMPILER> <FLAGS> <CMAKE_C_LINK_FLAGS> <LINK_FLAGS>"
  "   <OBJECTS>   <LINK_LIBRARIES>"
  "   -o<TARGET>"
)

set(CMAKE_C_CREATE_STATIC_LIBRARY)
string(APPEND CMAKE_C_CREATE_STATIC_LIBRARY
  "<CMAKE_AR> -r <TARGET>"
  " <OBJECTS> <LINK_LIBRARIES>"
)