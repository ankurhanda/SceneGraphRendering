# Find Pangolin (https://github.com/stevenlovegrove/Pangolin)
find_package(Pangolin 0.1 REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})

FIND_PACKAGE(CVD REQUIRED)

# Find Scenegraph
include_directories(${CMAKE_BINARY_DIR}/Examples/TextureRender ${SCENEGRAPH_INCLUDE_DIRS} ${CVD_INCLUDE_DIR})

# Set GCC style compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(TextureRender main.cpp)
target_link_libraries(TextureRender ${Pangolin_LIBRARIES})
target_link_libraries(TextureRender   ${CVD_LIBRARY})
target_link_libraries(TextureRender ${SCENEGRAPH_LIBRARIES})
