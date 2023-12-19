add_library(alumno alumno.cc alumno.h)
target_include_directories(alumno PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(alumno PUBLIC act_academica)
target_link_libraries(alumno PUBLIC usuario)

add_executable(alumno-main alumno-main.cc)
target_link_libraries(alumno-main PUBLIC alumno)