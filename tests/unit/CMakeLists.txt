cmake_minimum_required(VERSION 3.16)

#--------- GET PROPETIES ---------
get_property(TIME VARIABLE PROPERTY TIME)
get_property(Log VARIABLE PROPERTY Log)

#--------- SET ---------
file(GLOB SOURCE_TEST *.cpp)


Log("[${TIME}] tests/unit/CMakeLists.txt: added includes to gtest")

add_executable(unit_tests ${SOURCE_TEST})

#--------- LINKS AND INCLUDES ---------
target_include_directories(unit_tests PUBLIC gtest-1.6.0)
target_include_directories(unit_tests PUBLIC ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(unit_tests gtest )
target_link_libraries(unit_tests MathC)
Log("[${TIME}] tests/unit/CMakeLists.txt: linked libs for unit tests")

add_dependencies(unit_tests MathC)


enable_testing()
add_test(unit_tests unit_tests)
Log("[${TIME}] tests/unit/CMakeLists.txt: added unit tests")

