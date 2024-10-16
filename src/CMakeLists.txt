file(GLOB tfhe++_sources "*.cpp")

add_library(tfhe++ STATIC ${tfhe++_sources})

target_include_directories(
  tfhe++
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/thirdparties/hexl/hexl/hexl/include
    ${PROJECT_SOURCE_DIR}/thirdparties/spqlios)

if(USE_RANDEN)
  target_link_libraries(tfhe++ INTERFACE randen)
endif()

if(USE_HEXL)
  target_link_libraries(tfhe++ INTERFACE HEXL::hexl)
endif()

target_link_libraries(tfhe++ INTERFACE spqlios)


