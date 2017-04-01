cmake_minimum_required(VERSION 3.5)
project(cqBG)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

add_subdirectory(colorquant)

set(CMAKE_BUILD_TYPE Debug)

find_package(XCB REQUIRED COMPONENTS xcb xcb_image)
find_package(SFML REQUIRED COMPONENTS system window graphics)

include_directories(
	${cqBG_SOURCE_DIR}/include
	${ColorQuant_SOURCE_DIR}/include
	${XCB_INCLUDE_DIRS}
	${SFML_INCLUDE_DIRS}
)

file(GLOB_RECURSE sources_cq ${cqBG_SOURCE_DIR}/src/*.cpp)

add_executable(cqBG ${sources_cq})

target_link_libraries(cqBG ColorQuant
	${XCB_LIBRARIES}
	${SFML_LIBRARIES}
)
