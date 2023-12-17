add_library(act_academica act_academica.cc act_academica.h)
target_include_directories(act_academica PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_executable(act_academica-main act_academica-main.cc)
target_link_libraries(act_academica-main PUBLIC act_academica)