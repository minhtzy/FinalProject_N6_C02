#pragma once
#include "NguoiDungScene.h"

class GuiTienScene : public NguoiDungScene
{
public:
	GuiTienScene();
	GuiTienScene(NguoiDung * user);
	void show() override;
	bool GuiTien(double amount, double fee);
	~GuiTienScene();

private:

};