#pragma once
#include <string>
#include <vector>

class KhieuNai
{
public:
	KhieuNai();
	KhieuNai(std::string soTaiKhoan, std::string noiDung);
	std::string getSoTaiKhoan();
	std::string getThoiGian();
	std::string getNoiDung();
	void WriteToFile();
	static std::vector<KhieuNai> danhSachKhieuNai();
	void parseFromString(std::string data);
	std::string toString();
protected:
	std::string soTaiKhoan;
	std::string thoiGian;
	std::string noiDung;
};