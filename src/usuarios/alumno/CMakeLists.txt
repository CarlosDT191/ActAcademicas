add_library(alumno alumno.cc alumno.h)

#echo herencia target_link_libraries(basket PUBLIC product)

target_include_directories(alumno PUBLIC ${CMAKE_CURRENT_LIST_DIR})
