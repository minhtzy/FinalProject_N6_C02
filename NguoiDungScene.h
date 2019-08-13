#pragma once
#include "Scene.h"
#include "NguoiDung.h"
class NguoiDungScene : public Scene
{
public:
	NguoiDungScene();
	virtual void show() = 0;
	NguoiDungScene(NguoiDung * user);
	~NguoiDungScene();

protected:
	NguoiDung* user;
};