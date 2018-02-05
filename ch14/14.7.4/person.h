#pragma once
#include<string>
#include<iostream>
#include<ctime>
class Person
{
private:
	std::string fname;
	std::string lname;
public:
	Person(std::string f = "null", std::string l = "null")
		:fname(f), lname(l) {}
	virtual ~Person(){ }
	virtual void Show()const;
	virtual void Set();
};

class Gunslinger :virtual public Person
{
private:
	double gtime;
	int nick;
public:
	Gunslinger() {}
	Gunslinger(std::string f, std::string l, double t, int n)
		:Person(f, l), gtime(t), nick(n) {}
	~Gunslinger() {}
	double Draw()const { return gtime; }
	virtual void Show()const;
	virtual void Set();
};

class PokerPlayer :virtual public Person
{
public:
	PokerPlayer() {}
	PokerPlayer(std::string f, std::string l) :Person(f, l) {}
	~PokerPlayer() {}
	virtual void Show()const;
	int Draw()const;
};
class BadDude :public Gunslinger, public PokerPlayer
{
public:
	BadDude() {}
	BadDude(std::string f, std::string l, double t, int n)
		:Person(f, l), Gunslinger(f, l, t, n), PokerPlayer(f, l) {}
	~BadDude() {}
	double Gdraw()const;
	int Cdraw()const;
	void Show()const;
	void Set();
};
