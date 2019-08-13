#pragma once
#include <string>

class DoiTien
{
public:
	DoiTien();
	static double doiTien(double amount, std::string from, std::string to);
	static double getTiGia(std::string from, std::string to);
	static double getPhi(double amount,std::string from, std::string to);
	static double getPhiDoi(std::string from, std::string to);
	~DoiTien();

private:

};