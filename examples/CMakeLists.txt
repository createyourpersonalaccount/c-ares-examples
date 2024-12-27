file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

foreach(SOURCE ${SOURCES})
  get_filename_component(EXE ${SOURCE} NAME_WLE)
  add_executable(${EXE} ${SOURCE})
  target_include_directories(${EXE} PUBLIC ${CARES_INCLUDE_DIRS})
  target_link_libraries(${EXE} ${CARES_LIBRARIES})
endforeach()
