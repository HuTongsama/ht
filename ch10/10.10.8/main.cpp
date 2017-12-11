#include"List.h"

void showFunc(double &n)
{
	cout << n << endl;
}
int main() {
	
	List<double> ld(4);
	cout << ld.isEmpty() << endl;
	ld.addData(2.1);
	ld.addData(3.6);
	ld.addData(5.5);
	ld.addData(1.78);
	cout << ld.isFull() << endl;
	ld.visit(showFunc);


	system("pause");
}
