cmake_minimum_required(VERSION 3.5)
project(cqbg)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

add_subdirectory(args_parse)
add_subdirectory(rgb_funcs)

set(CMAKE_BUILD_TYPE Release)

find_package(Boost REQUIRED COMPONENTS program_options)
find_package(XCB REQUIRED COMPONENTS xcb xcb_image)
find_package(SFML REQUIRED COMPONENTS system window graphics)

include_directories(
	${${PROJECT_NAME}_SOURCE_DIR}/include
	${ArgsParse_SOURCE_DIR}/include
	${RGBFuncs_SOURCE_DIR}/include
	${Boost_INCLUDE_DIRS}
	${XCB_INCLUDE_DIRS}
	${SFML_INCLUDE_DIRS}
)

file(GLOB_RECURSE SRC_FILES ${${PROJECT_NAME}_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME}
	rgb_funcs
	args_parse
	${Boost_LIBRARIES}
	${XCB_LIBRARIES}
	${SFML_LIBRARIES}
)
