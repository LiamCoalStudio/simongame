cmake_minimum_required(VERSION 3.17)
project(simongame)

set(CMAKE_CXX_STANDARD 20)

add_library(simongame STATIC sfml.cpp simongame.h)
target_link_libraries(simongame simondev pthread)

install(TARGETS simongame DESTINATION /usr/lib)
install(FILES simongame.h DESTINATION /usr/include)
