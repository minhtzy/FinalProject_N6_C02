#pragma once
#include <string>

class Tien
{
public:
	enum MA_TIEN
	{
		VND = 1,
		USD,
		GBP,
		CNY,
		EUR
	};
	Tien();
	Tien(double soTien, MA_TIEN maTien = Tien::VND);
	
	Tien operator+(const Tien& tien);
	Tien operator+(double amount);
	Tien& operator+=(double amount);

	Tien operator-(const Tien& tien);
	Tien operator-(double amount);
	Tien& operator-=(double amount);
	
	Tien operator*(int num);
	Tien operator/(int num);
	void Input();
	MA_TIEN getMaTien();
	std::string getStringMaTien();
	void setMaTien(MA_TIEN maTien);
	double getGiaTri();
	std::string getKyHieu();
	~Tien();

private:
	MA_TIEN maTien;
	double soTien;
};