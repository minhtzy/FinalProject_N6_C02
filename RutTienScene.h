#pragma once
#include "NguoiDungScene.h"

class RutTienScene : public NguoiDungScene
{
public:
	RutTienScene();
	RutTienScene(NguoiDung * user);
	void show() override;
	bool RutTien(double amount);
	~RutTienScene();

private:

};