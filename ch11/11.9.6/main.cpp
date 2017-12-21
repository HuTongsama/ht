#include<iostream>
#include"stonewt.h"

using namespace std;

int main() {
	Stonewt incognito = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);

	Stonewt *p = new Stonewt[6]{ incognito,wolfe,taft };
	
	for (int i = 3; i < 6; i++)
	{
		double tmp;
		cout << "Enter pounds: ";
		if (cin >> tmp)
			p[i] = Stonewt(tmp);
		else
			cout << "Wrong input!\n";
	}
	Stonewt max = p[0], min = p[0], tmp(11, 0);
	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		if (p[i] >= tmp)
			count++;
		if (p[i] > max)
			max = p[i];
		else if (p[i] < min)
			min = p[i];
	}
	cout << "The number of the elements which more than 11 stones is: " << count << endl;
	max.setMode(Stonewt::stones);
	min.setMode(Stonewt::stones);
	cout << "Max: " << max;
	cout << "Min: " << min;


	system("pause");
}
