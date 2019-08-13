#include "TaoNguoiDungScene.h"
#include "NguoiDungIO.h"

#include <iostream>

using namespace std;

TaoNguoiDungScene::TaoNguoiDungScene()
{
}

void TaoNguoiDungScene::show()
{
	NguoiDungIO ndIO;
	NguoiDung * nd = new NguoiDung();
	do {
		cout << "====================== TAO NGUOI DUNG ======================" << endl;
		cout << "Nhap thong tin nguoi dung: " << endl;
		nd->Input();
		ndIO.addNguoiDung(nd);

	} while (IsUserContinue("Tao nguoi dung khac? "));
	delete nd;
}

TaoNguoiDungScene::~TaoNguoiDungScene()
{
}
