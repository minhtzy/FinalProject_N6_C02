#pragma once
#include "Sence.h"

class DangNhapSence : public Sence
{
public:
	DangNhapSence();
	void show() override;
	void doNguoiDungDangNhap();
	void doQuanTriDangNhap();
	~DangNhapSence();

};