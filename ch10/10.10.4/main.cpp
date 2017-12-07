#include"Sales.h"

int main() {
	double *ar = new double[4]{ 11.56,21.2,15.31,19.78 };
	SALES::Sales s1(ar, 3);
	SALES::Sales s2;
	s1.showSales();
	s2.showSales();

	system("pause");
}
