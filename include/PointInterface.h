#ifndef POINTINTERFACE_H
#define POINTINTERFACE_H

class PointInterface
{
	public:
		virtual float GetX(void) const = 0;
		virtual float GetY(void) const = 0;
		virtual void TranslateX(float translation) = 0;
		virtual void TranslateY(float translation) = 0;
		virtual void Translate(PointInterface* vector) = 0;
		virtual void RotateAboutOrigin(float degrees) = 0;
		virtual bool EqualTo(const PointInterface *p) const
		{
			return (this->GetX() == p->GetX()) &&
					(this->GetY() == p->GetY());
		}
		PointInterface(){};
		virtual ~PointInterface(){};
};

#endif // POINTINTERFACE_H
