add_library(actacademica actacademica.cc actacademica.h)

#echo herencia target_link_libraries(basket PUBLIC product)

target_include_directories(actacademica PUBLIC ${CMAKE_CURRENT_LIST_DIR})
