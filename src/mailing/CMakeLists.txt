add_library(mailing mailing.cc mailing.h)

#echo herencia target_link_libraries(alumnos PUBLIC mailing)

target_include_directories(mailing PUBLIC ${CMAKE_CURRENT_LIST_DIR})
