#include"move.h"

int main() {
	Move m1(1, 2), m2(3, 4);
	cout << "m1:\n";
	m1.showmove();
	cout << "m2:\n";
	m2.showmove();
	cout << "m1+m2:\n";
	m1.add(m2).showmove();
	cout << "reset m1 to (5,6):\n";
	m1.reset(5, 6);
	m1.showmove();
	system("pause");
}
