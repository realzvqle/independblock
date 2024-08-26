cmake_minimum_required(VERSION 3.10) 
project(IndependBlock) 

set(CMAKE_C_STANDARD 99) 

file(GLOB SOURCES "src/*.c" "src/externincludes/glad.c")  # Adjust if necessary

add_executable(iblock ${SOURCES})

include_directories(src)

target_link_libraries(iblock
    ${CMAKE_SOURCE_DIR}/lib/libSDL2.dll.a
    ${CMAKE_SOURCE_DIR}/lib/libSDL2.a
    ${CMAKE_SOURCE_DIR}/lib/libpsapi.a
    psapi
)

target_compile_options(iblock PRIVATE
    -mwindows
    -O2
    -D_WIN32_WINNT=0x0600
    -DWINVER=0x0600
    -DPSAPI_VERSION=1
    -mwindows
)

add_custom_command(
    TARGET iblock
    POST_BUILD
    COMMAND iblock
)


