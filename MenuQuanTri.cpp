#include "MenuQuanTri.h"
#include "TaoNguoiDungScene.h"

#include <iostream>

using namespace std;

MenuQuanTri::MenuQuanTri()
{
}

void MenuQuanTri::show()
{
	do
	{
		cout << "Chao mung den voi trang quan tri" << endl;
		cout << "MENU:" << endl;
		cout << "\t1. Tao tai khoan nguoi dung." << endl;
		cout << "\t2. Active/Inactive tai khoan." << endl;

		int iChoice;
		InputChoice(iChoice, 1, 2);
		switch (iChoice)
		{
		case 1:
		{
			TaoNguoiDungScene taond;
			taond.show();
			break;
		}
		case 2:
			break;
		default:
			break;
		}
	} while (IsUserContinue("Tiep tuc thuc hien chuc nang khac?"));

}

MenuQuanTri::~MenuQuanTri()
{
}
