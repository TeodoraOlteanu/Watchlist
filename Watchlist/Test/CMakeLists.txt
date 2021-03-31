project(test)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(SOURCE_FILES
        ../src/domain/Film.cpp
        ../src/domain/Film.h
        ../src/repository/FilmRepository.cpp
        ../src/repository/FilmRepository.h
        ../src/controller/FilmController.h
        ../src/controller/FilmController.cpp)
add_executable(Google_Tests_run FilmControllerTest.cpp ${SOURCE_FILES})
target_link_libraries(Google_Tests_run gtest gtest_main)