#include <gtest/gtest.h>
#include <Blaze/Engine/Core/Math/Matrix4X4.hpp>

using namespace blaze;

TEST(Matrix4X4, constructor_default)
{
	const Matrix4X4 mat{};

	ASSERT_FLOAT_EQ(mat(0, 0), 0.0f);
	ASSERT_FLOAT_EQ(mat(0, 1), 0.0f);
	ASSERT_FLOAT_EQ(mat(0, 2), 0.0f);
	ASSERT_FLOAT_EQ(mat(0, 3), 0.0f);

	ASSERT_FLOAT_EQ(mat(1, 0), 0.0f);
	ASSERT_FLOAT_EQ(mat(1, 1), 0.0f);
	ASSERT_FLOAT_EQ(mat(1, 2), 0.0f);
	ASSERT_FLOAT_EQ(mat(1, 3), 0.0f);

	ASSERT_FLOAT_EQ(mat(2, 0), 0.0f);
	ASSERT_FLOAT_EQ(mat(2, 1), 0.0f);
	ASSERT_FLOAT_EQ(mat(2, 2), 0.0f);
	ASSERT_FLOAT_EQ(mat(2, 3), 0.0f);
	
	ASSERT_FLOAT_EQ(mat(3, 0), 0.0f);
	ASSERT_FLOAT_EQ(mat(3, 1), 0.0f);
	ASSERT_FLOAT_EQ(mat(3, 2), 0.0f);
	ASSERT_FLOAT_EQ(mat(3, 3), 0.0f);
}

TEST(Matrix4X4, constructor_vector)
{
	const Matrix4X4 mat{
		{0.0f, 1.0f, 2.0f, 3.0f},
		{4.0f, 5.0f, 6.0f, 7.0f},
		{8.0f, 9.0f, 10.0f, 11.0f},
		{12.0f, 13.0f, 14.0f, 15.0f}
	};

	ASSERT_FLOAT_EQ(mat(0, 0), 0.0f);
	ASSERT_FLOAT_EQ(mat(0, 1), 1.0f);
	ASSERT_FLOAT_EQ(mat(0, 2), 2.0f);
	ASSERT_FLOAT_EQ(mat(0, 3), 3.0f);

	ASSERT_FLOAT_EQ(mat(1, 0), 4.0f);
	ASSERT_FLOAT_EQ(mat(1, 1), 5.0f);
	ASSERT_FLOAT_EQ(mat(1, 2), 6.0f);
	ASSERT_FLOAT_EQ(mat(1, 3), 7.0f);

	ASSERT_FLOAT_EQ(mat(2, 0), 8.0f);
	ASSERT_FLOAT_EQ(mat(2, 1), 9.0f);
	ASSERT_FLOAT_EQ(mat(2, 2), 10.0f);
	ASSERT_FLOAT_EQ(mat(2, 3), 11.0f);

	ASSERT_FLOAT_EQ(mat(3, 0), 12.0f);
	ASSERT_FLOAT_EQ(mat(3, 1), 13.0f);
	ASSERT_FLOAT_EQ(mat(3, 2), 14.0f);
	ASSERT_FLOAT_EQ(mat(3, 3), 15.0f);
}


TEST(Matrix4X4, operator_paranthesis)
{
	Matrix4X4 mat{
		{0.0f, 1.0f, 2.0f, 3.0f},
		{4.0f, 5.0f, 6.0f, 7.0f},
		{8.0f, 9.0f, 10.0f, 11.0f},
		{12.0f, 13.0f, 14.0f, 15.0f}
	};

	ASSERT_FLOAT_EQ(mat(0, 0), 0.0f);
	ASSERT_FLOAT_EQ(mat(0, 1), 1.0f);
	ASSERT_FLOAT_EQ(mat(0, 2), 2.0f);
	ASSERT_FLOAT_EQ(mat(0, 3), 3.0f);

	ASSERT_FLOAT_EQ(mat(1, 0), 4.0f);
	ASSERT_FLOAT_EQ(mat(1, 1), 5.0f);
	ASSERT_FLOAT_EQ(mat(1, 2), 6.0f);
	ASSERT_FLOAT_EQ(mat(1, 3), 7.0f);

	ASSERT_FLOAT_EQ(mat(2, 0), 8.0f);
	ASSERT_FLOAT_EQ(mat(2, 1), 9.0f);
	ASSERT_FLOAT_EQ(mat(2, 2), 10.0f);
	ASSERT_FLOAT_EQ(mat(2, 3), 11.0f);

	ASSERT_FLOAT_EQ(mat(3, 0), 12.0f);
	ASSERT_FLOAT_EQ(mat(3, 1), 13.0f);
	ASSERT_FLOAT_EQ(mat(3, 2), 14.0f);
	ASSERT_FLOAT_EQ(mat(3, 3), 15.0f);

	mat(2, 2) = 50.0f;
	
	ASSERT_FLOAT_EQ(mat(0, 0), 0.0f);
	ASSERT_FLOAT_EQ(mat(0, 1), 1.0f);
	ASSERT_FLOAT_EQ(mat(0, 2), 2.0f);
	ASSERT_FLOAT_EQ(mat(0, 3), 3.0f);

	ASSERT_FLOAT_EQ(mat(1, 0), 4.0f);
	ASSERT_FLOAT_EQ(mat(1, 1), 5.0f);
	ASSERT_FLOAT_EQ(mat(1, 2), 6.0f);
	ASSERT_FLOAT_EQ(mat(1, 3), 7.0f);

	ASSERT_FLOAT_EQ(mat(2, 0), 8.0f);
	ASSERT_FLOAT_EQ(mat(2, 1), 9.0f);
	ASSERT_FLOAT_EQ(mat(2, 2), 50.0f);
	ASSERT_FLOAT_EQ(mat(2, 3), 11.0f);

	ASSERT_FLOAT_EQ(mat(3, 0), 12.0f);
	ASSERT_FLOAT_EQ(mat(3, 1), 13.0f);
	ASSERT_FLOAT_EQ(mat(3, 2), 14.0f);
	ASSERT_FLOAT_EQ(mat(3, 3), 15.0f);
}