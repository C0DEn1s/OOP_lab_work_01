cmake_minimum_required(VERSION 3.17)
project(lab_work_01)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_work_01 main.cpp text_editor.cpp text_editor.h history_revisions.h test.h test.cpp Stack.h history_revisions.cpp)