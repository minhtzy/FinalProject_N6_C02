#include "XemThongBaoScene.h"
#include "ThongBao.h"

#include <iostream>

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
	std::vector<std::string> thongBao = ThongBao::danhSachThongBao(user->getSoTaiKhoan());

	for (int i = 0; i < thongBao.size(); ++i)
	{
		cout << thongBao[i] << endl;
	}
}

XemThongBaoScene::~XemThongBaoScene()
{
}
