#include "MenuQuanTri.h"
#include "TaoNguoiDungScene.h"
#include "DoiTrangThaiScene.h"
#include "ThongKeKhieuNaiScene.h"
#include "XuLyKhieuNaiScene.h"

#include <iostream>

using namespace std;

MenuQuanTri::MenuQuanTri()
{
}

MenuQuanTri::MenuQuanTri(QuanTri * quanTri) : QuanTriScene(quanTri)
{
}

void MenuQuanTri::show()
{
	do
	{
		cout << "=============== Chao mung den voi trang quan tri ================" << endl;
		cout << "MENU:" << endl;
		cout << "\t1. Tao tai khoan nguoi dung." << endl;
		cout << "\t2. Active/Inactive tai khoan." << endl;
		cout << "\t3. Thong ke khieu nai" << endl;
		cout << "\t4. Xu ly khieu nai" << endl;
		int iChoice;
		InputChoice(iChoice, 1, 4);

		Scene * scene = nullptr;
		switch (iChoice)
		{
		case 1:
			scene = new TaoNguoiDungScene(quanTri);
			break;
		case 2:
			scene = new DoiTrangThaiScene(quanTri);
			break;
		case 3:
			scene = new ThongKeKhieuNaiScene(quanTri);
			break;
		case 4:
			scene = new XuLyKhieuNaiScene(quanTri);
			break;
		default:
			break;
		}
		if (scene)
		{
			scene->show();
			delete scene;
		}
		
	} while (IsUserContinue("Tiep tuc thuc hien chuc nang khac?"));

}

MenuQuanTri::~MenuQuanTri()
{
}
