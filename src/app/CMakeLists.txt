add_library(app prototipos.cc prototipos.h)
target_include_directories(app PUBLIC ${CMAKE_CURRENT_LIST_DIR})
add_executable(proyect-main proyect-main.cc)
target_link_libraries(proyect-main PUBLIC app)