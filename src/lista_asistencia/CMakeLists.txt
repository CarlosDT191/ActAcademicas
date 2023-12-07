add_library(lista_asistencia lista_asistencia.cc lista_asistencia.h)

#echo herencia target_link_libraries(basket PUBLIC product)

target_include_directories(lista_asistencia PUBLIC ${CMAKE_CURRENT_LIST_DIR})
