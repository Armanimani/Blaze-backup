add_executable(
	blaze_test_engine_math
	"test_base_types.cpp"
	"test_IntVector2.cpp"
)

target_link_libraries(
	blaze_test_engine_math
	PRIVATE Blaze::Engine::Math GTest::GTest GTest::GTest::Main
	INTERFACE Blaze::ProjectOption
)

add_test(NAME blaze_test_engine_math COMMAND blaze_test_engine_math)