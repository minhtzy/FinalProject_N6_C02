#pragma once
#include<iostream>

#include"NguoiDungScene.h"
#include"NguoiDung.h"
using namespace std;

class KhieuNaiScene : public NguoiDungScene {
public:
	KhieuNaiScene();
	KhieuNaiScene(NguoiDung* user);
	void show() override;
	void GuiKhieuNai();
	~KhieuNaiScene();
};