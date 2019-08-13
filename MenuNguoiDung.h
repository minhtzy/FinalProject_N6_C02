#pragma once
#include "NguoiDungSence.h"
class MenuNguoiDung : public NguoiDungSence
{

public:
	MenuNguoiDung();
	MenuNguoiDung(NguoiDung * user);
	void show() override;
	~MenuNguoiDung();
protected:

};
