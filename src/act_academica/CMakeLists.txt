add_library(act_academica act_academica.cc act_academica.h)

#echo herencia target_link_libraries(basket PUBLIC product)

target_include_directories(act_academica PUBLIC ${CMAKE_CURRENT_LIST_DIR})