include(FetchContent)

FetchContent_Declare(fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

add_executable(app main.cpp)

target_link_libraries(app fmt::fmt)
target_include_directories(app PUBLIC ${CMAKE_SOURCE_DIR}/include)