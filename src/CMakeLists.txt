include(FetchContent)

FetchContent_Declare(fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

add_executable(hello-world first_file.cpp)

target_link_libraries(hello-world fmt::fmt)
target_include_directories(hello-world PUBLIC ${CMAKE_SOURCE_DIR}/include)