cmake_minimum_required(VERSION 3.16)

get_property(TIME VARIABLE PROPERTY TIME)
get_property(Log VARIABLE PROPERTY Log)

add_subdirectory(unit)
Log("[${TIME}] tests/CMakeLists.txt: added unit test")