#pragma once
class vec3
{
public:
	float x;
	float y;
	float z;
	vec3()
		:x(0.0), y(0.0), z(0.0) {}

	vec3(float val)
		:x(val), y(val), z(val) {}

	vec3(float newX, float newY, float newZ)
		:x(newX), y(newY), z(newZ) {}

	vec3 operator*(const float& rhs)
	{
		this->x = x * rhs;
		this->y = y * rhs;
		this->z = z * rhs;

		return *this;
	}

	vec3 operator/(const float& rhs)
	{
		this->x = x / rhs;
		this->y = y / rhs;
		this->z = z / rhs;

		return *this;
	}

};