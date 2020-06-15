#include "Blaze/Engine/Base/Vector4.hpp"

#include <DirectXMath.h>
#include <cassert>
#include <cmath>

namespace blaze::base
{
	/* Static constants */
	const Vector4 Vector4::k_zero = { 0.0f, 0.0f, 0.0f, 0.0f };
	const Vector4 Vector4::k_one = { 1.0f, 1.0f, 1.0f, 1.0f };
	const Vector4 Vector4::k_unit_x = { 1.0f, 0.0f, 0.0f, 0.0f };
	const Vector4 Vector4::k_unit_y = { 0.0f, 1.0f, 0.0f, 0.0f };
	const Vector4 Vector4::k_unit_z = { 0.0f, 0.0f, 1.0f, 0.0f };
	const Vector4 Vector4::k_unit_w = { 0.0f, 1.0f, 0.0f, 1.0f };


	/* Function definitions */
	using namespace DirectX;

	Vector4::Vector4() noexcept
		: XMFLOAT4{ 0.0f, 0.0f, 0.0f, 0.0f } {}

	Vector4::Vector4(const Float uniform_value) noexcept
		: XMFLOAT4{ uniform_value, uniform_value, uniform_value, uniform_value } {}

	Vector4::Vector4(const Float x_value, const Float y_value, const Float z_value, const Float w_value) noexcept
		: XMFLOAT4{ x_value, y_value, z_value, w_value } {}

	bool Vector4::operator==(const Vector4& other) const noexcept
	{
		const auto v1 = XMLoadFloat4(this);
		const auto v2 = XMLoadFloat4(&other);
		return XMVector4Equal(v1, v2);
	}
	
	bool Vector4::operator!=(const Vector4& other) const noexcept
	{
		return !((*this) == other);
	}
	
	Vector4& Vector4::operator+=(const Vector4& other) noexcept
	{
		const auto v1 = XMLoadFloat4(this);
		const auto v2 = XMLoadFloat4(&other);
		const auto result = XMVectorAdd(v1, v2);
		XMStoreFloat4(this, result);
		return *this;
	}
	
	Vector4& Vector4::operator-=(const Vector4& other) noexcept
	{
		const auto v1 = XMLoadFloat4(this);
		const auto v2 = XMLoadFloat4(&other);
		const auto result = XMVectorSubtract(v1, v2);
		XMStoreFloat4(this, result);
		return *this;
	}
	
	Vector4& Vector4::operator*=(const Vector4& other) noexcept
	{
		const auto v1 = XMLoadFloat4(this);
		const auto v2 = XMLoadFloat4(&other);
		const auto result = XMVectorMultiply(v1, v2);
		XMStoreFloat4(this, result);
		return *this;
	}
	
	Vector4& Vector4::operator*=(const Float value) noexcept
	{
		const auto v1 = XMLoadFloat4(this);
		const auto result = XMVectorScale(v1, value);
		XMStoreFloat4(this, result);
		return *this;
	}
	
	Vector4& Vector4::operator/=(const Float value) noexcept
	{
		assert(value != 0.0f);
		const auto v1 = XMLoadFloat4(this);
		const auto result = XMVectorScale(v1, 1.0f / value);
		XMStoreFloat4(this, result);
		return *this;
	}
	
	Vector4 Vector4::operator+() const noexcept
	{
		return *this;
	}
	
	Vector4 Vector4::operator-() const noexcept
	{
		return Vector4(-x, -y, -z, -w);
	}
	
	Float Vector4::getX() const noexcept
	{
		return x;
	}
	
	Float Vector4::getY() const noexcept
	{
		return y;
	}
	
	Float Vector4::getZ() const noexcept
	{
		return z;
	}

	Float Vector4::getW() const noexcept
	{
		return w;
	}
	
	void Vector4::setX(const Float value) noexcept
	{
		x = value;
	}
	
	void Vector4::setY(const Float value) noexcept
	{
		y = value;
	}
	
	void Vector4::setZ(const Float value) noexcept
	{
		z = value;
	}

	void Vector4::setW(const Float value) noexcept
	{
		w = value;
	}
	
	void Vector4::setValues(const Float x_value, const Float y_value, const Float z_value, const Float w_value) noexcept
	{
		x = x_value;
		y = y_value;
		z = z_value;
		w = w_value;
	}
	
