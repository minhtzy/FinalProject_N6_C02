#include "NganHang.h"
#include <iostream>

using namespace std;

NganHang::NganHang()
{
}

void NganHang::Input()
{
	cout << "Chon ngan hang: " << endl;
	cout << "1. Agribank - Ngan hang nong nghiep phat trien nong thon" << endl;
	cout << "2. VPBank - Ngan hang Viet Nam thinh vuong" << endl;
	cout << "3. BIDV - Ngan hang TMCP dau tu va phat trien Viet Nam" << endl;
	cout << "4. VietcomBank - Ngan hang TMCP Ngoai thuong Viet Nam" << endl;
	cout << "5. VietinBank - Ngan hang TMCP Cong thuong Viet Nam" << endl;
	int iChoice;
	do
	{
		cout << "Nhap lua chon: " << endl;
		cin >> iChoice;
	} while (iChoice < 1 || iChoice > 5);
	
	switch (iChoice)
	{
	case 1:
		setMaNH(NganHang::Agribank);
		break;	
	case 2:
		setMaNH(NganHang::VPBank);
		break;	
	case 3:
		setMaNH(NganHang::BIDV);
		break;	
	case 4:
		setMaNH(NganHang::VietcomBank);
		break;	
	case 5:
		setMaNH(NganHang::VietinBank);
		break;
	default:
		break;
	}	
}

NganHang::NganHang(MA_NGAN_HANG maNH)
{
	setMaNH(maNH);
}

NganHang::MA_NGAN_HANG NganHang::getMaNH()
{
	return maNH;
}

std::string NganHang::getStringMaNH()
{
	switch (maNH)
	{
	case NganHang::Agribank:
		return "Agribank";
	case NganHang::VPBank:
		return "VPBank";
	case NganHang::BIDV:
		return "BIDV";
	case NganHang::VietcomBank:
		return "VietcomBank";
	case NganHang::VietinBank:
		return "VietinBank";
	default:
		return "";
	}
}

void NganHang::setMaNH(MA_NGAN_HANG maNH)
{
	this->maNH = maNH;
	switch (maNH)
	{
	case NganHang::Agribank:
		strcpy(tenNH,"Ngan hang nong nghiep phat trien nong thon");
		break;
	case NganHang::VPBank:
		strcpy(tenNH, "Ngan hang Viet Nam thinh vuong");
		break;
	case NganHang::BIDV:
		strcpy(tenNH, "Ngan hang TMCP dau tu va phat trien Viet Nam");
		break;
	case NganHang::VietcomBank:
		strcpy(tenNH, "Ngan hang TMCP Ngoai thuong Viet Nam");
		break;
	case NganHang::VietinBank:
		strcpy(tenNH, "Ngan hang TMCP Cong thuong Viet Nam");
		break;
	default:
		strcpy(tenNH, "");
		break;
	}
}

std::string NganHang::getTenNH()
{
	return tenNH;
}

NganHang::~NganHang()
{
}
