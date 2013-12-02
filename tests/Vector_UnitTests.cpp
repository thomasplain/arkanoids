#include "gtest/gtest.h"
#include "Vector.h"
#include "Point.h"
#include <cmath>

class VectorTests : public ::testing::Test
{
protected:

	Vector expected;
	inline void testVectorElements(Vector v, float x, float y)
	{
		ASSERT_FLOAT_EQ(v.GetX(), x);
		ASSERT_FLOAT_EQ(v.GetY(), y);
	}

	void checkResult(Vector actual)
	{
		testVectorElements(expected, actual.GetX(), actual.GetY());
	}

	void expect(Vector v)
	{
		expected = v;
	}
};


TEST_F(VectorTests, ConstructorTakesTwoFloats)
{
	Vector v(3, 2);
	testVectorElements(v, 3, 2);
}

TEST_F(VectorTests, InitialiseFromOrderedPairClass)
{
	Vector v1(3, 2);
	Vector v2(v1);
	testVectorElements(v1, 3, 2);

	Point p(3, 2);
	Vector v3(p);

	testVectorElements(v1, 3, 2);
}

TEST_F(VectorTests, ConstructorDefaultsToXBasis)
{
	Vector v;

	testVectorElements(v, 1, 0);
}

TEST_F(VectorTests, TranslatesInXDirection)
{
	Vector v(3, 3);

	v.TranslateX(3);
	expect(Vector(6, 3));
	checkResult(v);

	v.TranslateX(-15);
	expect(Vector(-9, 3));
	checkResult(v);
}

TEST_F(VectorTests, TranslatesInYDirection)
{
	Vector v(1, 1);

	v.TranslateY(20);
	expect(Vector(1, 21));
	checkResult(v);

	v.TranslateY(-40);
	expect(Vector(1, -19));
	checkResult(v);
}

TEST_F(VectorTests, TranslatesByVector)
{
	Vector v(3, 4);

	v.TranslateBy(Vector(7,6));
	expect(Vector(10, 10));
	checkResult(v);

	v.TranslateBy(Vector(-14, -12));
	expect(Vector(-4, -2));
	checkResult(v);
}

TEST_F(VectorTests, LengthReturnsMagnitudeOfVector)
{
	ASSERT_EQ(Vector(3, 4).Length(), 5);
	ASSERT_FLOAT_EQ(Vector(1, 1).Length(), sqrt(2));
	ASSERT_FLOAT_EQ(Vector(0, 0).Length(), 0);
}

TEST_F(VectorTests, NormaliseReturnsDirectionUnitVector)
{
	Vector v(3, 3);

	expect(Vector(1.0/sqrt(2), 1.0/sqrt(2)));
	checkResult(v.Normalise());

	v = Vector(2, 4);
	expect(Vector(1/sqrt(5), 2/sqrt(5)));
	checkResult(v.Normalise());
}

TEST_F(VectorTests, DotReturnsDotProduct)
{
	Vector v(1, 2);

	ASSERT_EQ(v.Dot(Vector(1, 2)), 5);
	ASSERT_EQ(v.Dot(Vector(3, 3)), 9);
	ASSERT_EQ(v.Dot(Vector(2.5, 2.5)), 7.5);
	ASSERT_EQ(v.Dot(Vector(0, 0)), 0);
}

TEST_F(VectorTests, DotWithOrthogonalGivesZero)
{
	Vector v;
	ASSERT_EQ(v.Dot(Vector(0, 1)), 0);
	v = Vector(3, 4);
	ASSERT_EQ(v.Dot(Vector(-4, 3)), 0);
}

TEST_F(VectorTests, AddTwoVectors)
{
	Vector v1(1, 1), v2(1, 1);
	expect(Vector(2, 2));

	checkResult(v1.Add(v2));

	v2 = Vector(3, -5);
	expect(Vector(4, -4));
	checkResult(v1.Add(v2));
}

TEST_F(VectorTests, AddOverloaded)
{
	ASSERT_EQ(Vector(1, 1).Add(Vector(1, 1)),
		Vector(1, 1) + Vector(1, 1));
}
