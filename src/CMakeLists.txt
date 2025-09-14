set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(TinyClient WIN32 main.cpp)

target_link_libraries(TinyClient PRIVATE wx::core wx::net wx::base)
