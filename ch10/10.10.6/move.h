#pragma once
#include<iostream>
class Move
{
public:
	Move(double a=0,double b=0);//set x.y to a,b
	void showmove()const;//show current x,y values
	//this function adds x of m to x of invoking object to get new x,
	//adds y of m to y of invoking object to get new y,creates a new
	//move object initialized to new x,y values and returns it
	Move add(const Move &m)const;
	void reset(double a = 0, double b = 0);//resets x,y to a,b
	~Move();

private:
	double x;
	double y;
};

Move::Move(double a,double b)
{
	x = a;
	y = b;
}

inline void Move::showmove() const
{
	std::cout << "Current x: " << x << '\n';
	std::cout << "Current y: " << y << std::endl;
}

inline Move Move::add(const Move & m) const
{
	return Move(this->x+m.x,this->y+m.y);
}

inline void Move::reset(double a, double b)
{
	x = a;
	y = b;
}

Move::~Move()
{
}
