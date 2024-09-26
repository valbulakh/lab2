cmake_minimum_required(VERSION 3.5)

project(lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab2 main.cpp) # добавление исполняемого файла к проекту (ИМЯ_ПРОЕКТА ИМЯ_ФАЙЛА)

add_subdirectory(libs/generator) # добавление файлового пути
target_link_libraries(lab2 generator) # подключение библиотеки (ИМЯ_ПРОЕКТА ИМЯ_ЛИБЫ)

add_subdirectory(libs/writer)
target_link_libraries(lab2 writer)
