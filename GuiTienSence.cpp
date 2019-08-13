#include "GuiTienSence.h"
#include "NguoiDungIO.h"
#include "DoiTien.h"

#include <iostream>

using namespace std;

GuiTienSence::GuiTienSence()
{
}

GuiTienSence::GuiTienSence(NguoiDung * user) : NguoiDungSence(user)
{
}

void GuiTienSence::show()
{
	if (!user->isActived())
	{
		cout << "Tai khoan cua ban dang bi khoa. Vui long lien he nguoi quan tri de kich hoat." << endl;
		return;
	}

	bool success = false;

	// Nhập số tiền cần chuyển
	Tien tien;
	tien.Input();
	double tienDoi = DoiTien::doiTien(tien.getGiaTri(), user->getSoDu().getMaTien(), tien.getMaTien());
	double phiChuyen = DoiTien::getPhi(tien.getGiaTri(), user->getSoDu().getMaTien(), tien.getMaTien());
	cout << "Ban muon chuyen " << tienDoi << " " << user->getSoDu().getStringMaTien() << " vao tai khoan" << endl;
	cout << "Phi gui tien " << phiChuyen << endl;
	if (!IsUserContinue()) return;
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

bool GuiTienSence::GuiTien(double amount, double fee)
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
		}
		return updated;
	}
	return false;
}

GuiTienSence::~GuiTienSence()
{
}
