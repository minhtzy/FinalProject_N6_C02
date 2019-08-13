#include "GuiTienScene.h"
#include "NguoiDungIO.h"
#include "DoiTien.h"
#include "FileLoger.h"
#include "Definations.h"

#include <iostream>
#include <ctime>

using namespace std;


GuiTienScene::GuiTienScene()
{
}

GuiTienScene::GuiTienScene(NguoiDung * user) : NguoiDungScene(user)
{
}

void GuiTienScene::show()
{
	cout << "======================= GUI TIEN =========================" << endl;
	if (!user->isActived())
	{
		cout << "Tai khoan cua ban dang bi khoa. Vui long lien he nguoi quan tri de kich hoat." << endl;
		return;
	}

	bool success = false;

	// Nhập số tiền cần chuyển
	Tien tien;
	tien.Input();
	double tienDoi = DoiTien::doiTien(tien.getGiaTri(), tien.getStringMaTien(), user->getSoDu().getStringMaTien());
	double phiChuyen = DoiTien::getPhi(tien.getGiaTri(), tien.getStringMaTien(),user->getSoDu().getStringMaTien());
	cout << "Ban muon chuyen " << tienDoi << " (" << user->getSoDu().getStringMaTien() << ") vao tai khoan." << endl;
	cout << "Phi gui tien " << phiChuyen << endl;
	if (!IsUserContinue("Xac nhan chuyen tien?")) return;
	success = GuiTien(tienDoi,phiChuyen);
	if (success)
	{
		cout << "Gui tien vao tai khoan thanh cong. " << endl;
	}
	else
	{
		cout << "Co loi xay ra vui long thu lai sau. " << endl;
	}

}

bool GuiTienScene::GuiTien(double amount, double fee)
{
	if (amount > 0)
	{
		bool updated;

		user->setSoDu(user->getSoDu() + amount - fee);
		NguoiDungIO ndIO;
		updated = ndIO.updateNguoiDung(user);
		if (!updated) // nếu ko update thành công reset lại số dư
		{
			user->setSoDu(user->getSoDu() - amount + fee);
			return false;
		}
		LogGuiTien(amount, fee);
		return true;
	}
	return false;
}

void GuiTienScene::LogGuiTien(double amount, double fee)
{
	time_t now = time(NULL);
	std::tm * ptm = new tm;
	localtime_s(ptm, &now);
	char time_buffer[32];
	//Format: Mo, 15.06.2009 20:20:00
	std::strftime(time_buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);

	string message = "";
	message.append(user->getSoTaiKhoan()).append(" [").append(time_buffer).append("] ").append(" Gui tien tai cay ATM - So tien: ").append(to_string(amount)).append(" - Phi: ").append(to_string(fee)).append(" - So du cuoi: ").append(to_string(user->getSoDu().getGiaTri()));
	FileLoger::WriteLog(LOG_GUI_TIEN_FILE_PATH, message);
}

GuiTienScene::~GuiTienScene()
{
}