	Float Vector4::length() const noexcept
	{
		const auto vec = XMLoadFloat4(this);
		const auto result = XMVector4Length(vec);
		return XMVectorGetX(result);
	}
	
	Float Vector4::lengthSquared() const noexcept
	{
		const auto vec = XMLoadFloat4(this);
		const auto result = XMVector4LengthSq(vec);
		return XMVectorGetX(result);
	}
	
	Float Vector4::dot(const Vector4& other) const noexcept
	{
		const auto v1 = XMLoadFloat4(this);
		const auto v2 = XMLoadFloat4(&other);
		const auto result = XMVector4Dot(v1, v2);
		return XMVectorGetX(result);
	}
	
	void Vector4::normalize() noexcept
	{
		const auto vec = XMLoadFloat4(this);
		const auto result = XMVector4Normalize(vec);
		XMStoreFloat4(this, result);
	}
	
	Bool Vector4::isNormalize() const noexcept
	{
		return std::fabs(lengthSquared() - 1.0f) <= FLT_EPSILON;
	}
	
	void Vector4::clamp(const Vector4& min, const Vector4& max) noexcept
	{
		const auto vec = XMLoadFloat4(this);
		const auto vec_min = XMLoadFloat4(&min);
		const auto vec_max = XMLoadFloat4(&max);
		const auto result = XMVectorClamp(vec, vec_min, vec_max);
		XMStoreFloat4(this, result);
	}
	
	Vector4 operator+(const Vector4& lhs, const Vector4& rhs) noexcept
	{
		const auto vec_lhs = XMLoadFloat4(&lhs);
		const auto vec_rhs = XMLoadFloat4(&rhs);
		const auto vec_result = XMVectorAdd(vec_lhs, vec_rhs);
	
		Vector4 result{};
		XMStoreFloat4(&result, vec_result);
		return result;
	}
	
	Vector4 operator-(const Vector4& lhs, const Vector4& rhs) noexcept
	{
		const auto vec_lhs = XMLoadFloat4(&lhs);
		const auto vec_rhs = XMLoadFloat4(&rhs);
		const auto vec_result = XMVectorSubtract(vec_lhs, vec_rhs);
	
		Vector4 result{};
		XMStoreFloat4(&result, vec_result);
		return result;
	}
	
	Vector4 operator*(const Vector4& lhs, const Vector4& rhs) noexcept
	{
		const auto vec_lhs = XMLoadFloat4(&lhs);
		const auto vec_rhs = XMLoadFloat4(&rhs);
		const auto vec_result = XMVectorMultiply(vec_lhs, vec_rhs);
	
		Vector4 result{};
		XMStoreFloat4(&result, vec_result);
		return result;
	}
	
	Vector4 operator*(const Vector4& lhs, const Float rhs) noexcept
	{
		const auto vec_lhs = XMLoadFloat4(&lhs);
		const auto vec_result = XMVectorScale(vec_lhs, rhs);
	
		Vector4 result{};
		XMStoreFloat4(&result, vec_result);
		return result;
	}
	
	Vector4 operator*(const Float lhs, const Vector4& rhs) noexcept
	{
		const auto vec_rhs = XMLoadFloat4(&rhs);
		const auto vec_result = XMVectorScale(vec_rhs, lhs);
	
		Vector4 result{};
		XMStoreFloat4(&result, vec_result);
		return result;
	}
	
	Vector4 operator/(const Vector4& lhs, const Vector4& rhs) noexcept
	{
		const auto vec_lhs = XMLoadFloat4(&lhs);
		const auto vec_rhs = XMLoadFloat4(&rhs);
		const auto vec_result = XMVectorDivide(vec_lhs, vec_rhs);
	
		Vector4 result{};
		XMStoreFloat4(&result, vec_result);
		return result;
	}
	
	Vector4 operator/(const Vector4& lhs, const Float rhs) noexcept
	{
		assert(rhs != 0.0f);
		const auto vec_lhs = XMLoadFloat4(&lhs);
		const auto vec_result = XMVectorScale(vec_lhs, 1.0f / rhs);
	
		Vector4 result{};
		XMStoreFloat4(&result, vec_result);
		return result;
	}
}
