#https://www.youtube.com/watch?v=7sg88N_bDI0 video for cmake and SFML 
# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.24.2)

# project name
project(sfml-project)

# # set the C++14 standard
set(CMAKE_CXX_STANDARD 17)

# for header files 
# include_directories( ${SFML_INCLUDE_DIRS} )
# include_directories(
# 		${PROJECT_SOURCE_DIR}/lib
# 		${PROJECT_SOURCE_DIR}/src
# )

file( GLOB LIB_SOURCES src/*.cpp )
file( GLOB LIB_HEADERS lib/*.hpp )

add_executable(app ${LIB_SOURCES} ${LIB_HEADERS}) 
# add_executable(app src/Collision.cpp src/Game.cpp src/main.cpp src/Platform.cpp src/Player.cpp lib/Collision.hpp lib/DEFINITIONS.hpp lib/Game.hpp lib/Platform.hpp lib/Player.hpp) 

# # I../includes
include_directories(includes usr/include C:/SFML-2.5.1/include) 


# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
# set(SFML_DIR "C:\\SFML-2.5.1\\lib\\cmake\\SFML")
# find_package(SFML COMPONENTS audio graphics window system network REQUIRED)

set(SFML_ROOT C:/SFML-2.5.1)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics audio network)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(app ${SFML_LIBRARIES})
endif()


# Copy dlls to build directory
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()






#find sfml libraries for linking (nameOfProject path)
#use relative path to specify root folder ${CMAKE_SOURCE_DIR}/lib/ 
# target_link_libraries(app sfml-graphics sfml-window sfml-system sfml-network sfml-audio)

# target_link_libraries(app ${CMAKE_SOURCE_DIR}/lib/sfml-window-d-2.dll)

#<------------------------------------------------------------------------------------>

# cmake_minimum_required(VERSION 3.24.2)
# project(app VERSION 1.0)
# include(FetchContent)
# set(BUILD_SHARED_LIBS OFF)
# FetchContent_Declare(
#  SFML
#  GIT_REPOSITORY https://github.com/SFML/SFML.git
#  GIT_TAG 2.5.1
# )
# FetchContent_MakeAvailable(SFML)
# file( GLOB LIB_SOURCES src/*.cpp )
# file( GLOB LIB_HEADERS lib/*.h )


# add_library(lib1 ${LIB_SOURCES})
# target_include_directories(lib1
# 	PUBLIC
# 		include
# 	PRIVATE
# 		src
# )
# # include_directories(${SFML_INCLUDE_DIR})
# # target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
# # install(TARGETS ${EXECUTABLE_NAME} DESTINATION ${PROJECT_BINARY_DIR}/bin)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED true)
# add_executable(app ${LIB_SOURCES} ${LIB_HEADERS}) 
# target_link_libraries(app sfml-graphics sfml-window sfml-system sfml-network sfml-audio)

#<------------------------------------------------------------------------------------>
