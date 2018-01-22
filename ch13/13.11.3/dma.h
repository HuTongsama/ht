#pragma once
#include<iostream>

class abcDMA
{
public:
	abcDMA(const char * l = "null", int r = 0);
	abcDMA(const abcDMA & a);
	virtual ~abcDMA();
	abcDMA & operator=(const abcDMA & a);
	virtual void View()const = 0;

private:
	char *label;
	int rating;

};

class baseDMA:public abcDMA
{
public:
	baseDMA(const char * l = "null", int r = 0) :abcDMA(l, r) {}
	baseDMA(const baseDMA& b) :abcDMA(b) {}
	virtual ~baseDMA();
	baseDMA & operator=(const baseDMA & b);
	virtual void View()const;
};

class lacksDMA :public abcDMA
{
public:
	lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
	lacksDMA(const lacksDMA & l);
	virtual ~lacksDMA();
	lacksDMA & operator=(const lacksDMA & l);
	virtual void View()const;
private:
	static const int COL_LEN = 20;
	char color[COL_LEN];
};

class hasDMA :public abcDMA
{
public:
	hasDMA(const char * s = "none", const char * l = "null", int r = 0);
	hasDMA(const hasDMA & h);
	virtual ~hasDMA();
	hasDMA & operator=(const hasDMA & h);
	virtual void View()const;
private:
	char * style;
};
