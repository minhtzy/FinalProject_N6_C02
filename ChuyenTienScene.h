#pragma once
#include<iostream>
#include"NguoiDungScene.h"
#include"PhiChuyenTien.h"
using namespace std;

class ChuyenTienScene: public NguoiDungScene, public NganHang {
	public:
		ChuyenTienScene();
		ChuyenTienScene(NguoiDung * user);
		void show() override;
		bool ChuyenTien(NguoiDung * user1, double amount, double fee);
		void LogChuyenTien(NguoiDung * user1,double amount, double fee);
		~ChuyenTienScene();
};