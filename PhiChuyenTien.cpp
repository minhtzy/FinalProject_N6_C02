#include<iostream>
#include<fstream>
#include"PhiChuyenTien.h"
#include"NguoiDungIO.h"
using namespace std;

PhiChuyenTien::PhiChuyenTien() {

}

double PhiChuyenTien::getPhiChuyenTien(std::string fromBank, std::string toBank)
{
	fstream file;
	string from;
	string to;
	double fee;

	file.open("phichuyen.dat", ios::app | ios::in);
	while (!file.eof()) {
		file >> from >> to >> fee;
		if (fromBank.compare(from) == 0 && toBank.compare(to) == 0)
		{
			return fee;
		}
	}

	return 0;

}

PhiChuyenTien::~PhiChuyenTien()
{
}



