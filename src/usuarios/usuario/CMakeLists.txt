add_library(usuario usuario.cc usuario.h)
target_include_directories(usuario PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_executable(usuario-main usuario-main.cc)
target_link_libraries(usuario-main PUBLIC usuario)

