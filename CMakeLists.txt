cmake_minimum_required(VERSION 3.10)

project(ImageToASCII VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ImageToASCII src/Source/Main.cpp src/Source/Util.cpp)

include_directories("SFML/include")
link_directories("SFML/lib")

target_link_libraries(ImageToASCII
    $<$<CONFIG:Debug>:SFML/lib/sfml-graphics-d>
    $<$<CONFIG:Release>:SFML/lib/sfml-graphics> 
)


