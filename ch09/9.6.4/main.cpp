#include<iostream>
#include"Sales.h"

int main() {

	SALES::Sales s1, s2;
	double *da = new double[4] {25.6, 36.7, 55.3, 38.6};
	SALES::setSales(s1, da, 3);
	SALES::setSales(s2);
	SALES::showSales(s1);
	SALES::showSales(s2);
	system("pause");
}
