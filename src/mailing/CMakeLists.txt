add_library(mailing mailing.cc mailing.h)
target_include_directories(mailing PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(mailing PUBLIC alumno)
target_link_libraries(mailing PUBLIC usuario)

add_executable(mailing-main mailing-main.cc)
target_link_libraries(mailing-main PUBLIC mailing)