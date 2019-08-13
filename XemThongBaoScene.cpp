#include "XemThongBaoScene.h"
#include "Definations.h"

#include <iostream>
#include <fstream>
using namespace std;
XemThongBaoScene::XemThongBaoScene()
{
}

XemThongBaoScene::XemThongBaoScene(NguoiDung * user) : NguoiDungScene(user)
{
	
}

void XemThongBaoScene::show()
{
	cout << "======================= THONG BAO =========================" << endl;
	ifstream iFile;
	iFile.open(THONG_BAO_FILE_PATH);

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

XemThongBaoScene::~XemThongBaoScene()
{
}
