#include "Blaze/Engine/Base/Vector2.hpp"

#include <DirectXMath.h>
#include <cassert>
#include <cmath>

namespace blaze::base
{
	/* Static constants */
	const Vector2 Vector2::k_zero = { 0.0f, 0.0f };
	const Vector2 Vector2::k_one = { 1.0f, 1.0f };
	const Vector2 Vector2::k_unit_x = { 1.0f, 0.0f };
	const Vector2 Vector2::k_unit_y = { 0.0f, 1.0f };

	/* Function definitions */
	using namespace DirectX;
	
	Vector2::Vector2() noexcept
		: XMFLOAT2{ 0.0f, 0.0f } {}

	Vector2::Vector2(const Float uniform_value) noexcept
		: XMFLOAT2{ uniform_value, uniform_value } {}

	Vector2::Vector2(const Float x_value, const Float y_value) noexcept
		: XMFLOAT2{x_value, y_value} {}


	bool Vector2::operator==(const Vector2& other) const noexcept
	{
		const auto v1 = XMLoadFloat2(this);
		const auto v2 = XMLoadFloat2(&other);
		return XMVector2Equal(v1, v2);
	}
	
	bool Vector2::operator!=(const Vector2& other) const noexcept
	{
		return !((*this) == other);
	}

	Vector2& Vector2::operator+=(const Vector2& other) noexcept
	{
		const auto v1 = XMLoadFloat2(this);
		const auto v2 = XMLoadFloat2(&other);
		const auto result = XMVectorAdd(v1, v2);
		XMStoreFloat2(this, result);
		return *this;
	}
	
	Vector2& Vector2::operator-=(const Vector2& other) noexcept
	{
		const auto v1 = XMLoadFloat2(this);
		const auto v2 = XMLoadFloat2(&other);
		const auto result = XMVectorSubtract(v1, v2);
		XMStoreFloat2(this, result);
		return *this;
	}
	
	Vector2& Vector2::operator*=(const Vector2& other) noexcept
	{
		const auto v1 = XMLoadFloat2(this);
		const auto v2 = XMLoadFloat2(&other);
		const auto result = XMVectorMultiply(v1, v2);
		XMStoreFloat2(this, result);
		return *this;
	}

	Vector2& Vector2::operator*=(const Float value) noexcept
	{
		const auto v1 = XMLoadFloat2(this);
		const auto result = XMVectorScale(v1, value);
		XMStoreFloat2(this, result);
		return *this;
	}
	
	Vector2& Vector2::operator/=(const Float value) noexcept
	{
		assert(value != 0.0f);
		const auto v1 = XMLoadFloat2(this);
		const auto result = XMVectorScale(v1, 1.0f / value);
		XMStoreFloat2(this, result);
		return *this;
	}
	
	Vector2 Vector2::operator+() const noexcept
	{
		return *this;
	}
	
	Vector2 Vector2::operator-() const noexcept
	{
		return Vector2(-x, -y);
	}

	Float Vector2::getX() const noexcept
	{
		return x;
	}
	
	Float Vector2::getY() const noexcept
	{
		return y;
	}
	
	void Vector2::setX(const Float value) noexcept
	{
		x = value;
	}
	
	void Vector2::setY(const Float value) noexcept
	{
		y = value;
	}
	
	void Vector2::setValues(const Float x_value, const Float y_value) noexcept
	{
		x = x_value;
		y = y_value;
	}

	Float Vector2::length() const noexcept
	{
		const auto vec = XMLoadFloat2(this);
		const auto result = XMVector2Length(vec);
		return XMVectorGetX(result);
	}
	
	Float Vector2::lengthSquared() const noexcept
	{
		const auto vec = XMLoadFloat2(this);
		const auto result = XMVector2LengthSq(vec);
		return XMVectorGetX(result);
	}
	
