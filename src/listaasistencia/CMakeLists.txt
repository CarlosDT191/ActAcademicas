add_library(listaasistencia listaasistencia.cc listaasistencia.h)

#echo herencia target_link_libraries(basket PUBLIC product)

target_include_directories(listaasistencia PUBLIC ${CMAKE_CURRENT_LIST_DIR})
