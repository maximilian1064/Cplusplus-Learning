####################  cmake configuration  ###########################

# cmake version
cmake_minimum_required(VERSION 3.0.0)
project(Cplusplus-Learning)

####################  g++ compiler configuration  ####################

# ensure c++ version c++11
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no \
C++11 support. Please use a different C++ compiler.")
endif()

# set warnings as errors
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

####################  make targets  ##################################

# make compiler_learning
file(GLOB Compiler "Compiler@Coursera/*.cpp")
add_executable(compiler_learning ${Compiler})

# make cpp_learning
file(GLOB CPlusPlus "CPP@Coursera/CppStaticMember.cpp")
add_executable(cpp_learning ${CPlusPlus})

####################  aditional make targets  ########################

# make purge
add_custom_target(purge COMMAND rm -r *)

####################  include headers and libraries  #################

# include header
include_directories(Compiler@Coursera/include)
include_directories(CPP@Coursera/include)

