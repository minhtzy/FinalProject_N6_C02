#include "DoiTien.h"

DoiTien::DoiTien()
{
}

double DoiTien::doiTien(double amount, Tien::MA_TIEN from, Tien::MA_TIEN to)
{
	if (from == to) return amount;
	return amount * getTiGia(from,to);
}

double DoiTien::getTiGia(Tien::MA_TIEN from, Tien::MA_TIEN to)
{
	if (from == to) return 1.0f;
	// TO DO: get Ti gia tien
	return 1.0f;
}

double DoiTien::getPhi(double amount, Tien::MA_TIEN from, Tien::MA_TIEN to)
{
	return amount * getPhiDoi(from, to);
}

double DoiTien::getPhiDoi(Tien::MA_TIEN from, Tien::MA_TIEN to)
{
	if (from == to) return 0;

}

DoiTien::~DoiTien()
{
}
