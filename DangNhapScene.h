#pragma once
#include "Scene.h"

class DangNhapScene : public Scene
{
public:
	DangNhapScene();
	void show() override;
	void doNguoiDungDangNhap();
	void doQuanTriDangNhap();
	void doAddQuanTri();
	~DangNhapScene();

};