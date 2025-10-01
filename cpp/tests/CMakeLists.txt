add_executable(test_array test_array.cpp)
target_link_libraries(test_array PRIVATE dsa dsa_core)
add_test(NAME array COMMAND test_array)


