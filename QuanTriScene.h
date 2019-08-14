#pragma once

#include "Scene.h"
#include "QuanTri.h"
class QuanTriScene : public Scene
{
public:
	QuanTriScene();
	virtual void show() = 0;
	QuanTriScene(QuanTri * quanTri);
	~QuanTriScene();

protected:
	QuanTri* quanTri;
};