#include <iostream>
#include<fstream>
#include <ctime>

#include "ChuyenTienScene.h"
#include "PhiChuyenTien.h"
#include "NguoiDungIO.h"
#include "Definations.h"
#include "FileLoger.h"

using namespace std;

ChuyenTienScene::ChuyenTienScene() {
}
ChuyenTienScene::ChuyenTienScene(NguoiDung * user) : NguoiDungScene(user) {

}
void ChuyenTienScene::show() {
	cout << "======================= CHUYEN TIEN =========================" << endl;
	if (!user->isActived())
	{
		cout << "Tai khoan cua ban dang bi khoa. Vui long lien he nguoi quan tri de kich hoat." << endl;
		return;
	}

	double amount;
	NguoiDung* user1;
	bool success = false;
	std::string soTaiKhoan;
	NguoiDungIO ndIO;
	do
	{
		cout << "Nhap so tai khoan: ";
		cin >> soTaiKhoan;
		user1 = ndIO.getNguoiDung(soTaiKhoan);

	} while (user1 == nullptr);

	cout << "Nhap so tien can chuyen" << "(" << user->getSoDu().getStringMaTien() << ") : ";
	cin >> amount;
	PhiChuyenTien phiChuyen;
	double phi = phiChuyen.getPhiChuyenTien(user->getNganHang().getStringMaNH(), user1->getNganHang().getStringMaNH());
	// xác nhận chuyển tiền
	cout << "Ban co muon chuyen " << amount << "(" << user->getSoDu().getStringMaTien() << ") toi tai khoan " << user1->getSoTaiKhoan() << endl;
	cout << "Phi chuyen tien: " << phi << endl;
	if (!IsUserContinue("Xac nhan chuyen tien?")) return; // nếu không đồng ý chuyển -> kết thúc

	success = ChuyenTien(user1, amount,phi);
	if (success)
	{
		cout << "Chuyen tien thanh cong. " << endl;
	}
	else
	{
		cout << "So tien trong tai khoan khong du." << endl;
	}

}
bool ChuyenTienScene::ChuyenTien(NguoiDung* user1, double amount,double fee)
{
	if (amount > 0 && amount <= user->getSoDu().getGiaTri() - fee)
	{
		bool updated = false;
		
		user->setSoDu(user->getSoDu() - amount - fee);
		user1->setSoDu(user1->getSoDu() + amount);

		NguoiDungIO ndIO;
		updated = ndIO.updateNguoiDung(user);
		if (!updated) // nếu ko update thành công reset lại số dư
		{
			user->setSoDu(user->getSoDu() + amount + fee);
			return false;
		}
		updated = ndIO.updateNguoiDung(user1);
		if (!updated) // nếu ko update thành công reset lại số dư
		{
			user1->setSoDu(user1->getSoDu() - amount);
			return false;
		}
		LogChuyenTien(user1, amount, fee); // ghi lịch sử chuyển tiền ra file
		return true;
	}
	return false;
}

void ChuyenTienScene::LogChuyenTien(NguoiDung * user1, double amount, double fee)
{
	time_t now = time(NULL);
	std::tm * ptm = localtime(&now);
	char time_buffer[32];
	//Format: Mo, 15.06.2009 20:20:00
	std::strftime(time_buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);

	string message = "";
	message.append(user->getSoTaiKhoan()).append(" [").append(time_buffer).append("] ").append(" Chuyen tien toi so tai khoan ").append(user1->getSoTaiKhoan()).append(" - So tien: ").append(to_string(amount)).append(" - Phi: ").append(to_string(fee));
	FileLoger::WriteLog(LOG_CHUYEN_TIEN_FILE_PATH, message);
}

ChuyenTienScene::~ChuyenTienScene()
{
}
