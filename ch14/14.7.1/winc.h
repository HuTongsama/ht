#pragma once
#include<valarray>
#include<string>
template<class T1,class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1 & first() { return a; }
	T2 & second() { return b; }
	T1 first()const { return a; }
	T2 second()const { return b; }
	Pair(const T1 & aval, const T2 & bval) :a(aval), b(bval) {}
	Pair() {}
};
using ArrayInt = std::valarray<int>;
using PairArray = Pair<ArrayInt, ArrayInt>;
class Wine
{
private:
	PairArray p;
	std::string name;
	int years;
public:
	Wine() {}
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	const std::string & Label()const
	{
		return name;
	}
	int sum()const;
	void GetBottles();
	void Show()const;
};
