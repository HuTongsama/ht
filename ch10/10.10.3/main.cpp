#include"golf.h"

int main() {
	Golf ann;
	ann.setgolf();
	Golf andy("hu dashuai", 25);
	ann.showgolf();
	andy.showgolf();
	andy.setHandicap(30);
	andy.showgolf();
	system("pause");
}
