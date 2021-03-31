cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)

project(Laborator6)

set(SOURCE_FILES
        src/domain/Film.cpp
        src/domain/Film.h
        src/repository/FilmRepository.h
        src/repository/FilmRepository.cpp
        src/controller/FilmController.h
        src/controller/FilmController.cpp
        src/ui/UI.h
        src/UI/UI.cpp
        main.cpp src/ValidClass/ValidationClass.cpp src/ValidClass/ValidationClass.h src/html/HTML.cpp HTML.h CSV.h src/repository/FilmInMemoryRepository.h FileNotFoundException.cpp)

add_executable(Laborator_6_run ${SOURCE_FILES})

add_subdirectory(test)