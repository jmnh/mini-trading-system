cmake_minimum_required(VERSION 3.20)

project(
    MiniTradingSystem
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(
    trading_core
    src/order.cpp
)

target_include_directories(
    trading_core
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_options(
    trading_core
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
)

add_executable(
    trading_app
    src/main.cpp
)

target_link_libraries(
    trading_app
    PRIVATE
        trading_core
)

target_compile_options(
    trading_app
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
)

include(CTest)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)

    add_executable(
        trading_tests
        tests/order_test.cpp
    )

    target_link_libraries(
        trading_tests
        PRIVATE
            trading_core
            GTest::gtest_main
    )

    target_compile_options(
        trading_tests
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Wconversion
    )

    include(GoogleTest)

    gtest_discover_tests(trading_tests)
endif()

option(ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

if(ENABLE_SANITIZERS)
    target_compile_options(
        trading_core
        PRIVATE
            -fsanitize=address,undefined
            -fno-omit-frame-pointer
    )

    target_link_options(
        trading_core
        PRIVATE
            -fsanitize=address,undefined
    )

    target_compile_options(
        trading_app
        PRIVATE
            -fsanitize=address,undefined
            -fno-omit-frame-pointer
    )

    target_link_options(
        trading_app
        PRIVATE
            -fsanitize=address,undefined
    )
endif()