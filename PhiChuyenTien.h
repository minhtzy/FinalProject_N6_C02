#pragma once
#include<iostream>
#include"NguoiDungIO.h"
#include<fstream>
#include"Tien.h"


class PhiChuyenTien {

public:
	PhiChuyenTien();
	double getPhiChuyenTien(std::string fromBank, std::string toBank);
	~PhiChuyenTien();

};