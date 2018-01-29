cmake_minimum_required(VERSION 3.9)
project(MMGGA)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/externals)

include_directories(include ${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE MMGGA_SRC src/*/*.cpp include/*.h)

#SFML
set(SFML_DIR ${EXTERNAL_DIR}/SFML)
set(SFML_BUILD_EXAMPLES FALSE)
set(BUILD_SHARED_LIBS TRUE)
add_subdirectory(${SFML_DIR})
include_directories(${SFML_DIR}/include)
LIST(APPEND MMGGA_LIBRARIES
	sfml-system
	sfml-window
	sfml-graphics
	sfml-audio
	sfml-network)

#SFML Imgui
set(SFML_IMGUI ${EXTERNAL_DIR}/imgui-sfml/)
set(IMGUI_ROOT ${EXTERNAL_DIR}/imgui/)

set(SFML_ROOT ${EXTERNAL_DIR}/SFML/)
add_subdirectory(${SFML_IMGUI})
include_directories(${IMGUI_ROOT} ${SFML_IMGUI})
LIST(APPEND MMGGA_LIBRARIES 
	imgui-sfml)


#JSON
set(JSON_DIR ${EXTERNAL_DIR}/json/)
add_subdirectory(${JSON_DIR})
include_directories(${JSON_DIR}/src/)
LIST(APPEND MMGGA_LIBRARIES
	nlohmann_json)

#PYTHON
IF(NOT WIN32)
	add_definitions(-Wall -Wextra -pedantic -std=c++11)

	IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
		add_definitions(-g -O0)
	ELSE()
		add_definitions(-O3)
	ENDIF()

	LIST(APPEND MMGGA_LIBRARIES resolv)
ELSE()
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
ENDIF()


find_package(PythonLibs 3 EXACT REQUIRED)

include_directories(${PYTHON_INCLUDE_DIR})

LIST(APPEND MMGGA_LIBRARIES ${PYTHON_LIBRARY})

#PYBIND11
set(PYBIND11_DIR ${EXTERNAL_DIR}/pybind11/)
add_subdirectory(${PYBIND11_DIR})
include_directories(${PYBIND11_DIR})
LIST(APPEND MMGGA_LIBRARIES
  pybind11)

#MMGGA
if(NOT WIN32)
LIST(APPEND MMGGA_LIBRARIES
  stdc++fs)
ENDIF()


 
#MMGGA
add_executable(MMGGA src/main.cpp ${MMGGA_SRC})
target_link_libraries(MMGGA ${MMGGA_LIBRARIES})

#MMGGA_TEST
SET(MMGGA_TEST_DIR ${CMAKE_SOURCE_DIR}/tests)
file(GLOB TEST_FILES ${MMGGA_TEST_DIR}/*.cpp )
foreach(test_file ${TEST_FILES} )
    # I used a simple string replace, to cut off .cpp.
    file(RELATIVE_PATH test_relative_path ${MMGGA_TEST_DIR} ${test_file})
    string( REPLACE ".cpp" "" test_name ${test_relative_path} )
    add_executable(${test_name} ${MMGGA_TEST_DIR}/${test_relative_path} ${MMGGA_SRC})
    # Make sure YourLib is linked to each app
    target_link_libraries(${test_name} ${MMGGA_LIBRARIES})
endforeach()

