#include <iostream>
#include <ctime>

#include "RutTienScene.h"
#include "NguoiDungIO.h"
#include "DoiTien.h"
#include "Definations.h"
#include "FileLoger.h"

using namespace std;

RutTienScene::RutTienScene()
{
}

RutTienScene::RutTienScene(NguoiDung * user) : NguoiDungScene(user)
{
}

void RutTienScene::show()
{
	cout << "======================= RUT TIEN =========================" << endl;
	if (!user->isActived())
	{
		cout << "Tai khoan cua ban dang bi khoa. Vui long lien he nguoi quan tri de kich hoat." << endl;
		return;
	}

	double amount;
	bool success = false;
	do
	{
		cout << "Nhap so tien can rut" << "(VND) : ";
		cin >> amount;
		success = RutTien(amount);
		
		if (success)
		{
			cout << "Rut tien thanh cong. " << endl;
			break;
		}
		else
		{
			cout << "So tien trong tai khoan khong du." << endl;
		}
	} while (IsUserContinue("Nhap so khac?"));
}

bool RutTienScene::RutTien(double amount)
{
	if (amount > 0 && amount <= user->getSoDu().getGiaTri())
	{
		bool updated;

		user->setSoDu(user->getSoDu() - amount);
		NguoiDungIO ndIO;
		updated = ndIO.updateNguoiDung(user);
		if (!updated) // nếu ko update thành công reset lại số dư
		{
			user->setSoDu(user->getSoDu() + amount);
			return false;
		}
		LogRutTien(amount);
		return true;
	}
	return false;
}

void RutTienScene::LogRutTien(double amount)
{
	time_t now = time(NULL);
	std::tm * ptm = new tm;
	localtime_s(ptm, &now);
	char time_buffer[32];
	//Format: Mo, 15.06.2009 20:20:00
	std::strftime(time_buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);

	string message = "";
	message.append(user->getSoTaiKhoan()).append(" [").append(time_buffer).append("] ").append("Rut tien tai cay ATM - So tien: ").append(to_string(amount)).append(" - So du cuoi: ").append(to_string(user->getSoDu().getGiaTri()));
	FileLoger::WriteLog(LOG_RUT_TIEN_FILE_PATH, message);
}

RutTienScene::~RutTienScene()
{
}
