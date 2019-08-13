#pragma once

#include "Tien.h"

class DoiTien
{
public:
	DoiTien();
	static double doiTien(double amount, Tien::MA_TIEN from, Tien::MA_TIEN to);
	static double getTiGia(Tien::MA_TIEN from, Tien::MA_TIEN to);
	static double getPhi(double amount,Tien::MA_TIEN from, Tien::MA_TIEN to);
	static double getPhiDoi(Tien::MA_TIEN from, Tien::MA_TIEN to);
	~DoiTien();

private:

};