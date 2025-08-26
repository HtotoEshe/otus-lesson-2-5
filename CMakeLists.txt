cmake_minimum_required(VERSION 3.12)

project(lesson.2-5)

add_executable(lesson_2_5
    main.cpp
)

set(CMAKE_CXX_FLAGS_DEBUG  "-g")
set(CMAKE_BUILD_TYPE Debug)

set_target_properties( PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)