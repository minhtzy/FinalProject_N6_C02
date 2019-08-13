#include "SaoKeNguoiDungScene.h"
#include "Definations.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
SaoKeNguoiDungScene::SaoKeNguoiDungScene()
{
}

SaoKeNguoiDungScene::SaoKeNguoiDungScene(NguoiDung * user) : NguoiDungScene(user)
{
}

void SaoKeNguoiDungScene::show()
{
	cout << "======================= SAO KE =========================" << endl;
	user->Output();
	doSaoKeRutTien();
	doSaoKeGuiTien();
	doSaoKeChuyenTien();
}

SaoKeNguoiDungScene::~SaoKeNguoiDungScene()
{
}

void SaoKeNguoiDungScene::doSaoKeRutTien()
{
	cout << "------- Lich su rut tien ---------------" << endl;
	ifstream iFile;
	iFile.open(LOG_RUT_TIEN_FILE_PATH);

	std::string line;
	std::string soTK, message;
	int first_space = 0;
	while (!iFile.eof())
	{
		getline(iFile, line);
		first_space = line.find_first_of(' ');
		if (first_space != string::npos) {
			soTK = line.substr(0, first_space);
			message = line.substr(first_space);
			if (user->getSoTaiKhoan().compare(soTK) == 0)
			{
				cout << message << endl;
			}
		}

	}
}

void SaoKeNguoiDungScene::doSaoKeChuyenTien()
{
	cout << "------- Lich su chuyen tien ---------------" << endl;
	ifstream iFile;
	iFile.open(LOG_CHUYEN_TIEN_FILE_PATH);

	std::string line;
	std::string soTK, message;
	int first_space = 0;
	while (!iFile.eof())
	{
		getline(iFile, line);
		first_space = line.find_first_of(' ');
		if (first_space != string::npos) {
			soTK = line.substr(0, first_space);
			message = line.substr(first_space);
			if (user->getSoTaiKhoan().compare(soTK) == 0)
			{
				cout << message << endl;
			}
		}
	}
}

void SaoKeNguoiDungScene::doSaoKeGuiTien()
{
	cout << "------- Lich su gui tien ---------------" << endl;
	ifstream iFile;
	iFile.open(LOG_GUI_TIEN_FILE_PATH);

	std::string line;
	std::string soTK, message;
	int first_space = 0;
	while (!iFile.eof())
	{
		getline(iFile, line);
		first_space = line.find_first_of(' ');
		if (first_space != string::npos) {
			soTK = line.substr(0, first_space);
			message = line.substr(first_space);
			if (user->getSoTaiKhoan().compare(soTK) == 0)
			{
				cout << message << endl;
			}
		}
	}
}
