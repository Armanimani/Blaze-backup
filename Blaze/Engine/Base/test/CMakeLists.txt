add_executable(
	blaze_test_engine_base
	test.cpp
)

target_link_libraries(
	blaze_test_engine_base
	PRIVATE Blaze::Engine::Base GTest::GTest GTest::GTest::Main
)

add_test(NAME blaze_test_engine_base COMMAND blaze_test_engine_base)