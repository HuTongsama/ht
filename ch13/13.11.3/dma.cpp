#include "dma.h"
#pragma warning(disable:4996)
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

abcDMA::abcDMA(const char * l, int r)
{
	label = new char[strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}

abcDMA::abcDMA(const abcDMA & a)
{
	label = new char[strlen(a.label) + 1];
	strcpy(label, a.label);
	rating = a.rating;
}

abcDMA::~abcDMA()
{
	delete[]label;
}

abcDMA & abcDMA::operator=(const abcDMA & a)
{
	if (this == &a)
		return *this;
	delete[]label;
	label = new char[strlen(a.label) + 1];
	strcpy(label, a.label);
	rating = a.rating;
	return *this;
}

void abcDMA::View()const
{
	cout << "Label: " << label << endl;
	cout << "Rating: " << rating << endl;
}

baseDMA::~baseDMA()
{
}

baseDMA & baseDMA::operator=(const baseDMA & b)
{
	if (this == &b)
		return *this;
	abcDMA::operator=(b);
	return *this;
}

void baseDMA::View() const
{
	abcDMA::View();
}

lacksDMA::lacksDMA(const char * c, const char * l, int r):abcDMA(l,r)
{
	if (strlen(c) < lacksDMA::COL_LEN)
		strcpy(color, c);
	else
		cout << "Wrong color size!" << endl;
}

lacksDMA::lacksDMA(const lacksDMA & l):abcDMA(l)
{
	strcpy(color, l.color);
}

lacksDMA::~lacksDMA()
{
}

lacksDMA & lacksDMA::operator=(const lacksDMA & l)
{
	if (this == &l)
		return *this;
	abcDMA::operator=(l);
	strcpy(color, l.color);
	return *this;
}

void lacksDMA::View() const
{
	abcDMA::View();
	cout << "Color: " << color << endl;
}

hasDMA::hasDMA(const char * s, const char * l, int r):abcDMA(l,r)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & h):abcDMA(h)
{
	style = new char[strlen(h.style) + 1];
	strcpy(style, h.style);
}

hasDMA::~hasDMA()
{
	delete[]style;
}

hasDMA & hasDMA::operator=(const hasDMA & h)
{
	if (this == &h)
		return *this;
	abcDMA::operator=(h);
	delete[]style;
	style = new char[strlen(h.style) + 1];
	strcpy(style, h.style);
	return *this;
}

void hasDMA::View() const
{
	abcDMA::View();
	cout << "Style :" << style << endl;
}
