#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "vector.hpp"

TEST_CASE("constructor") {
	vector x(3, 4);
	std::stringstream s;
	s << x;
	REQUIRE(s.str() == "[3/4]");
}

TEST_CASE("+=") {
	vector x(3, 4);
	x += x;
	REQUIRE(x == vector(6, 8));
}

TEST_CASE("+") {
	vector v(3, 4);
	vector x = v + v;
	REQUIRE(x == vector(6, 8));
}

TEST_CASE("*= int") {
	vector x(3, 4);
	x *= 5;
	REQUIRE(x == vector(15, 20));
}

TEST_CASE("*= vector") {
	vector x(3, 4);
	x *= x;
	REQUIRE(x == vector(9, 16));
}

TEST_CASE("* int") {
	vector v(3, 4);
	vector x = v * 5;
	REQUIRE(x == vector(15, 20));
}

TEST_CASE("* vector") {
	vector v(3, 4);
	vector x = v * v;
	REQUIRE(x == vector(9, 16));
}
