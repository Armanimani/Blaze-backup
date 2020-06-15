#pragma once

#include "base_types.hpp"
#include <DirectXMath.h>

namespace blaze::base
{
	class Vector4 : DirectX::XMFLOAT4
	{
	public:
		Vector4() noexcept;
		explicit Vector4(Float uniform_value) noexcept;
		Vector4(Float x_value, Float y_value, Float z_value, Float w_value) noexcept;

		~Vector4() = default;
		
		Vector4(const Vector4& other) noexcept = default;
		Vector4& operator=(const Vector4& other) noexcept = default;
		
		Vector4(Vector4&& other) noexcept = default;
		Vector4& operator=(Vector4&& other) noexcept = default;
		
		friend Vector4 operator+(const Vector4& lhs, const Vector4& rhs) noexcept;
		friend Vector4 operator-(const Vector4& lhs, const Vector4& rhs) noexcept;
		friend Vector4 operator*(const Vector4& lhs, const Vector4& rhs) noexcept;
		friend Vector4 operator*(const Vector4& lhs, Float rhs) noexcept;
		friend Vector4 operator*(Float lhs, const Vector4& rhs) noexcept;
		friend Vector4 operator/(const Vector4& lhs, const Vector4& rhs) noexcept;
		friend Vector4 operator/(const Vector4& lhs, Float rhs) noexcept;
		
		bool operator==(const Vector4& other) const noexcept;
		bool operator!=(const Vector4& other) const noexcept;
		
		Vector4& operator+=(const Vector4& other) noexcept;
		Vector4& operator-=(const Vector4& other) noexcept;
		Vector4& operator*=(const Vector4& other) noexcept;
		
		Vector4& operator*=(Float value) noexcept;
		Vector4& operator/=(Float value) noexcept;
		
		Vector4 operator+() const noexcept;
		Vector4 operator-() const noexcept;
		
		[[nodiscard]] Float getX() const noexcept;
		[[nodiscard]] Float getY() const noexcept;
		[[nodiscard]] Float getZ() const noexcept;
		[[nodiscard]] Float getW() const noexcept;
		
		void setX(Float value) noexcept;
		void setY(Float value) noexcept;
		void setZ(Float value) noexcept;
		void setW(Float value) noexcept;
		void setValues(Float x_value, Float y_value, Float z_value, Float w_value) noexcept;
		
		[[nodiscard]] Float length() const noexcept;
		[[nodiscard]] Float lengthSquared() const noexcept;
		
		[[nodiscard]] Float dot(const Vector4& other) const noexcept;
		
		void normalize() noexcept;
		[[nodiscard]] Bool isNormalize() const noexcept;
		
		void clamp(const Vector4& min, const Vector4& max) noexcept;

		static const Vector4 k_zero;
		static const Vector4 k_one;
		static const Vector4 k_unit_x;
		static const Vector4 k_unit_y;
		static const Vector4 k_unit_z;
		static const Vector4 k_unit_w;
	};

	/* Stand-alone functions */
	Vector4 operator+(const Vector4& lhs, const Vector4& rhs) noexcept;
	Vector4 operator-(const Vector4& lhs, const Vector4& rhs) noexcept;
	Vector4 operator*(const Vector4& lhs, const Vector4& rhs) noexcept;
	Vector4 operator*(const Vector4& lhs, Float rhs) noexcept;
	Vector4 operator*(Float lhs, const Vector4& rhs) noexcept;
	Vector4 operator/(const Vector4& lhs, const Vector4& rhs) noexcept;
	Vector4 operator/(const Vector4& lhs, Float rhs) noexcept;
}
