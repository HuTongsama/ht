#pragma once
#pragma warning(disable:4996)

#include<iostream>
#include<cstring>

class Stock
{
public:
	Stock();
	Stock(const char * s, long n = 0, double pr = 0.0);
	Stock(const Stock &s);
	Stock & operator=(const Stock &s);
	~Stock();

	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	friend std::ostream &operator<<(std::ostream &os, const Stock &s);
	const Stock &topval(const Stock &s)const;
private:
	char *company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares*share_val; }
	
};
