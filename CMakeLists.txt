cmake_minimum_required(VERSION 3.25)
project(apcsQuestions)

set(CMAKE_CXX_STANDARD 14)

file (GLOB files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable(${exe} ${file})
endforeach ()