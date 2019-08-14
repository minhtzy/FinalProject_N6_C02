#pragma once

#include "NguoiDung.h"
#include <vector>
#include <string>

class ThongBao
{

public:
	ThongBao();
	static void pushThongBao(NguoiDung * nguoiDung, std::string noiDung);
	static std::vector<std::string> danhSachThongBao(std::string soTaiKhoan);
	~ThongBao();
};