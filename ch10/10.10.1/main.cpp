#include"bank_account.h"

using namespcae std;

int main() {
	Account *p = new Account[3];
	p[0] = Account("zhangsan", "9732", 5000);
	p[1] = Account("lisi", "10086", 8000);
	for (int i = 0; i < 3; i++)
		p[i].show();

	cout << "Hudashuai withdraw some cash....\n";
	p[2].getMoney(2500);
	p[2].show();
	cout << "Hudashuai save some money....\n";
	p[2].saveMoney(6000);
	p[2].show();
	system("pause");
}
