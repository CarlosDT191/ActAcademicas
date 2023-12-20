add_library(director_acad director_acad.cc director_acad.h)
target_include_directories(director_acad PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(director_acad PUBLIC act_academica)
target_link_libraries(director_acad PUBLIC usuario)
target_link_libraries(director_acad PUBLIC lista_asistencia)
target_link_libraries(director_acad PUBLIC mailing)

add_executable(director_acad-main director_acad-main.cc)
target_link_libraries(director_acad-main PUBLIC director_acad)