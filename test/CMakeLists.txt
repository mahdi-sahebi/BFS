option(BUILD_TESTS "To enable tests" ON)

if (BUILD_TESTS)
    # Variables
    set(TEST test_${PROJECT_NAME})
    set(TEST_SOURCES ${PROJECT_SOURCE_DIR}/test/test_bfs.cpp)

    # Find Pacakges
    find_package(GTest REQUIRED)

    # Executables
    add_executable(${TEST} ${TEST_SOURCES})

    # Linking
    target_link_libraries(${TEST} 
        PRIVATE GTest::gtest graph bfs
    )

    # Include Directories
    target_include_directories(${TEST}
        PRIVATE ${GTEST_INCLUDE_DIRS}
    )
endif()
