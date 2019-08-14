#include "DangNhapScene.h"
#include "NguoiDungIO.h"
#include "QuanTriIO.h"

#include "MenuNguoiDung.h"
#include "MenuQuanTri.h"

#include <string>
#include <iostream>

using namespace std;

DangNhapScene::DangNhapScene()
{
}

void DangNhapScene::show()
{
	do
	{
		cout << "====================== Login ========================= " << endl;
		cout << "\t1. Nguoi dung dang nhap." << endl;
		cout << "\t2. Quan tri dang nhap." << endl;
		cout << "\t3. Them tai khoan quan tri." << endl;
		int iChoice;
		InputChoice(iChoice, 1, 3);
		switch (iChoice)
		{
		case 1:
			doNguoiDungDangNhap();
			break;
		case 2:
			doQuanTriDangNhap();
			break;
		case 3:
			doAddQuanTri();
			break;
		default:
			break;
		}
	} while (true);
}

void DangNhapScene::doNguoiDungDangNhap()
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

void DangNhapScene::doQuanTriDangNhap()
{
	string username, password;
	do
	{
		cout << "Nhap ten nguoi dung: ";
		cin >> username;
		cout << "Nhap mat khau: ";
		cin >> password;

		// TODO: check login
		QuanTriIO qtIO;
		if (qtIO.checkLogin(username,password))
		{
			QuanTri * qt = qtIO.getQuanTri(username);
			MenuQuanTri menu(qt);
			menu.show();
			return;
		}
	} while (IsUserContinue("Ten nguoi dung hoac mat khau sai. Nhap lai?"));
}

void DangNhapScene::doAddQuanTri()
{
	QuanTri * quanTri = new QuanTri();
	quanTri->Input();
	QuanTriIO qtIO;
	bool added = qtIO.addQuanTri(quanTri);
	if (added)
	{
		cout << "Them quan tri thanh cong." << endl;
	}
	delete quanTri;
}

DangNhapScene::~DangNhapScene()
{
}
