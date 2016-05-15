project(msgcc-test)

include_directories("${GTEST_ROOT}/include"
                                      "${CMAKE_CURRENT_SOURCE_DIR}")

link_directories("${GTEST_ROOT}/lib")

file(GLOB_RECURSE files *.h *.cpp)

add_executable(msgcc-test ${files})

target_link_libraries(msgcc-test ccinfra gtest pthread)

