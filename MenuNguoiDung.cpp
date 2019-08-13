#include "MenuNguoiDung.h"
#include <iostream>

#include "RutTienSence.h"
#include "ChuyenTienSence.h"

using namespace std;

MenuNguoiDung::MenuNguoiDung()
{
}

MenuNguoiDung::MenuNguoiDung(NguoiDung * user) : NguoiDungSence(user)
{
}

void MenuNguoiDung::show()
{
	cout << "MENU" << endl;
	cout << "\t1. Rut tien." << endl;
	cout << "\t2. Gui tien." << endl;
	cout << "\t3. Chuyen tien." << endl;
	cout << "\t4. In sao ke." << endl;
	int iChoice;
	InputChoice(iChoice, 1, 4);
	switch (iChoice)
	{
	case 1:
	{
		RutTienSence rutTienSence(user);
		rutTienSence.show();
		break;
	}
	case 2:
	{
		break;
	}
	case 3:
	{
		break;
	}
	case 4:
	{
		break;
	}
	default:
		break;
	}
}

MenuNguoiDung::~MenuNguoiDung()
{
}
