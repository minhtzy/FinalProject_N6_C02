#pragma once
#include "NguoiDungScene.h"
class MenuNguoiDung : public NguoiDungScene
{

public:
	MenuNguoiDung();
	MenuNguoiDung(NguoiDung * user);
	void show() override;
	~MenuNguoiDung();
protected:

};
