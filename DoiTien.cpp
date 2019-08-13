#include "DoiTien.h"
#include <fstream>
#include "Definations.h"

using namespace std;

DoiTien::DoiTien()
{
}

double DoiTien::doiTien(double amount, std::string from, std::string to)
{
	if (from.compare(to) == 0) return amount;
	return amount * getTiGia(from,to);
}

double DoiTien::getPhi(double amount, std::string from, std::string to)
{
	return amount * getPhiDoi(from, to);
}

double DoiTien::getTiGia(std::string from, std::string to)
{
	if (from.compare(to) == 0) return 1.0;
	ifstream iFile;
	iFile.open(TI_GIA_FILE_PATH);
	string maDau, maCuoi;
	double tiGia, phi;
	while (!iFile.eof())
	{
		iFile >> maDau >> maCuoi >> tiGia >> phi;
		if (maDau.compare(from) == 0 && maCuoi.compare(to) == 0)
		{
			return tiGia;
		}
	}
	return 1.0;
}



double DoiTien::getPhiDoi(std::string from, std::string to)
{
	if (from.compare(to) == 0) return 0;
	ifstream iFile;
	iFile.open(TI_GIA_FILE_PATH);
	string maDau, maCuoi;
	double tiGia, phi;
	while (!iFile.eof())
	{
		iFile >> maDau >> maCuoi >> tiGia >> phi;
		if (maDau.compare(from) == 0 && maCuoi.compare(to) == 0)
		{
			return phi;
		}
	}
	return 0;
}

DoiTien::~DoiTien()
{
}
