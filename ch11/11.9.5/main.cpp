#include<iostream>
#include"stonewt.h"

using namespace std;

int main() {
	Stonewt incognito = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);

	cout << "The celebrity weighed \n";
	cout << incognito;
	cout << "The detective weighed \n";
	cout << wolfe;
	wolfe.setMode(Stonewt::int_pound);
	cout << wolfe;
	cout << "The President weighed \n";
	cout << taft;
	cout << "1+2 weighed \n";
	cout << incognito + wolfe;
	cout << "2-1 weighed \n";
	cout << wolfe - incognito;
	cout << "3*10 weighed \n";
	cout << taft * 10;
	cout << 10 * taft;



	system("pause");
}
