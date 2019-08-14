#pragma once
#include "QuanTriScene.h"

class XuLyKhieuNaiScene : public QuanTriScene
{
public:
	XuLyKhieuNaiScene();
	XuLyKhieuNaiScene(QuanTri * quanTri);
	void show() override;
	~XuLyKhieuNaiScene();
};