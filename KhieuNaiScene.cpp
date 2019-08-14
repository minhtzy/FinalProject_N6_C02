#include "KhieuNaiScene.h"
#include<fstream>
#include<iostream>
#include"NguoiDungIO.h"
#include "Definations.h"
#include "KhieuNai.h"

using namespace std;
KhieuNaiScene::KhieuNaiScene() {

}
KhieuNaiScene::KhieuNaiScene(NguoiDung* user) : NguoiDungScene (user) {

}
void KhieuNaiScene::show()
{
	GuiKhieuNai();
}
void KhieuNaiScene::GuiKhieuNai()
{	
	cout << "======================= GUI KHIEU NAI =========================" << endl;
	string msg;
	cout << "Thong tin khieu nai: "; 
	cin.ignore();
	getline(cin, msg);
	KhieuNai khieuNai(user->getSoTaiKhoan(),msg);
	khieuNai.WriteToFile();
	cout << "Gui thong tin khieu nai thanh cong" << endl;
}

KhieuNaiScene::~KhieuNaiScene()
{
}

