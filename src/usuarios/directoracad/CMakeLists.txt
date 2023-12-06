add_library(directoracad directoracad.cc directoracad.h)

#echo herencia target_link_libraries(basket PUBLIC product)

target_include_directories(directoracad PUBLIC ${CMAKE_CURRENT_LIST_DIR})
