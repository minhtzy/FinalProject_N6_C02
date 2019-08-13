#include "DangNhapSence.h"
#include "NguoiDungIO.h"
#include "MenuNguoiDung.h"
#include "MenuQuanTri.h"

#include <string>
#include <iostream>

using namespace std;

DangNhapSence::DangNhapSence()
{
}

void DangNhapSence::show()
{
	cout << "Login : " << endl;
	cout << "\t1. Nguoi dung dang nhap." << endl;
	cout << "\t2. Quan tri dang nhap." << endl;
	int iChoice;
	InputChoice(iChoice, 1, 2);
	switch (iChoice)
	{
	case 1:
		
		break;
	case 2:
		break;
	default:
		break;
	}
}

void DangNhapSence::doNguoiDungDangNhap()
{
	string soTaiKhoan, matKhau;
	do
	{
		cout << "Nhap so tai khoan: ";
		cin >> soTaiKhoan;
		cout << "Nhap mat khau: ";
		cin >> matKhau;

		NguoiDungIO ndIO;
		if (ndIO.checkLogin(soTaiKhoan, matKhau))
		{
			NguoiDung* nd = ndIO.getNguoiDung(soTaiKhoan);
			MenuNguoiDung menu = MenuNguoiDung(nd);
			menu.show();
			delete nd;
			return;
		}
	} while (IsUserContinue("So tai khoan hoac mat khau sai. Nhap lai?"));

}

void DangNhapSence::doQuanTriDangNhap()
{
	string username, password;
	cout << "Nhap ten nguoi dung: ";
	cin >> username;
	cout << "Nhap mat khau: ";
	cin >> password;

	MenuQuanTri menu;
	menu.show();

}

DangNhapSence::~DangNhapSence()
{
}
