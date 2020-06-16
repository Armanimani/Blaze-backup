# Googletest
add_subdirectory(googletest)
add_library(GTest::GTest ALIAS gtest)
add_library(GTest::GTest::Main ALIAS gtest_main)
add_library(GTest::GMock ALIAS gmock)
add_library(GTest::GMock::Main ALIAS gmock_main)

# DirectXMath
add_library(DirectXMath INTERFACE)

target_include_directories(DirectXMath INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/DirectXMath/inc>
	$<INSTALL_INTERFACE:DirectXMath/inc> 
)
