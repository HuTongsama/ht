#include"customer.h"
#include<iostream>
using namespace std;

int main() {
	double total = 0;
	int ia[4] = { 5,7,1,11 };
	double da[4] = { 2.51,6.66,11.3,1.78 };
	customer ca[4] = { {"hudashuai",15.6},
						{"zhangsan",55.6},
						{"lisi",21.89},
						{"wangwu",6.66} };
	Stack<int> is(4);
	Stack<double>id(4);
	Stack<customer>ic(4);
	for (int i = 0; i < 4; i++)
	{
		is.push(ia[i]);
		id.push(da[i]);
		ic.push(ca[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		cout << "Int: " << is.pop() << '\n';
		cout << "Double: " << id.pop() << '\n';
		double tmp = ic.pop().payment;
		cout << "Payment: " << tmp << endl;
		total += tmp;
	}
	cout << "Total payment is: " << total << endl;
	system("pause");
}
