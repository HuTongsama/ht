#include "complex0.h"

Complex::Complex():real(0),imaginary(0)
{
}

Complex::Complex(double a, double b):real(a),imaginary(b)
{
}

Complex::~Complex()
{
}

Complex Complex::operator+(const Complex & b) const
{
	return Complex(real+b.real,imaginary+b.imaginary);
}

Complex Complex::operator-(const Complex & b) const
{
	return Complex(real-b.real,imaginary-b.imaginary);
}

Complex Complex::operator*(const Complex & b) const
{
	double A = real*b.real - imaginary*b.imaginary;
	double B = real*b.imaginary + imaginary*b.real;
	return Complex(A,B);
}

Complex operator*(double n, const Complex & b)
{
	return Complex(n*b.real,n*b.imaginary);
}

Complex operator~(const Complex & b)
{
	return Complex(b.real,-b.imaginary);
}

std::ostream & operator<<(std::ostream &os, const Complex & b)
{
	os << '(' << b.real << ',' << b.imaginary << "i)";
	return os;
}

std::istream & operator>>(std::istream &is, Complex & b)
{
	double A, B;
	std::cout << "real:";
	if (is >> A)
	{
		std::cout << "imaginary:";
		is >> B;
		b = Complex(A, B);
	}
	return is;
}
