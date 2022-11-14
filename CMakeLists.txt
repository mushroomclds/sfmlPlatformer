#https://www.youtube.com/watch?v=7sg88N_bDI0 video for cmake and SFML 
# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.24.2)

# project name
project(sfml-project) #${PROJECT_NAME}

set(CMAKE_CXX_STANDARD 17)

file( GLOB LIB_SOURCES src/*.cpp )
file( GLOB LIB_HEADERS lib/*.hpp )
file( GLOB INCLUDE_HEADERS include/*.hpp )
add_executable(${PROJECT_NAME} ${LIB_SOURCES} ${LIB_HEADERS} ${INCLUDE_HEADERS}) 
#*=============================================================================
#                         SFML 
#=============================================================================*/
set(SFML_ROOT C:/SFML-2.5.1)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML MODULE REQUIRED system window graphics audio network)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    message(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
    message(${SFML_LIBRARIES})
endif()
#*=============================================================================
#                         Boost LOG 
#=============================================================================*/
set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
# set(Boost_INCLUDE_DIR C:/local/boost_1_80_0)
# set(Boost_COMPILER "-vc143")
set(BOOST_ROOT C:/local/boost_1_80_0)
# add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)
set(Boost_DIR C:/local/boost_1_80_0/stage/lib/cmake/Boost-1.80.0/)
find_package(Boost CONFIG REQUIRED log log_setup) 
# include_directories(${Boost_INCLUDE_DIRS})
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    target_link_libraries(sfml-project ${Boost_LIBRARIES})
endif()
#*=============================================================================
#                         Copy dlls to build directory
#=============================================================================*/
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB BOOST_DEP_DLLS "C:/local/boost_1_80_0/lib64-msvc-14.3/*.dll")
    file(COPY ${BOOST_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()

