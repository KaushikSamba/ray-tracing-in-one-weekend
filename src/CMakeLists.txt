include(FetchContent)

FetchContent_Declare(fmt 
    GIT_REPOSITORY  https://github.com/fmtlib/fmt.git
    GIT_TAG         master
)
FetchContent_MakeAvailable(fmt)

add_executable(hello-world first_file.cpp)

target_link_libraries(hello-world fmt::fmt)