cmake_minimum_required (VERSION 3.8)
set(CXX_STANDARD 17)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("BrainFuck")

set( EXEC_FILES
	"src/main.cpp"
	"src/BrainFuck.h"
	"src/BrainFuck.cpp"
	"src/Memory.h"
	"src/Memory.cpp"
	"src/Optimizer.h"
	"src/Optimizer.cpp"
)
add_executable (${PROJECT_NAME} ${EXEC_FILES})