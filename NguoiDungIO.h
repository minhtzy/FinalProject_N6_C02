#pragma once
#include <vector>
#include "NguoiDung.h"

class NguoiDungIO
{
public:
	NguoiDungIO();
	NguoiDung * getNguoiDung(std::string soTaiKhoan);
	bool addNguoiDung(NguoiDung * thongTin);
	bool updateNguoiDung(NguoiDung * thongTin);
	bool deleteNguoiDung(std::string soTaiKhoan);
	NguoiDung * checkLogin(std::string soTaiKhoan, std::string matKhau);
	~NguoiDungIO();

private:

};
