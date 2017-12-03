#include"golf.h"

int main() {

	golf *ga = new golf[4];
	setgolf(ga[0], "Ann Birdfree", 24);
	showgolf(ga[0]);
	int count = 1;
	for (int i = 1; i < 4; i++)
	{
		if (setgolf(ga[i]))
			count++;
		else
			break;
	}
	handicap(ga[0], 34);
	for (int i = 0; i < count; i++)
		showgolf(ga[i]);

	cout << "Bye!" << endl;

	system("pause");
}
