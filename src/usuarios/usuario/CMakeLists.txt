add_library(usuario usuario.cc usuario.h)

#echo herencia target_link_libraries(basket PUBLIC product)

target_include_directories(usuario PUBLIC ${CMAKE_CURRENT_LIST_DIR})
