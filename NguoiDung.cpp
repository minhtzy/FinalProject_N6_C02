#include "NguoiDung.h"

#include <iostream>
#include <iomanip>

using namespace std;

NguoiDung::NguoiDung() : isActive(true)
{
}

void NguoiDung::Input()
{
	double balance;
	Nguoi::Input();
	cout << "Nhap so tai khoan: ";
	cin >> soTaiKhoan;
	cout << "Nhap mat khau: ";
	cin >> matKhau;
	nganHang.Input();
	cout << "Nhap so du tai khoan: ";
	cin >> balance;
	soDu = Tien(balance, Tien::VND);
}

void NguoiDung::Output()
{
	cout << "So tai khoan: " << soTaiKhoan << endl;
	Nguoi::Output();
	cout << "Ngan hang: " << nganHang.getTenNH() << endl;
	cout << "So Du: " << std::fixed << setprecision(0)<< soDu.getGiaTri() << " " << soDu.getKyHieu() <<endl;
	cout << "Trang thai: " << (isActive ? "Kich hoat" : "Khong kich hoat") << endl;
}

std::string NguoiDung::getSoTaiKhoan()
{
	return soTaiKhoan;
}

void NguoiDung::setSoTaiKhoan(std::string soTK)
{
	strcpy(this->soTaiKhoan, soTK.c_str());
}

std::string NguoiDung::getMatKhau()
{
	return matKhau;
}

void NguoiDung::setMatKhau(std::string matKhau)
{
	strcpy(this->matKhau,matKhau.c_str());
}

void NguoiDung::setActive(bool active)
{
	isActive = active;
}

bool NguoiDung::isActived()
{
	return isActive;
}

Tien NguoiDung::getSoDu()
{
	return soDu;
}

void NguoiDung::setSoDu(Tien soDu)
{
	this->soDu = soDu;
}

NganHang NguoiDung::getNganHang()
{
	return nganHang;
}

void NguoiDung::setNganHang(NganHang nganHang)
{
	this->nganHang = nganHang;
}

NguoiDung::~NguoiDung()
{
	//delete this;
}
