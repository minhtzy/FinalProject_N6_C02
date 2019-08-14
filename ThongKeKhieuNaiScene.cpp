#include "ThongKeKhieuNaiScene.h"
#include <iostream>

using namespace std;

ThongKeKhieuNaiScene::ThongKeKhieuNaiScene()
{
}

ThongKeKhieuNaiScene::ThongKeKhieuNaiScene(QuanTri * quanTri) : QuanTriScene(quanTri)
{
}

void ThongKeKhieuNaiScene::show()
{
	cout << "======================= THONG KE KHIEU NAI ===========================" << endl;
	cout << "TRANG DANG PHAT TRIEN. COMMING SOON !!!";
	//TODO: Thong ke khieu nai

}

ThongKeKhieuNaiScene::~ThongKeKhieuNaiScene()
{
}
