cmake_minimum_required (VERSION 3.8)
set(CXX_STANDARD 17)

set( EXEC_FILES
	"main.cpp"
	"BrainFuck.h"
	"BrainFuck.cpp"
	"Memory.h"
	"Memory.cpp"
)
add_executable (${PROJECT_NAME} ${EXEC_FILES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()