#include"dma.h"
#include<iostream>
const int members = 4;

using namespace srd;

int main() {
	abcDMA * p_mems[members];
	char t_label[20];
	int t_rating;
	char t_color[20];
	char t_style[20];
	int choose;
	for (int i = 0; i < members; i++)
	{
		cout << "Choose one to construct:\n";
		do {
			cout << "1.baseDMA\t2.lacksDMA\t3.hasDMA\n";
			cin >> choose;
			cin.get();
			if (choose != 1 && choose != 2 && choose != 3)
				cout << "Wrong option!" << endl;
		} while (choose != 1 && choose != 2 && choose != 3);
		if (choose == 1)
		{
			cout << "Enter label:\n";
			cin.getline(t_label, 20);
			cout << "Enter rating:\n";
			cin >> t_rating;
			cin.get();
			p_mems[i] = new baseDMA(t_label, t_rating);
		}
		else if (choose == 2)
		{
			cout << "Enter label:\n";
			cin.getline(t_label, 20);
			cout << "Enter color:\n";
			cin.getline(t_color, 20);
			cout << "Enter rating:\n";
			cin >> t_rating;
			cin.get();
			p_mems[i] = new lacksDMA(t_color, t_label, t_rating);
		}
		else
		{
			cout << "Enter label:\n";
			cin.getline(t_label, 20);
			cout << "Enter style:\n";
			cin.getline(t_style, 20);
			cout << "Enter rating:\n";
			cin >> t_rating;
			cin.get();
			p_mems[i] = new hasDMA(t_style, t_label, t_rating);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < members; i++)
		p_mems[i]->View();
	for (int i = 0; i < members; i++)
		delete p_mems[i];
	cout << "Done!";
	system("pause");
}
