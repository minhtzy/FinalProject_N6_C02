#include "RutTienScene.h"
#include <iostream>

#include "NguoiDungIO.h"
#include "DoiTien.h"

using namespace std;

RutTienScene::RutTienScene()
{
}

RutTienScene::RutTienScene(NguoiDung * user) : NguoiDungScene(user)
{
}

void RutTienScene::show()
{

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
		}
		else
		{
			cout << "So tien trong tai khoan khong du." << endl;
		}
	} while (!success);
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
		}
		return updated;
	}
	return false;
}

RutTienScene::~RutTienScene()
{
}
