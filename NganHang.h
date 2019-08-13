#pragma once
#include <string>

class NganHang
{
public:
	enum MA_NGAN_HANG
	{
		Agribank = 1,
		VPBank,
		BIDV,
		VietcomBank,
		VietinBank
	};
	NganHang();
	void Input();
	NganHang(MA_NGAN_HANG maNH);
	MA_NGAN_HANG getMaNH();
	std::string getStringMaNH();
	void setMaNH(MA_NGAN_HANG maNH);
	std::string getTenNH();
	~NganHang();
private:
	MA_NGAN_HANG maNH;
	char tenNH[50];
	//std::string chiNhanh;
};
