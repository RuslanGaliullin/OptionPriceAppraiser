cmake_minimum_required(VERSION 3.0)
project(OptionPrice CXX)
set(CMAKE_CXX_STANDARD 20)

#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -O0 -g")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-sanitize=address -fno-sanitize=undefined -O0 -Werror=return-type")

add_executable(${PROJECT_NAME} src/main.cpp src/process/Process.hpp src/process/CompositePoissonProcess/CompositePoissonProcess.hpp src/process/WienerProcess/WienerProcess.hpp src/process/CompositePoissonProcess/CompositePoissonProcess.cpp src/process/WienerProcess/WienerProcess.cpp src/model/Model.cpp src/model/Model.hpp)