#include <iostream>
#include<fstream>
#include"ChuyenTienScene.h"
#include"PhiChuyenTien.h"
#include "NguoiDungIO.h"
using namespace std;

 ChuyenTienScene::ChuyenTienScene(){
}
 ChuyenTienScene::ChuyenTienScene(NguoiDung * user) : NguoiDungScene(user) {

}
void ChuyenTienScene::show() {
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
	do{
		cout << "Nhap so tien can rut" << "(" << user->getSoDu().getStringMaTien() << ") : ";
		cin >> amount;
		success = ChuyenTien(user1,amount);

		if (success)
		{
			cout << "Chuyen tien thanh cong. " << endl;
		}
		else
		{
			cout << "So tien trong tai khoan khong du." << endl;
		}
	} while (IsUserContinue());
}
bool ChuyenTienScene::ChuyenTien(NguoiDung* user1,double amount)
{

	PhiChuyenTien phi;
	if (amount > 0 && amount <= user->getSoDu().getGiaTri())
	{
		bool updated = false;
		double a = phi.getPhiChuyenTien(user->getNganHang().getStringMaNH(), user1->getNganHang().getStringMaNH());
		user->setSoDu(user->getSoDu() - amount - a);
		user1->setSoDu(user1->getSoDu() + amount);

		NguoiDungIO ndIO;
		updated = ndIO.updateNguoiDung(user);
		if (!updated)
		{
			user->setSoDu(user->getSoDu() + amount + a);
			return false;
		}
		updated = ndIO.updateNguoiDung(user1);
		if (!updated)
		{
			user1->setSoDu(user1->getSoDu()- amount );
			return false;
		}
		/*acc.balance -= amount;
		bool updated = Update(acc);
		if (updated)
		{
		LogRutTien(acc, amount, msg);
		}
		else {
		acc.balance += amount;
		}*/

		return true;
	}
	return false;
}

ChuyenTienScene::~ChuyenTienScene()
{
}
