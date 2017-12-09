#include"plorg.h"

int main() {
	Plorg p1, p2("hudashuai", 66), p3("01234567899876543210", 21);
	p1.resetCI(55);
	p1.show();
	p2.show();
	p3.show();
	system("pause");
}
