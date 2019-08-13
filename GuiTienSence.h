#pragma once
#include "NguoiDungSence.h"

class GuiTienSence : public NguoiDungSence
{
public:
	GuiTienSence();
	GuiTienSence(NguoiDung * user);
	void show() override;
	bool GuiTien(double amount, double fee);
	~GuiTienSence();

private:

};