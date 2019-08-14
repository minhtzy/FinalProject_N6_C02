#pragma once
#include "QuanTriScene.h"

class TaoNguoiDungScene : public QuanTriScene
{
public:
	TaoNguoiDungScene();
	TaoNguoiDungScene(QuanTri * quanTri);
	void show() override;
	~TaoNguoiDungScene();

private:

};