#include "Blaze/Engine/Base/Vector3.hpp"

#include <DirectXMath.h>
#include <cassert>
#include <cmath>

namespace blaze::base
{
	/* Static constants */
	const Vector3 Vector3::k_zero = { 0.0f, 0.0f, 0.0f };
	const Vector3 Vector3::k_one = { 1.0f, 1.0f, 1.0f };
	const Vector3 Vector3::k_unit_x = { 1.0f, 0.0f, 0.0f };
	const Vector3 Vector3::k_unit_y = { 0.0f, 1.0f, 0.0f };
	const Vector3 Vector3::k_unit_z = { 0.0f, 0.0f, 1.0f };
	const Vector3 Vector3::k_up = { 0.0f, 1.0f, 0.0f };
	const Vector3 Vector3::k_down = { 0.0f, -1.0f, 0.0f };
	const Vector3 Vector3::k_right = { 1.0f, 0.0f, 0.0f };
	const Vector3 Vector3::k_left = { -1.0f, 0.0f, 0.0f };
	const Vector3 Vector3::k_forward = { 0.0f, 0.0f, 1.0f };
	const Vector3 Vector3::k_backward = { 0.0f, 0.0f, -1.0f };

	
	/* Function definitions */
	using namespace DirectX;

	Vector3::Vector3() noexcept
		: XMFLOAT3{ 0.0f, 0.0f, 0.0f } {}
	
	Vector3::Vector3(const Float uniform_value) noexcept
		: XMFLOAT3{ uniform_value, uniform_value, uniform_value } {}
	
	Vector3::Vector3(const Float x_value, const Float y_value, const Float z_value) noexcept
		: XMFLOAT3{ x_value, y_value, z_value } {}

	bool Vector3::operator==(const Vector3& other) const noexcept
	{
		const auto v1 = XMLoadFloat3(this);
		const auto v2 = XMLoadFloat3(&other);
		return XMVector3Equal(v1, v2);
	}

	bool Vector3::operator!=(const Vector3& other) const noexcept
	{
		return !((*this) == other);
	}

	Vector3& Vector3::operator+=(const Vector3& other) noexcept
	{
		const auto v1 = XMLoadFloat3(this);
		const auto v2 = XMLoadFloat3(&other);
		const auto result = XMVectorAdd(v1, v2);
		XMStoreFloat3(this, result);
		return *this;
	}
	
	Vector3& Vector3::operator-=(const Vector3& other) noexcept
	{
		const auto v1 = XMLoadFloat3(this);
		const auto v2 = XMLoadFloat3(&other);
		const auto result = XMVectorSubtract(v1, v2);
		XMStoreFloat3(this, result);
		return *this;
	}
	
	Vector3& Vector3::operator*=(const Vector3& other) noexcept
	{
		const auto v1 = XMLoadFloat3(this);
		const auto v2 = XMLoadFloat3(&other);
		const auto result = XMVectorMultiply(v1, v2);
		XMStoreFloat3(this, result);
		return *this;
	}
	
	Vector3& Vector3::operator*=(const Float value) noexcept
	{
		const auto v1 = XMLoadFloat3(this);
		const auto result = XMVectorScale(v1, value);
		XMStoreFloat3(this, result);
		return *this;
	}
	
	Vector3& Vector3::operator/=(const Float value) noexcept
	{
		assert(value != 0.0f);
		const auto v1 = XMLoadFloat3(this);
		const auto result = XMVectorScale(v1, 1.0f / value);
		XMStoreFloat3(this, result);
		return *this;
	}
	
	Vector3 Vector3::operator+() const noexcept
	{
		return *this;
	}
	
	Vector3 Vector3::operator-() const noexcept
	{
		return Vector3(-x, -y, -z);
	}

	Float Vector3::getX() const noexcept
	{
		return x;
	}
	
	Float Vector3::getY() const noexcept
	{
		return y;
	}
	
	Float Vector3::getZ() const noexcept
	{
		return z;
	}

	void Vector3::setX(const Float value) noexcept
	{
		x = value;
	}
	
	void Vector3::setY(const Float value) noexcept
	{
		y = value;
	}
	
	void Vector3::setZ(const Float value) noexcept
	{
		z = value;
	}
	
	void Vector3::setValues(const Float x_value, const Float y_value, const Float z_value) noexcept
	{
		x = x_value;
		y = y_value;
		z = z_value;
	}

