#include "gtest/gtest.h"
#include "Projection.h"
#include "Box.h"
#include "Circle.h"
#include "Point.h"
#include "Vector.h"
#include <cmath>

class ProjectionTests : public ::testing::Test
{
protected:
	Circle c;
	Projection expected;
	ProjectionTests() : c(Point(0, 0), 2), expected(c, Vector(0, 0)) {}
	void expect(Projection p)
	{
		expected = p;
	}
	void compareProjections(Projection p)
	{
		ASSERT_EQ(expected, p);
	}
	void checkProjectionsNotEqual(Projection p)
	{
		ASSERT_NE(expected, p);
	}
	void projectCircleAndCheck(Vector projectionAxis)
	{
		compareProjections(Projection(c, projectionAxis));
	}
};

TEST_F(ProjectionTests, CreateProjectionFromCircle)
{
	Vector xAxis(1, 0);
	Projection p(c, xAxis);
}

TEST_F(ProjectionTests, CircleProjectionIsSameInAnyDirection)
{
	expect(Projection(-2, 2));

	projectCircleAndCheck(Vector(1, 0));
	projectCircleAndCheck(Vector(-1, 0));
	projectCircleAndCheck(Vector(3, -17));
}

TEST_F(ProjectionTests, CreateProjectionFromBox)
{
	Box b(Point(0, 0), 2, 2);
	Vector xAxis(1, 0);
	Projection p(b, xAxis);
}

TEST_F(ProjectionTests, ProjectOriginCentredBoxOnto45DegreeAxis)
{
	Box b(Point(-1, 1), 2, 2);
	Vector fortyFiveDegAxis(1, 1);
	expect(Projection(-sqrt(2), sqrt(2)));

	compareProjections(Projection(b, fortyFiveDegAxis));

	fortyFiveDegAxis = Vector(-1, 1);
	compareProjections(Projection(b, fortyFiveDegAxis));

	fortyFiveDegAxis = Vector(-1, -1);
	compareProjections(Projection(b, fortyFiveDegAxis));

	fortyFiveDegAxis = Vector(1, -1);
	compareProjections(Projection(b, fortyFiveDegAxis));
}

TEST_F(ProjectionTests, NoOverlapIfJustTouching)
{
	Projection p1(-2, 2), p2(2, 4);

	ASSERT_FALSE(p1.OverlapsWith(p2));

	p2 = Projection(-4, -2);
	ASSERT_FALSE(p1.OverlapsWith(p2));
}

TEST_F(ProjectionTests, DetectsOverlapAtStart)
{
	Projection p1(-2, 2), p2(-4, -1.9);

	ASSERT_TRUE(p1.OverlapsWith(p2));
}

TEST_F(ProjectionTests, DetectsOverlapAtEnd)
{
	Projection p1(-2, 2), p2(1.9, 4);

	ASSERT_TRUE(p1.OverlapsWith(p2));
}

TEST_F(ProjectionTests, OverlapWhenOneNestedWithinTheOther)
{
	Projection p1(-1, 1), p2(-2, 2);

	ASSERT_TRUE(p1.OverlapsWith(p2));

	ASSERT_TRUE(p2.OverlapsWith(p1));
}

TEST_F(ProjectionTests, OverlapWhenOneLaysDirectlyOnTheOther)
{
	
	Projection p1(-1, 1), p2(-1, 1);

	ASSERT_TRUE(p1.OverlapsWith(p2));
}

TEST_F(ProjectionTests, OverlapsWithZeroLengthProjection)
{
    Projection p1(-1, 1), p2(0, 0);
    ASSERT_TRUE(p1.OverlapsWith(p2));    
}

TEST_F(ProjectionTests, NonOverlapWithZeroLengthProjAtEitherEnd)
{
    Projection p1(-1, 1), p2(-1, -1);
    ASSERT_FALSE(p1.OverlapsWith(p2));
    p2 = Projection(1, 1);
    ASSERT_FALSE(p1.OverlapsWith(p2));
}
