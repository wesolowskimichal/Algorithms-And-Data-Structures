cmake_minimum_required(VERSION 3.25)

set(Name
	onp_conversion
)

project(${Name})

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(
	ONP_CONV
	ConvertFromONP.cpp
	ConvertToONP.cpp
)

add_executable(
	tests
	tests.cpp
)

target_link_libraries(
	tests
	GTest::gtest_main
	ONP_CONV
)

include(GoogleTest)
gtest_discover_tests(tests)