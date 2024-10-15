file(GLOB test_sources RELATIVE "${CMAKE_CURRENT_LIST_DIR}" "*.cpp")

foreach(test_source ${test_sources})
    string( REPLACE ".cpp" "" test_name ${test_source} )
    add_executable(${test_name} ${test_source})
    if(USE_PERF)
        add_compile_definitions(USE_PERF)
        target_link_libraries(${test_name} tfhe++  profiler)
    else()
        target_link_libraries(${test_name} tfhe++)
    endif()
endforeach(test_source ${test_sources})



