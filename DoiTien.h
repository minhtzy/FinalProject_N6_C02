#pragma once

#include "Tien.h"

class DoiTien
{
public:
	DoiTien();
	double getTien(double amount, Tien::MA_TIEN from, Tien::MA_TIEN to);
	double getTiGia(Tien::MA_TIEN from, Tien::MA_TIEN to);
	~DoiTien();

private:

};