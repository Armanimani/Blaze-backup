#pragma once

#include "base_types.hpp"
#include <DirectXMath.h>

namespace blaze::base
{
	class Vector2: DirectX::XMFLOAT2
	{
	public:
		Vector2() noexcept;
		explicit Vector2(Float uniform_value) noexcept;
		Vector2(Float x_value, Float y_value) noexcept;

		~Vector2() = default;

		Vector2(const Vector2& other) noexcept = default;
		Vector2& operator=(const Vector2& other) noexcept = default;
		
		Vector2(Vector2&& other) noexcept = default;
		Vector2& operator=(Vector2&& other) noexcept = default;

		bool operator==(const Vector2& other) const noexcept;
		bool operator!=(const Vector2& other) const noexcept;

		Vector2& operator+=(const Vector2& other) noexcept;
		Vector2& operator-=(const Vector2& other) noexcept;
		Vector2& operator*=(const Vector2& other) noexcept;
		
		Vector2& operator*=(Float value) noexcept;
		Vector2& operator/=(Float value) noexcept;

		Vector2 operator+() const noexcept;
		Vector2 operator-() const noexcept;

		[[nodiscard]] Float getX() const noexcept;
		[[nodiscard]] Float getY() const noexcept;

		void setX(Float value) noexcept;
		void setY(Float value) noexcept;
		void setValues(Float x_value, Float y_value) noexcept;
	};
}
