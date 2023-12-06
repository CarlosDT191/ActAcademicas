add_library(mailing mailing.cc mailing.h)

#echo herencia target_link_libraries(basket PUBLIC product)

target_include_directories(mailing PUBLIC ${CMAKE_CURRENT_LIST_DIR})
