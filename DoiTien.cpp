#include "DoiTien.h"

DoiTien::DoiTien()
{
}

double DoiTien::getTien(double amount, Tien::MA_TIEN from, Tien::MA_TIEN to)
{
	return amount * getTiGia(from,to);
}

double DoiTien::getTiGia(Tien::MA_TIEN from, Tien::MA_TIEN to)
{
	// TO DO: get Ti gia tien
	return 1.0f;
}

DoiTien::~DoiTien()
{
}
