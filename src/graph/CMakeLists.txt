# Variables
set(PRIVATE_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include/private/)
set(PUBLIC_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include/public/)
set(HEADERS 
${PUBLIC_INCLUDE_DIRS}/graph/graph.hpp
${PUBLIC_INCLUDE_DIRS}/graph/unweighted_graph.hpp
)
set(SOURCES unweighted_graph.cpp)
set(LIB graph)

# Find Packages

# Binaries
add_library(${LIB} STATIC ${SOURCES} ${HEADERS})

# Inludes
target_include_directories(${LIB} 
    PRIVATE ${PRIVATE_INCLUDE_DIRS}
    PUBLIC  ${PUBLIC_INCLUDE_DIRS}
)

# Linkging
