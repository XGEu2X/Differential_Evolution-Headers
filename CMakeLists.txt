cmake_minimum_required (VERSION 3.8)

project ("DIFFERENTIAL_EVOLUTION-HEADERS")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#Chooses optimization depending which compiler is used.
if(UNIX) 
    message(STATUS ">>> Linux")
	set(CMAKE_BUILD_TYPE Release)
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
elseif(WIN32)
    message(STATUS ">>> Windows")
    set(CMAKE_CXX_FLAGS_RELEASE "-Ox")
endif()

#set(BUILD_STATIC_LIBS ON)
#set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

#To use gtest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()
