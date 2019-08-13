#pragma once
#include "NguoiDungSence.h"

class RutTienSence : public NguoiDungSence
{
public:
	RutTienSence();
	RutTienSence(NguoiDung * user);
	void show() override;
	bool RutTien(double amount);
	~RutTienSence();

private:

};