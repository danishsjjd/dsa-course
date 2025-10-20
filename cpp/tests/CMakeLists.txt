add_executable(array_tests array_tests.cpp)
target_link_libraries(array_tests PRIVATE dsa dsa_core)
add_test(NAME array COMMAND array_tests)

add_executable(linked_list_tests linked_list_tests.cpp)
target_link_libraries(linked_list_tests PRIVATE dsa dsa_core)
add_test(NAME linked_list COMMAND linked_list_tests)


