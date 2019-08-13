#include "KhieuNaiScene.h"
#include<fstream>
#include<iostream>
#include"NguoiDungIO.h"
#include "Definations.h"

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
	fstream file;
	file.open(KHIEU_NAI_FILE_PATH, ios::app | ios::out);
	cout << "Thong tin khieu nai: "; 
	getline(cin, msg);
	file << user->getSoTaiKhoan() << " " << msg << endl;
}

KhieuNaiScene::~KhieuNaiScene()
{
}

