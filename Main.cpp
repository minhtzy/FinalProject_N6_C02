#include "Main.h"
#include "DangNhapSence.h"

#include <iostream>

using namespace std;

int main(int arg, char ** args)
{
	DangNhapSence dnSence;
	dnSence.show();
	//for (int i = 0; i < 2; ++i)
	//{
	//	NguoiDung * nd = new NguoiDung();
	//	nd->Input();
	//	ndIO.addNguoiDung(nd);
	//}

	//for (int i = 0; i < 3; ++i)
	//{
	//	NguoiDung * nd = ndIO.getNguoiDung(std::to_string(i + 1));
	//	if (nd != NULL) {
	//		nd->Output();
	//	}
	//}
	system("pause");
	return 0;
}