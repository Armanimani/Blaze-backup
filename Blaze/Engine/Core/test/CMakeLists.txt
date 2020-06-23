add_executable(
	blaze_test_engine_core
	"Types/test_base_types.cpp"
	"Types/test_fnv1a_hash.cpp"
	"Types/test_HashedString.cpp"
	"Types/test_TypeIdentifier.cpp"
	"Math/test_utilities.cpp" 
	"Math/test_IntVector2.cpp"
	"Math/test_IntVector3.cpp" 
	"Math/test_IntVector4.cpp" 
	"Math/test_FloatVector2.cpp" 
	"Math/test_FloatVector3.cpp" 
	"Math/test_FloatVector4.cpp" 
	"Math/test_Matrix4X4.cpp" 
	"Logging/test_ConsoleLogger.cpp" 
	"Logging/mock_ConsoleLoggerAdapter.cpp" 
	"DesignPatterns/test_ServiceLocator.cpp" 
	"DataStructures/test_SparseSet.cpp")

target_link_libraries(
	blaze_test_engine_core
	PRIVATE Blaze::Engine::Core GTest::GTest GTest::GTest::Main
	INTERFACE Blaze::ProjectOption
)

add_test(NAME blaze_test_engine_core COMMAND blaze_test_engine_core)