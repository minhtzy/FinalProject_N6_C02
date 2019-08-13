#pragma once

#include "NguoiDungScene.h"

class XemThongBaoScene : public NguoiDungScene
{
public:
	XemThongBaoScene();
	XemThongBaoScene(NguoiDung * user);
	void show() override;
	~XemThongBaoScene();

private:

};