cmake_minimum_required(VERSION 3.16)
# ---------- FILES ----------
file(MAKE_DIRECTORY lib)
file(GLOB SRC_LIST src/*.cpp)
file(GLOB HEADER_LIST include/*.h)

# ---------- SETS ----------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")
string(TIMESTAMP GET_TIME "%Y.%m.%d %H:%M:%S")
set(TIME ${GET_TIME} CACHE INTERNAL "time")
set(CACHE_LOG ${Log} CACHE INTERNAL "log")
set(LOG_BUILD OFF CACHE INTERNAL "")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# ---------- OPTIONS ----------
option(LOG_BUILD "LOG_BUILD" OFF)
option(WITH_TESTS "WITH_TESTS" OFF)

#---------- PROGRAMM PROPERTIES ----------
set_property(CACHE TIME PROPERTY VALUE ${GET_TIME})
set_property(CACHE CACHE_LOG PROPERTY VALUE)

#---------- PROGRAMM MACRO ----------
function(Log textlog) 
    if(${LOG_BUILD})
        message(${textlog})
    endif()
endfunction()

project(NeuronC VERSION 0.1 DESCRIPTION "A lib for neural networks")

find_package(MathC CONFIG REQUIRED)
include_directories(include)
include(GNUInstallDirs)

if (${WITH_TESTS})
    add_subdirectory(tests)
endif()

add_library(NeuronC SHARED ${SRC_LIST})

set_target_properties(NeuronC PROPERTIES VERSION ${PROJECT_VERSION})

configure_file(NeuronC.pc.in NeuronC.pc @ONLY)

install(TARGETS NeuronC
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${HEADER_LIST} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} )
install(FILES ${CMAKE_BINARY_DIR}/NeuronC.pc 
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

install(FILES cmake/NeuronCConfig.cmake DESTINATION lib/cmake/NeuronC)