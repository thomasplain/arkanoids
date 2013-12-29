#include "Shape.h"
#include "OrderedPair.h"

class Line : public Shape
{
		OrderedPair start, end;
	public:
		Line(const OrderedPair& p_start, const OrderedPair& p_end) : start(p_start), end(p_end) {}
		virtual Projection Project(const Vector& axis) const;
		virtual Vector getCentre() const;
		virtual	OrderedPair* getClosestVertex(const OrderedPair& op) const;
		virtual int getNumVertices() const;
		virtual Vector getVertex(int vertexIndex) const;
		virtual bool isVertex(const OrderedPair& point) const;
		virtual AxisSet* getSeparatingAxes(const Shape* s) const;
};
