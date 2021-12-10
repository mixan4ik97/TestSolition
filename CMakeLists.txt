cmake_minimum_required(VERSION 3.12.2)
project(calcserver)

#--------------- Files
set(CALCSERVER_SOURCE_FILES filereader.cpp builder.cpp typedetector.cpp  base64decoder.cpp app.cpp textencoder.cpp textdecoder.cpp consolereader.cpp consolewriter.cpp  main.cpp multiplier.cpp    )
file(GLOB CALCSERVER_HEADER_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

#--------------- Visual Studio
if(MSVC)
  include(${CMAKE_CURRENT_SOURCE_DIR}/MsvcRuntime.cmake)
  option(USE_STATIC_MSVC_CRT "Use static visual studio runtime linkage" ON)
  option(USE_SEH_IN_CATCH "Use SEH in catch blocks (/EHa, for testMemManager functionality" OFF)
  configure_msvc_runtime() 
  source_group("Headers" FILES ${CALCSERVER_HEADER_FILES})
  source_group("Sources" FILES ${CALCSERVER_SOURCE_FILES} ${EASYLOGGINGPP_SOURCE_FILES})
  add_compile_options(/D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS /D_CRT_SECURE_NO_WARNINGS /D_WINSOCK_DEPRECATED_NO_WARNINGS)
endif(MSVC)

#--------------- Optimizations
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

#--------------- Includes
include_directories(.)

#--------------- Target
add_executable(calcserver ${CALCSERVER_SOURCE_FILES} ${CALCSERVER_HEADER_FILES})
#target_compile_features(calcserver PRIVATE cxx_std_17)

