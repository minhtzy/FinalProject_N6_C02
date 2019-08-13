#pragma once

#include "NguoiDungScene.h"

class SaoKeNguoiDungScene : public NguoiDungScene
{
public:
	SaoKeNguoiDungScene();
	SaoKeNguoiDungScene(NguoiDung * user);
	void show() override;
	~SaoKeNguoiDungScene();

private:
	void doSaoKeRutTien();
	void doSaoKeChuyenTien();
	void doSaoKeGuiTien();

};