# Variables
set(PRIVATE_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include/private/algorithms/)
set(PUBLIC_INCLUDE_DIRS  ${PROJECT_SOURCE_DIR}/include/public/algorithms/)
set(HEADERS 
    ${PUBLIC_INCLUDE_DIRS}/bfs/bfs.hpp
)
set(SOURCES bfs.cpp)
set(LIB bfs)

# Find Packages

# Binaries
add_library(${LIB} STATIC ${SOURCES} ${HEADERS})

# Inludes
target_include_directories(${LIB} 
    PRIVATE ${PRIVATE_INCLUDE_DIRS}
    PUBLIC  ${PUBLIC_INCLUDE_DIRS}
)

# Linkging
target_link_libraries(${LIB}
    PUBLIC graph
)
