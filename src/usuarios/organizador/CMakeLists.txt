add_library(organizador organizador.cc organizador.h)
target_include_directories(organizador PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(organizador PUBLIC act_academica)
target_link_libraries(organizador PUBLIC usuario)

add_executable(organizador-main organizador-main.cc)
target_link_libraries(organizador-main PUBLIC organizador)
