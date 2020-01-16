cmake_minimum_required(VERSION 3.0)

# set the project name
project(RPC-ECHO)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -pthread")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add the include path

# add the jsoncpp libraries
find_package(PkgConfig REQUIRED)
include_directories("${JSONCPP_INCLUDE_DIRS}")
pkg_check_modules(JSONCPP jsoncpp)
link_libraries(${JSONCPP_LIBRARIES})

# add the boost libraries
find_package(Boost 1.55.0 REQUIRED COMPONENTS system filesystem)
include_directories(... ${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

# add the executable
add_executable(RPC-ECHO main.cpp echo_rpc.cpp rpc_base.cpp)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(RPC-ECHO PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )

target_link_libraries(RPC-ECHO PUBLIC ${EXTRA_LIBS} ${JSONCPP_LIBRARIES} ${Boost_LIBRARIES})
