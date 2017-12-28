#pragma once
#include<iostream>
using std::ostream;
using std::istream;
#pragma warning(disable : 4996)
class String
{
public:
	String();
	String(const char *s);
	String(const String &s);
	~String();
	int length()const { return len; }
	void stringlow();
	void stringup();
	int has(char ch);

	String &operator=(const String &s);
	String &operator=(const char *s);
	String operator+(const String &s)const;
	String friend operator+(const char *s1, const String &s2);
	char &operator[](int i);
	const char &operator[](int i)const;

	friend bool operator<(const String &s1, const String &s2);
	friend bool operator>(const String &s1, const String &s2);
	friend bool operator==(const String &s1, const String &s2);
	friend ostream &operator<<(ostream &os, const String &s);
	friend istream &operator>>(istream &is, String &s);

private:
	char *str;
	int len;
	static const int CINLIM = 80;
};
