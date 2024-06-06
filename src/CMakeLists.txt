cmake_minimum_required(VERSION 2.8)
project(pbd)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../)
add_definitions(" -g")

MESSAGE(STATUS "This is SOURCE dir " ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/
    /usr/include/opencv4
    /usr/include/plog
    /usr/local/include/
)


set(link_libs   /usr/local/lib/libaidlite.so
                /usr/local/lib/libsmartvision.so
                /usr/local/lib/libaidlux_ipc.so
                dl
                curl
                jsoncpp
                pthread
                opencv_core
                opencv_videoio
                opencv_imgproc
                opencv_imgcodecs
                opencv_highgui
                opencv_dnn
                opencv_freetype                
                z
                
)

add_executable(svapp  example.cpp model.cpp)
target_link_libraries(svapp ${link_libs})