	Float Vector3::length() const noexcept
	{
		const auto vec = XMLoadFloat3(this);
		const auto result = XMVector3Length(vec);
		return XMVectorGetX(result);
	}
	
	Float Vector3::lengthSquared() const noexcept
	{
		const auto vec = XMLoadFloat3(this);
		const auto result = XMVector3LengthSq(vec);
		return XMVectorGetX(result);
	}
	
	Float Vector3::dot(const Vector3& other) const noexcept
	{
		const auto v1 = XMLoadFloat3(this);
		const auto v2 = XMLoadFloat3(&other);
		const auto result = XMVector3Dot(v1, v2);
		return XMVectorGetX(result);
	}
	
	Vector3 Vector3::cross(const Vector3& other) const noexcept
	{
		const auto v1 = XMLoadFloat3(this);
		const auto v2 = XMLoadFloat3(&other);
		const auto cross_vector = XMVector3Cross(v1, v2);

		Vector3 result{};
		XMStoreFloat3(&result, cross_vector);
		return result;
	}
	
	void Vector3::normalize() noexcept
	{
		const auto vec = XMLoadFloat3(this);
		const auto result = XMVector3Normalize(vec);
		XMStoreFloat3(this, result);
	}
	
	Bool Vector3::isNormalize() const noexcept
	{
		return std::fabs(lengthSquared() - 1.0f) <= FLT_EPSILON;
	}
	
	void Vector3::clamp(const Vector3& min, const Vector3& max) noexcept
	{
		const auto vec = XMLoadFloat3(this);
		const auto vec_min = XMLoadFloat3(&min);
		const auto vec_max = XMLoadFloat3(&max);
		const auto result = XMVectorClamp(vec, vec_min, vec_max);
		XMStoreFloat3(this, result);
	}

	Vector3 operator+(const Vector3& lhs, const Vector3& rhs) noexcept
	{
		const auto vec_lhs = XMLoadFloat3(&lhs);
		const auto vec_rhs = XMLoadFloat3(&rhs);
		const auto vec_result = XMVectorAdd(vec_lhs, vec_rhs);

		Vector3 result{};
		XMStoreFloat3(&result, vec_result);
		return result;
	}
	
	Vector3 operator-(const Vector3& lhs, const Vector3& rhs) noexcept
	{
		const auto vec_lhs = XMLoadFloat3(&lhs);
		const auto vec_rhs = XMLoadFloat3(&rhs);
		const auto vec_result = XMVectorSubtract(vec_lhs, vec_rhs);

		Vector3 result{};
		XMStoreFloat3(&result, vec_result);
		return result;
	}
	
	Vector3 operator*(const Vector3& lhs, const Vector3& rhs) noexcept
	{
		const auto vec_lhs = XMLoadFloat3(&lhs);
		const auto vec_rhs = XMLoadFloat3(&rhs);
		const auto vec_result = XMVectorMultiply(vec_lhs, vec_rhs);

		Vector3 result{};
		XMStoreFloat3(&result, vec_result);
		return result;
	}
	
	Vector3 operator*(const Vector3& lhs, const Float rhs) noexcept
	{
		const auto vec_lhs = XMLoadFloat3(&lhs);
		const auto vec_result = XMVectorScale(vec_lhs, rhs);

		Vector3 result{};
		XMStoreFloat3(&result, vec_result);
		return result;
	}
	
	Vector3 operator*(const Float lhs, const Vector3& rhs) noexcept
	{
		const auto vec_rhs = XMLoadFloat3(&rhs);
		const auto vec_result = XMVectorScale(vec_rhs, lhs);

		Vector3 result{};
		XMStoreFloat3(&result, vec_result);
		return result;
	}
	
	Vector3 operator/(const Vector3& lhs, const Vector3& rhs) noexcept
	{
		const auto vec_lhs = XMLoadFloat3(&lhs);
		const auto vec_rhs = XMLoadFloat3(&rhs);
		const auto vec_result = XMVectorDivide(vec_lhs, vec_rhs);

		Vector3 result{};
		XMStoreFloat3(&result, vec_result);
		return result;
	}
	
	Vector3 operator/(const Vector3& lhs, const Float rhs) noexcept
	{
		assert(rhs != 0.0f);
		const auto vec_lhs = XMLoadFloat3(&lhs);
		const auto vec_result = XMVectorScale(vec_lhs, 1.0f / rhs);

		Vector3 result{};
		XMStoreFloat3(&result, vec_result);
		return result;
	}	
}
