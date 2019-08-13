#pragma once
#include<iostream>

#include"NguoiDungScene.h"
#include"NguoiDung.h"
using namespace std;

class KhieuNai : public NguoiDungScene {
public:
	KhieuNai();
	KhieuNai(NguoiDung* user);
	void show() override;
	void GuiKhieuNai();
	~KhieuNai();
};