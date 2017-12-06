#pragma once
#include<string>
#include<iostream>

class Account
{
public:
	Account(std::string name="hudashuai",std::string id="9527",double deposit=10000);
	~Account();

	void show()const;
	void saveMoney(double n);
	void getMoney(double n);

private:
	std::string _name;
	std::string _ID;
	double _deposit;
};

inline Account::Account(std::string name, std::string id, double deposit)
{
	_name = name;
	_ID = id;
	_deposit = deposit;
}

Account::~Account()
{
}

inline void Account::show() const
{
	std::cout << "Information of Depositor:\n";
	std::cout << "Name: " << this->_name << '\t';
	std::cout << "Id: " << this->_ID << '\t';
	std::cout << "Deposit: " << this->_deposit << '\n';
}

inline void Account::saveMoney(double n)
{
	this->_deposit += n;
}

inline void Account::getMoney(double n)
{
	this->_deposit -= n;
}
