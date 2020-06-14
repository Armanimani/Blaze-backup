#include "Blaze/Engine/Base/Vector2.hpp"

#include <DirectXMath.h>
#include <cassert>

namespace blaze::base
{
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
}
