#include "MenuNguoiDung.h"
#include <iostream>

#include "RutTienScene.h"
#include "ChuyenTienScene.h"
#include "GuiTienScene.h"
#include "KhieuNaiScene.h"
#include "XemThongBaoScene.h"
#include "SaoKeNguoiDungScene.h"

using namespace std;

MenuNguoiDung::MenuNguoiDung()
{
}

MenuNguoiDung::MenuNguoiDung(NguoiDung * user) : NguoiDungScene(user)
{
}

void MenuNguoiDung::show()
{
	do
	{
		cout << "================ MENU ==================" << endl;
		cout << "\t1. Rut tien." << endl;
		cout << "\t2. Gui tien vao tai khoan." << endl;
		cout << "\t3. Chuyen tien." << endl;
		cout << "\t4. In sao ke." << endl;
		cout << "\t5. Gui khieu nai." << endl;
		cout << "\t6. Xem thong bao." << endl;
		cout << "\t7. Thoat" << endl;
		int iChoice;
		InputChoice(iChoice, 1, 7);
		Scene * scene = nullptr;
		switch (iChoice)
		{
		case 1:
		{
			scene = new RutTienScene(user);
			break;
		}
		case 2:
		{
			scene = new GuiTienScene(user);
			break;
		}
		case 3:
		{
			scene = new ChuyenTienScene(user);
			break;
		}
		case 4:
		{
			scene = new SaoKeNguoiDungScene(user);
			break;
		}
		case 5:
		{
			scene = new KhieuNaiScene(user);
			break;
		}
		case 6:
		{
			scene = new XemThongBaoScene(user);
			break;
		}
		case 7: 
			return;
		default:
			break;
		}
		if (scene)
		{
			scene->show();
			delete scene;
		}
	} while (true);
}

MenuNguoiDung::~MenuNguoiDung()
{
}