	Float Vector2::dot(const Vector2& other) const noexcept
	{
		const auto v1 = XMLoadFloat2(this);
		const auto v2 = XMLoadFloat2(&other);
		const auto result = XMVector2Dot(v1, v2);
		return XMVectorGetX(result);
	}
	
	Vector2 Vector2::cross(const Vector2& other) const noexcept
	{
		const auto v1 = XMLoadFloat2(this);
		const auto v2 = XMLoadFloat2(&other);
		const auto cross_vector = XMVector2Cross(v1, v2);

		Vector2 result;
		XMStoreFloat2(&result, cross_vector);
		return result;
	}
	
	void Vector2::normalize() noexcept
	{
		const auto vec = XMLoadFloat2(this);
		const auto result = XMVector2Normalize(vec);
		XMStoreFloat2(this, result);
	}
	
	Bool Vector2::isNormalize() const noexcept
	{
		return std::fabs(lengthSquared() - 1.0f) <= FLT_EPSILON;
	}
	
	void Vector2::clamp(const Vector2& min, const Vector2& max) noexcept
	{
		const auto vec = XMLoadFloat2(this);
		const auto vec_min = XMLoadFloat2(&min);
		const auto vec_max = XMLoadFloat2(&max);
		const auto result = XMVectorClamp(vec, vec_min, vec_max);
		XMStoreFloat2(this, result);
	}

	Vector2 operator+(const Vector2& lhs, const Vector2& rhs) noexcept
	{
		const auto vec_lhs = XMLoadFloat2(&lhs);
		const auto vec_rhs = XMLoadFloat2(&rhs);
		const auto vec_result = XMVectorAdd(vec_lhs, vec_rhs);

		Vector2 result{};
		XMStoreFloat2(&result, vec_result);
		return result;
	}
	
	Vector2 operator-(const Vector2& lhs, const Vector2& rhs) noexcept
	{
		const auto vec_lhs = XMLoadFloat2(&lhs);
		const auto vec_rhs = XMLoadFloat2(&rhs);
		const auto vec_result = XMVectorSubtract(vec_lhs, vec_rhs);

		Vector2 result{};
		XMStoreFloat2(&result, vec_result);
		return result;
	}
	
	Vector2 operator*(const Vector2& lhs, const Vector2& rhs) noexcept
	{
		const auto vec_lhs = XMLoadFloat2(&lhs);
		const auto vec_rhs = XMLoadFloat2(&rhs);
		const auto vec_result = XMVectorMultiply(vec_lhs, vec_rhs);

		Vector2 result{};
		XMStoreFloat2(&result, vec_result);
		return result;
	}
	
	Vector2 operator*(const Vector2& lhs, const Float rhs) noexcept
	{
		const auto vec_lhs = XMLoadFloat2(&lhs);
		const auto vec_result = XMVectorScale(vec_lhs, rhs);

		Vector2 result{};
		XMStoreFloat2(&result, vec_result);
		return result;
	}
	
	Vector2 operator*(const Float lhs, const Vector2& rhs) noexcept
	{
		const auto vec_rhs = XMLoadFloat2(&rhs);
		const auto vec_result = XMVectorScale(vec_rhs, lhs);

		Vector2 result{};
		XMStoreFloat2(&result, vec_result);
		return result;
	}
	
	Vector2 operator/(const Vector2& lhs, const Vector2& rhs) noexcept
	{
		const auto vec_lhs = XMLoadFloat2(&lhs);
		const auto vec_rhs = XMLoadFloat2(&rhs);
		const auto vec_result = XMVectorDivide(vec_lhs, vec_rhs);

		Vector2 result{};
		XMStoreFloat2(&result, vec_result);
		return result;
	}
	
	Vector2 operator/(const Vector2& lhs, const Float rhs) noexcept
	{
		assert(rhs != 0.0f);
		const auto vec_lhs = XMLoadFloat2(&lhs);
		const auto vec_result = XMVectorScale(vec_lhs, 1.0f / rhs);

		Vector2 result{};
		XMStoreFloat2(&result, vec_result);
		return result;
	}
}
