#include "MenuNguoiDung.h"
#include <iostream>

#include "RutTienSence.h"
#include "ChuyenTienSence.h"
#include "GuiTienSence.h"

using namespace std;

MenuNguoiDung::MenuNguoiDung()
{
}

MenuNguoiDung::MenuNguoiDung(NguoiDung * user) : NguoiDungSence(user)
{
}

void MenuNguoiDung::show()
{
	do
	{

		cout << "MENU" << endl;
		cout << "\t1. Rut tien." << endl;
		cout << "\t2. Gui tien vao tai khoan." << endl;
		cout << "\t3. Chuyen tien." << endl;
		cout << "\t4. In sao ke." << endl;
		cout << "\t5. Gui khieu nai." << endl;
		cout << "\t6. Xem thong bao." << endl;
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
			GuiTienSence guiTienSence(user);
			guiTienSence.show();
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
		cout << "Ban co muon thuc hien chuc nang khac? ";
	} while (IsUserContinue());
}

MenuNguoiDung::~MenuNguoiDung()
{
}
