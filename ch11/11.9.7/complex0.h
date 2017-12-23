#pragma once
#include<iostream>
class Complex
{
public:
	Complex();
	Complex(double a, double b);
	~Complex();
	Complex operator+(const Complex &b)const;
	Complex operator-(const Complex &b)const;
	Complex operator*(const Complex &b)const;
	friend Complex operator*(double n, const Complex & b);
	friend Complex operator~(const Complex & b);
	friend std::ostream &operator<<(std::ostream &os, const Complex &b);
	friend std::istream &operator>>(std::istream &is, Complex &b);
private:
	double real;
	double imaginary;
};
