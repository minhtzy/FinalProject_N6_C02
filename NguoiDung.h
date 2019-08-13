#pragma once

#include <string>

#include "Nguoi.h"
#include "NganHang.h"
#include "Tien.h"

class NguoiDung : public Nguoi
{
public:
	NguoiDung();
	//NguoiDung(std::string soCMND, std::string hoVaTen, std::string diaChi, time_t ngaySinh, std::string soTaiKhoan, std::string matKhau, NganHang nganHang, Tien soDu, bool active);
	void Input() override;
	void Output() override;
	std::string getSoTaiKhoan();
	void setSoTaiKhoan(std::string soTK);
	std::string getMatKhau();
	void setMatKhau(std::string matKhau);
	NganHang getNganHang();
	void setNganHang(NganHang nganHang);
	Tien getSoDu();
	void setSoDu(Tien soDu);
	void setActive(bool active);
	bool isActived();
	~NguoiDung() override;
protected:
	char soTaiKhoan[15];
	char matKhau[15];
	NganHang nganHang;
	Tien soDu;
	bool isActive;

};