cmake_minimum_required(VERSION 2.8)

include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(test_boost_asio)

add_subdirectory(patterns)

if(WITH_JAVA)
    add_subdirectory(JavaTest)
endif()

add_subdirectory(highload)

add_subdirectory(embedding)

add_subdirectory(exceptions)

add_subdirectory(io)

add_subdirectory(sorts)

add_subdirectory(algorithms)

add_subdirectory(performance)

if(WITH_GUI)
    add_subdirectory(gui)
endif()

add_subdirectory(metaprogramming)

add_subdirectory(custom_literals)

add_subdirectory(system)

add_subdirectory(format_class)

add_subdirectory(vector_by_rule)

add_subdirectory(initializer_list)

add_subdirectory(check_valid)

add_subdirectory(pretty_typeid)

add_subdirectory(classes)

add_subdirectory(methods_ref_qualifiers)