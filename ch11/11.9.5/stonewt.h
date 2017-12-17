#pragma once
#include<iostream>

class Stonewt
{
public:
	enum Mode {stones,int_pound,float_pound};
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	void setMode(Mode m);
	Stonewt operator+(const Stonewt & s)const;
	Stonewt operator-(const Stonewt & s)const;
	Stonewt operator*(double n)const;
	friend Stonewt operator*(double n, const Stonewt & s) { return s*n; }
	friend std::ostream & operator<<(std::ostream &os, const Stonewt s);
private:
	enum {Lbs_per_stn=14};//pounds per stone
	int stone;			  //whole stones
	double pds_left;      //fractional pounds
	double pounds;		  //entire weight in pounds
	Mode mode;
};
