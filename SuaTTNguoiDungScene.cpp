#include "SuaTTNguoiDungScene.h"
#include "NguoiDungIO.h"

#include <iostream>
#include "ThongBao.h"

using namespace std;

SuaTTNguoiDungScene::SuaTTNguoiDungScene()
{
}

SuaTTNguoiDungScene::SuaTTNguoiDungScene(QuanTri * quanTri) : QuanTriScene(quanTri)
{
}

void SuaTTNguoiDungScene::show()
{
	std::string soTaiKhoan;
	NguoiDung * nguoiDung = nullptr;
	NguoiDungIO ndIO;

	//cout << "====================== SUA THONG TIN NGUOI DUNG ===================" << endl;
	do
	{
		cout << "Nhap so tai khoan nguoi dung: ";
		cin >> soTaiKhoan;
		nguoiDung = ndIO.getNguoiDung(soTaiKhoan);
	} while (nguoiDung == nullptr && IsUserContinue("So tai khoan sai. Nhap lai?")); // nếu không tìm thấy số tài khoản và muốn nhập lại.

	if (nguoiDung != nullptr) // nếu tìm thấy người dùng
	{
		cout << "----------------Thong tin ---------------------" << endl;
		nguoiDung->Output();
		cout << "-----------------------------------------------" << endl;

		cout << "MENU" << endl;
		cout << "\t1. Sua so cmnd." << endl;
		cout << "\t2. Sua ho va ten." << endl;
		cout << "\t3. Sua ngay sinh." << endl;
		cout << "\t4. Sua dia chi." << endl;
		cout << "\t5. Kich hoat tai khoan" << endl;
		cout << "\t6. Khoa tai khoan" << endl;
		cout << "\t7. Thoat." << endl;
		int iChoice;
		InputChoice(iChoice, 1, 7);

		std::string noiDungTB;
		switch (iChoice)
		{
		case 1:
		{
			std::string soCMND;
			cout << "Nhap so CMND moi: ";
			cin >> soCMND;
			noiDungTB.append("Da doi so chung minh thanh").append(soCMND);
			nguoiDung->setSoCMND(soCMND.c_str());
			break;
		}
		case 2:
		{
			std::string ten;
			cout << "Nhap ho va ten moi: ";
			cin.ignore();
			getline(cin, ten);
			noiDungTB.append("Da doi ten thanh ").append(ten);
			nguoiDung->setHoTen(ten.c_str());
			break;
		}

		case 3:
		{
			Date ngaySinh;
			cout << "Nhap ngay sinh moi: " << endl;
			ngaySinh.Input();
			noiDungTB.append("Da doi ngay sinh thanh ").append(to_string(ngaySinh.getDay())).append("/").append(to_string(ngaySinh.getMonth())).append("/").append(to_string(ngaySinh.getYear()));
			nguoiDung->setNgaySinh(ngaySinh.getDay(), ngaySinh.getMonth(), ngaySinh.getYear());
			break;
		}
		case 4:
		{
			std::string diaChi;
			cout << "Nhap dia chi moi: ";
			cin.ignore();
			getline(cin, diaChi);
			noiDungTB.append("Da doi dia chi thanh ").append(diaChi);
			nguoiDung->setDiaChi(diaChi.c_str());
			break;
		}
		case 5:
		{
			noiDungTB.append("Tai khoan da duoc kich hoat.");
			nguoiDung->setActive(true);
			break;
		}
		case 6:
		{
			noiDungTB.append("Tai khoan da duoc khoa lai.");
			nguoiDung->setActive(false);
			break;
		}
		default:
			return;
			break;
		}
		bool isUpdated = ndIO.updateNguoiDung(nguoiDung); // ghi lại thong tin của người dùng

		if (isUpdated)
		{
			cout << "Doi thong tin thanh cong";
			ThongBao::pushThongBao(nguoiDung, noiDungTB);
		}
		else
		{
			cout << "Xay ra loi vui long thu lai sau" << endl;
		}
	}
}

SuaTTNguoiDungScene::~SuaTTNguoiDungScene()
{
}
