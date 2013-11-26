#include "Point.h"
#include "gtest/gtest.h"

TEST(PointTest, XAndYInitialisedToZeroByDefault)
{
	Point p;
	EXPECT_EQ(0, p.GetX());
	EXPECT_EQ(0, p.GetY());
}

TEST(PointTest, XAndYInitialised)
{
	Point p(2, 3);
	Point q(100, -5);
	
	EXPECT_EQ(2, p.GetX());
	EXPECT_EQ(3, p.GetY());
	EXPECT_EQ(100, q.GetX());
	EXPECT_EQ(-5, q.GetY());
}

TEST(PointTest, TranslateXMovesPointInPositiveXDirection)
{
	Point p;
	p.TranslateX(2);
	EXPECT_EQ(2, p.GetX());
	EXPECT_EQ(0, p.GetY());
}

TEST(PointTest, TranslateXMovesPointInNegativeXDirection)
{
	Point p;
	p.TranslateX(-2);
	EXPECT_EQ(-2, p.GetX());
	EXPECT_EQ(0, p.GetY());
}

TEST(PointTest, TranslateYMovesPointInPositiveYDirection)
{
	Point p;
	p.TranslateY(2);
	EXPECT_EQ(0, p.GetX());
	EXPECT_EQ(2, p.GetY());
}

TEST(PointTest, TranslateMovesWithPointInput)
{
	Point p;
	Point displacement(2, 2);
	Point expected(2, 2);
	p.TranslateBy(displacement);
	EXPECT_EQ(expected, p);
	expected = Point(4, 4);
	p.TranslateBy(displacement);
	EXPECT_EQ(expected, p);
	displacement = Point(-6, -10);
	expected = Point(-2, -6);
	p.TranslateBy(displacement);
	EXPECT_EQ(expected, p);
}

TEST(PointTest, TranslateYMovesPointInNegativeYDirection)
{
	Point p;
	p.TranslateY(-2);
	EXPECT_EQ(0, p.GetX());
	EXPECT_EQ(-2, p.GetY());
}

TEST(PointTest, TranslateZeroMakesNoChange)
{
	Point p(5, 5);
	p.TranslateX(0);
	p.TranslateY(0);
	EXPECT_EQ(5, p.GetX());
	EXPECT_EQ(5, p.GetY());
}

TEST(PointTest, RotateXUnitVector90DegreesGivesYUnitVector)
{
	Point p(1, 0);
	Point y(0, 1);
	
	p.RotateAboutOrigin(90);
	
	EXPECT_NEAR(y.GetY(), p.GetY(), 0.0001);
	EXPECT_NEAR(y.GetX(), p.GetX(), 0.0001);
}

TEST(PointTest, RotateXUnitVectorNegativeYUnitVector)
{
	Point p(1, 0);
	Point y(0, -1);
	
	p.RotateAboutOrigin(270);
	
	EXPECT_NEAR(y.GetY(), p.GetY(), 0.0001);
	EXPECT_NEAR(y.GetX(), p.GetX(), 0.0001);
}

TEST(PointTest, Rotating180DegreesReverses)
{
	Point x(1, 0);
	Point v(2, -3);
	
	x.RotateAboutOrigin(180);
	v.RotateAboutOrigin(180);
	
	EXPECT_NEAR(x.GetX(), -1, 0.0001);
	EXPECT_NEAR(x.GetY(), 0, 0.0001);
	
	EXPECT_NEAR(v.GetX(), -2, 0.0001);
	EXPECT_NEAR(v.GetY(), 3, 0.0001);
}
