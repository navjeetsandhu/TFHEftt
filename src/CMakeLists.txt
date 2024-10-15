file(GLOB tfhe++_sources "*.cpp")

add_library(tfhe++ STATIC ${tfhe++_sources})

target_include_directories(
  tfhe++
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/thirdparties/spqlios)

if(USE_RANDEN)
  target_link_libraries(tfhe++ INTERFACE randen)
endif()

target_link_libraries(tfhe++ INTERFACE spqlios)


