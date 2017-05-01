#include <iostream>

#ifndef VECTOR_HPP
#define VECTOR_HPP

/// @file

/// \brief
/// vector ADT
/// \details
/// This is an ADT that implements vector values, so a type
/// with an x and y values, both of these values being an integer.

class vector {
private:
	int x;
	int y;
public:
	/// \brief
	/// constructor from explicit values
	/// \details
	/// This constructor initializes a vector from its x and y value.
	vector(int x = 0, int y = 0):
		x(x), y(y)
	{}

	/// \brief
	/// compare two vectors
	/// \details
	/// This operator tests for equality. It returns true
	/// if and only if the x and y value of both
	/// operands are equal.
	bool operator==(const vector &v) const {
		return (x == v.x) && (y == v.y);
	}


	/// \brief
	/// output operator for a vector
	/// \details
	/// This operator<< prints a constructor in the format
	/// [x/y] where both values are printed as
	/// decimal values.
	friend std::ostream & operator<<(std::ostream &s, const vector &v) {
		return s
			<< "["
			<< v.x
			<< "/"
			<< v.y
			<< "]";
	}

	/// \brief
	/// add a vector to itself
	/// \details
	/// This operator+= adds a vector to itself.
	vector &operator+=(const vector &v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	/// \brief
	/// add a vector to another vector
	/// \details
	/// This operator+ adds a vector to another vector.
	vector operator+(const vector &v) const {
		return vector(
			x + v.x,
			y + v.y
		);
	}

	/// \brief
	/// multiply a vector by an interger
	/// \details
	/// This operator+= multiplies a vector by an interger.
	vector &operator*=(const int i) {
		x *= i;
		y *= i;
		return *this;
	}

	/// \brief
	/// multiply a vector by another vector
	/// \details
	/// This operator+= multiplies a vector by another vector.
	vector &operator*=(const vector &v) {
		x *= v.x;
		y *= v.y;
		return *this;
	}

	/// \brief
	/// multiply a vector by an interger
	/// \details
	/// This operator* multiplies a vector by an interger.
	vector operator*(const int i) const {
		return vector(
			x * i,
			y * i
		);
	}

	/// \brief
	/// multiply a vector by another vector
	/// \details
	/// This operator* multiplies a vector by another vector.
	vector operator*(const vector &v) const {
		return vector(
			x * v.x,
			y * v.y
		);
	}
};

#endif
