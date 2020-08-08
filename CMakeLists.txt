cmake_minimum_required(VERSION 3.0.0)
project(QtProject)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 COMPONENTS Core Gui Qml Quick Widgets Xml Charts OpenGL REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")

set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

set(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -Wall -O0 -g -ggdb")
set(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -Wall -O3")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -Wall -O0 -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -Wall -O3")

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
include_directories("${PROJECT_SOURCE_DIR}/include")
link_directories("${PROJECT_SOURCE_DIR}/lib")
aux_source_directory(src DIR_SRCS)
file(GLOB UI_FILES "src/*.ui")
qt5_wrap_ui(WRAP_FILES ${UI_FILES})
set(RCC_FILES resources.qrc)

add_executable(main ${DIR_SRCS} ${RCC_FILES} ${WRAP_FILES})
target_link_libraries(main pthread)
target_link_libraries(main m)
target_link_libraries(main Qt5::Core Qt5::Gui Qt5::Qml Qt5::Quick Qt5::Widgets Qt5::Xml Qt5::Charts Qt5::OpenGL ${OPENGL_LIBRARIES})
