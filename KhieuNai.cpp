#include "KhieuNai.h"
#include<fstream>
#include<iostream>
#include"NguoiDungIO.h"
using namespace std;
KhieuNai::KhieuNai() {

}
KhieuNai::KhieuNai(NguoiDung* user) : NguoiDungScene (user) {

}
void KhieuNai::show()
{
	GuiKhieuNai();
}
void KhieuNai::GuiKhieuNai()
{	
	string msg;
	fstream file;
	file.open("KhieuNai.dat", ios::app | ios::out);
	file << user->getSoTaiKhoan()<<endl;
	cout << "Thong tin khieu nai: "; 
	getline(cin, msg);
	file << msg;
}

KhieuNai::~KhieuNai()
{
}

