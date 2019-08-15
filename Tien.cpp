#include "Tien.h"
#include <iostream>

using namespace std;

Tien::Tien() : maTien(Tien::VND), soTien(0)
{
}

Tien::Tien(double soTien, MA_TIEN maTien): soTien(soTien) , maTien(maTien)
{
}

Tien Tien::operator+(const Tien & tien)
{
	if (maTien == tien.maTien)
	{
		return Tien(soTien + tien.soTien, maTien);
	}
	return Tien();
}

Tien Tien::operator-(const Tien & tien)
{
	if (maTien == tien.maTien)
	{
		return Tien(soTien - tien.soTien, maTien);
	}
	return Tien();
}

Tien Tien::operator+(double amount)
{
	return Tien(soTien + amount, maTien); 
}

Tien& Tien::operator+=(double amount)
{
	this->soTien += amount;
	return *this;
}

Tien Tien::operator-(double amount)
{
	return Tien(soTien - amount, maTien);
}

Tien& Tien::operator-=(double amount)
{
	this->soTien += amount;
	return *this;
}

Tien Tien::operator*(int num)
{
	return Tien(this->soTien * num,maTien);
}

Tien Tien::operator/(int num)
{
	return Tien(this->soTien / num, maTien);
}

void Tien::Input()
{
	cout << "Chon loai tien: " << endl;
	cout << "1. VND - Viet Nam Dong" << endl;
	cout << "2. USD - Dola My" << endl;
	cout << "3. GBP - Bang Anh" << endl;
	cout << "4. CNY - Nhan dan te" << endl;
	cout << "5. EUR - EURO" << endl;
	int iChoice;
	do
	{
		cout << "Nhap lua chon: " << endl;
		cin >> iChoice;
	} while (iChoice < 1 || iChoice > 5);

	switch (iChoice)
	{
	case 1:
		maTien = Tien::VND;
		break;
	case 2:
		maTien = Tien::USD;
		break;
	case 3:
		maTien = Tien::GBP;
		break;
	case 4:
		maTien = Tien::CNY;
		break;
	case 5:
		maTien = Tien::EUR;
		break;
	default:
		break;
	}

	cout << "Nhap so tien(" << getStringMaTien() << ") :";
	cin >> soTien;
}

Tien::MA_TIEN Tien::getMaTien()
{
	return maTien;
}

std::string Tien::getStringMaTien()
{
	switch (maTien)
	{
	case Tien::USD:
		return "USD";
	case Tien::GBP:
		return "GBP";
	case Tien::VND:
		return "VND";
	case Tien::CNY:
		return "CNY";
	case Tien::EUR:
		return "EUR";
	default:
		return "";
	}
}

void Tien::setMaTien(MA_TIEN maTien)
{
	this->maTien = maTien;
}

double Tien::getGiaTri()
{
	return soTien;
}

std::string Tien::getKyHieu()
{
	switch (maTien)
	{
	case Tien::USD:
		return "$";
	case Tien::GBP:
		return "£";
	case Tien::VND:
		return "VND";
	case Tien::CNY:
		return "¥";
	case Tien::EUR:
		return "€";
	default:
		return "";
	}
}

Tien::~Tien()
{
}
