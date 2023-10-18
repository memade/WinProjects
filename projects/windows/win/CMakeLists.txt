project(${entry_name})

GLOBAL_ENUM_DIR_SOURCE(${entry} HEADS SRCS)
set(SOURCES
${SRCS}
${HEADS}
)

add_definitions(-DSHARED_API)
add_definitions(-DWIN32_LEAN_AND_MEAN)
add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME}
PRIVATE
${entry}/
${CMAKE_CURRENT_SOURCE_DIR}/../../include/
${SOLUTION_INCLUDE_DIR}
${SOLUTION_ROOT_DIR}/third_party/
)
  
target_link_directories(${PROJECT_NAME}
PRIVATE
${SOLUTION_ROOT_DIR}/libs/runtimes/${CMAKE_VS_PLATFORM_NAME}/
${SOLUTION_ROOT_DIR}/libs/third_party/${CMAKE_VS_PLATFORM_NAME}/
)

if(MSVC)
MSVC_LINK_FLAGS_SET_CONSOLE(${PROJECT_NAME})
MSVC_CRT_SET(${PROJECT_NAME} "/MT")
MSVC_USE_PCH(${PROJECT_NAME} ${entry}/stdafx.h ${entry}/stdafx.cpp)
endif()