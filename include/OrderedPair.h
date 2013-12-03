#ifndef ORDEREDPAIR_H_
#define ORDEREDPAIR_H_

class OrderedPair
{
protected:
	float x, y;
public:
	float GetX() const { return x; }
	float GetY() const { return y; }

	OrderedPair(float xValue, float yValue) : x(xValue), y(yValue) {}
	OrderedPair(const OrderedPair &op) : x(op.x), y(op.y) {}

	void TranslateX(float displacement) { x += displacement; }
	void TranslateY(float displacement) { y += displacement; }
	void TranslateBy(const OrderedPair& translation)
	{
		TranslateX(translation.x);
		TranslateY(translation.y);
	}

	bool operator==(const OrderedPair &p) const
	{
		return ((x == p.GetX()) && (y == p.GetY()));
	}

};

#endif /* ORDEREDPAIR_H_ */
