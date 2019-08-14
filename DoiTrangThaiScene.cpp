#include "DoiTrangThaiScene.h"
#include "NguoiDungIO.h"
#include <iostream>

using namespace std;

DoiTrangThaiScene::DoiTrangThaiScene()
{
}

DoiTrangThaiScene::DoiTrangThaiScene(QuanTri * quanTri) : QuanTriScene(quanTri)
{
}

void DoiTrangThaiScene::show()
{
	std::string soTaiKhoan;
	NguoiDung * nguoiDung = nullptr;
	NguoiDungIO ndIO;

	cout << "====================== DOI TRANG THAI ===================" << endl;
	do
	{
		cout << "Nhap so tai khoan nguoi dung: ";
		cin >> soTaiKhoan;
		nguoiDung = ndIO.getNguoiDung(soTaiKhoan);
	}while(nguoiDung == nullptr && IsUserContinue("So tai khoan sai. Nhap lai?")); // nếu không tìm thấy số tài khoản và muốn nhập lại.

	if (nguoiDung != nullptr) // nếu tìm thấy người dùng
	{
		cout << "------------------------------------------------------------" << endl;
		cout << "So tai khoan: " << nguoiDung->getSoTaiKhoan() << endl;
		cout << "Ho va ten: " << nguoiDung->getHoTen() << endl; 
		cout << "Trang thai: " << (nguoiDung->isActived() ? "Da kich hoat" : "Chua kich hoat") << endl;
		cout << "------------------------------------------------------------" << endl;

		cout << "\t1. Kich hoat tai khoan." << endl;
		cout << "\t2. Khoa tai khoan." << endl;
		int iChoice;
		InputChoice(iChoice, 1, 2);

		nguoiDung->setActive(iChoice == 1); // đặt lại trạng thái của người dùng
		bool isUpdated = ndIO.updateNguoiDung(nguoiDung); // ghi lại trạng thái của người dùng

		if (isUpdated)
		{
			cout << (iChoice == 1 ? "Kich hoat tai khoan thanh cong" : "Khoa tai khoan thanh cong");
		}
		else
		{
			cout << "Xay ra loi vui long thu lai sau" << endl;
		}
	}


}

DoiTrangThaiScene::~DoiTrangThaiScene()
{
}
