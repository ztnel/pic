cmake_minimum_required(VERSION 3.22)

function(configure_xc8)
  set(
    XC8_PIC_INCLUDE
    ${TOOLCHAIN_ROOT}/pic/include
    ${TOOLCHAIN_ROOT}/pic/include/proc
    ${TOOLCHAIN_ROOT}/pic/include/c99
    PARENT_SCOPE
  )
  message(DEBUG "Exporting include paths: ${XC8_PIC_INCLUDE}")
endfunction()
