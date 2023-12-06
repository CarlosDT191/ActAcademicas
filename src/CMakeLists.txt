add_library(proyecto prototipos.cc prototipos.h)
target_include_directories(proyecto PUBLIC ${CMAKE_CURRENT_LIST_DIR})
add_executable(proyect-main person-main.cc)
target_link_libraries(proyect-main PUBLIC proyecto)