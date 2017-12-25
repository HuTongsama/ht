#include"cow.h"

int main() {
	{
		Cow a, b("huangniu", "chicao", 250), c("nainiu", "shuijiao", 260), d("shuiniu", "heshui", 280);
		a.ShowCow();
		b.ShowCow();
		a = c;
		a.ShowCow();
		Cow e(d);
		e.ShowCow();
	}
	system("pause");
}
