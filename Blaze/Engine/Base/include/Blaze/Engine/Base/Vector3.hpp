#pragma once

#include "base_types.hpp"
#include <DirectXMath.h>

namespace blaze::base
{
	class Vector3 : DirectX::XMFLOAT3
	{
	public:
		Vector3() noexcept;
		explicit Vector3(Float uniform_value) noexcept;
		Vector3(Float x_value, Float y_value, Float z_value) noexcept;

		~Vector3() = default;
		
		Vector3(const Vector3& other) noexcept = default;
		Vector3& operator=(const Vector3& other) noexcept = default;
		
		Vector3(Vector3&& other) noexcept = default;
		Vector3& operator=(Vector3&& other) noexcept = default;
		
		friend Vector3 operator+(const Vector3& lhs, const Vector3& rhs) noexcept;
		friend Vector3 operator-(const Vector3& lhs, const Vector3& rhs) noexcept;
		friend Vector3 operator*(const Vector3& lhs, const Vector3& rhs) noexcept;
		friend Vector3 operator*(const Vector3& lhs, Float rhs) noexcept;
		friend Vector3 operator*(Float lhs, const Vector3& rhs) noexcept;
		friend Vector3 operator/(const Vector3& lhs, const Vector3& rhs) noexcept;
		friend Vector3 operator/(const Vector3& lhs, Float rhs) noexcept;
		
		bool operator==(const Vector3& other) const noexcept;
		bool operator!=(const Vector3& other) const noexcept;
		
		Vector3& operator+=(const Vector3& other) noexcept;
		Vector3& operator-=(const Vector3& other) noexcept;
		Vector3& operator*=(const Vector3& other) noexcept;
		
		Vector3& operator*=(Float value) noexcept;
		Vector3& operator/=(Float value) noexcept;
		
		Vector3 operator+() const noexcept;
		Vector3 operator-() const noexcept;
		
		[[nodiscard]] Float getX() const noexcept;
		[[nodiscard]] Float getY() const noexcept;
		[[nodiscard]] Float getZ() const noexcept;
		
		void setX(Float value) noexcept;
		void setY(Float value) noexcept;
		void setZ(Float value) noexcept;
		void setValues(Float x_value, Float y_value, Float z_value) noexcept;
		
		[[nodiscard]] Float length() const noexcept;
		[[nodiscard]] Float lengthSquared() const noexcept;
		
		[[nodiscard]] Float dot(const Vector3& other) const noexcept;
		
		[[nodiscard]] Vector3 cross(const Vector3& other) const noexcept;
		
		void normalize() noexcept;
		[[nodiscard]] Bool isNormalize() const noexcept;
		
		void clamp(const Vector3& min, const Vector3& max) noexcept;

		static const Vector3 k_zero;
		static const Vector3 k_one;
		static const Vector3 k_unit_x;
		static const Vector3 k_unit_y;
		static const Vector3 k_unit_z;
		static const Vector3 k_up;
		static const Vector3 k_down;
		static const Vector3 k_right;
		static const Vector3 k_left;
		static const Vector3 k_forward;
		static const Vector3 k_backward;
	};

	/* Stand-alone functions */
	Vector3 operator+(const Vector3& lhs, const Vector3& rhs) noexcept;
	Vector3 operator-(const Vector3& lhs, const Vector3& rhs) noexcept;
	Vector3 operator*(const Vector3& lhs, const Vector3& rhs) noexcept;
	Vector3 operator*(const Vector3& lhs, Float rhs) noexcept;
	Vector3 operator*(Float lhs, const Vector3& rhs) noexcept;
	Vector3 operator/(const Vector3& lhs, const Vector3& rhs) noexcept;
	Vector3 operator/(const Vector3& lhs, Float rhs) noexcept;
}
