#ifndef BOX_H_
#define BOX_H_

class OrderedPair;
class Projection;

class Box
{
	OrderedPair* topLeftCorner;
	float boxWidth, boxHeight;
public:
	Box(const OrderedPair& p, float width, float height);
	Box(const OrderedPair& firstCorner, const OrderedPair &oppositeCorner);
	Box(const Box &b);
	OrderedPair& GetFirstVertex();
	float GetWidth() const;
	float GetHeight() const;
	Projection Project(const OrderedPair& axis);
};

#endif /* BOX_H_ */
