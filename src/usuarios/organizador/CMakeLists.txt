add_library(organizador organizador.cc organizador.h)

#echo herencia target_link_libraries(basket PUBLIC product)

target_include_directories(organizador PUBLIC ${CMAKE_CURRENT_LIST_DIR})
