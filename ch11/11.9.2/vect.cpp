#include"vect.h"
#include<cmath>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR 
{
	//compute degrees in one radian
	const double Rad_to_deg = 45.0 / atan(1.0);
	//private methods

	void Vector::set_x(double n1,double n2)
	{
		x = n1*cos(n2 / Rad_to_deg);
	}
	void Vector::set_y(double n1,double n2)
	{
		y = n1*sin(n2 / Rad_to_deg);
	}
	//public methods
	Vector::Vector()
	{
		x = y = 0.0;
		mode = RECT;
	}
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (mode == RECT)
		{
			x = n1;
			y = n2;
			
		}
		else if (mode == POL)
		{
			set_x(n1,n2);
			set_y(n1,n2);
			
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector()--";
			cout << "vector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (mode == RECT)
		{
			x = n1;
			y = n2;

		}
		else if (mode == POL)
		{
			set_x(n1, n2);
			set_y(n1, n2);

		}
		else
		{
			cout << "Incorrect 3rd argument to Vector()--";
			cout << "vector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}
	Vector::~Vector()
	{

	}
	double Vector::magval() const
	{
		return sqrt(x*x + y*y);
	}
	double Vector::angval() const
	{
		return (x == 0 && y == 0) ? 0.0 : atan2(y, x);
	}
	void Vector::polar_mode()
	{
		mode = POL;
	}
	void Vector::rect_mode()
	{
		mode = RECT;
	}
	//operator overloading
	Vector Vector::operator+(const Vector &b)const
	{
		return Vector(x + b.x, y + b.y);
	}
	Vector Vector::operator-(const Vector &b)const
	{
		return Vector(x - b.x, y - b.y);
	}
	Vector Vector::operator-()const
	{
		return Vector(-x, -y);
	}
	Vector Vector::operator*(double n)const
	{
		return Vector(n*x, n*y);
	}
	Vector operator*(double n, const Vector &a)
	{
		return a*n;
	}
	std::ostream&operator<<(std::ostream&os, const Vector &v)
	{
		if (v.mode == Vector::RECT)
			os << "(x,y) = (" << v.x << "," << v.y << ")";
		else if (v.mode == Vector::POL)
		{
			os << "(m,a) = (" << v.magval() << ", "
				<< v.angval()*Rad_to_deg << ")";
		}
		else
			os << "Vector object mode is invalid";
		return os;
	}
}
