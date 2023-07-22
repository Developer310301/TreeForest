cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME TreeForestTest)
set(LIBRARY_NAME TreeForest)

project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# Set the output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Create a static library from the files in include and src folders
file(GLOB_RECURSE LIBRARY_HEADERS include/*.h)
file(GLOB_RECURSE LIBRARY_SOURCES src/*.cpp)

add_library(${LIBRARY_NAME} STATIC
    ${LIBRARY_HEADERS}
    ${LIBRARY_SOURCES}
)

set_target_properties(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# Add include directories for the library
target_include_directories(${LIBRARY_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Create an executable from main.cpp in the test folder
add_executable(${PROJECT_NAME}
    test/main.cpp
)

# Link the executable to the library
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${LIBRARY_NAME}
)

# Add include directories for the executable
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)