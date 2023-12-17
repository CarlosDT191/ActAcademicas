add_library(director_acad director_acad.cc director_acad.h)

#echo herencia target_link_libraries(basket PUBLIC product)

target_include_directories(director_acad PUBLIC ${CMAKE_CURRENT_LIST_DIR})
