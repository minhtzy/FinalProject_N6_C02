#pragma once

#include "QuanTriScene.h"

class MenuQuanTri : public QuanTriScene
{
public:
	MenuQuanTri();
	MenuQuanTri(QuanTri * quanTri);
	void show() override;
	~MenuQuanTri();

private:

};
