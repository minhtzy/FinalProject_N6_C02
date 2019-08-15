#include "XuLyKhieuNaiScene.h"
#include "KhieuNai.h"
#include "SuaTTNguoiDungScene.h"

#include <iostream>
#include <iomanip>

using namespace std;

XuLyKhieuNaiScene::XuLyKhieuNaiScene()
{
}

XuLyKhieuNaiScene::XuLyKhieuNaiScene(QuanTri * quanTri) : QuanTriScene(quanTri)
{
}

void XuLyKhieuNaiScene::show()
{
	std::vector<KhieuNai> dsKhieuNai = KhieuNai::danhSachKhieuNai();
	cout << "====================== DANH SACH KHIEU NAI =====================" << endl;
	cout  <<setw(5) << left << "STT"<< setw(15) << left <<"So tai khoan" <<setw(25) << left <<"Thoi gian" << "Noi dung" << endl;
	for (int i = 0; i < dsKhieuNai.size(); ++i)
	{
		cout << setw(5) << left << i + 1 << setw(15) << left << dsKhieuNai[i].getSoTaiKhoan() << setw(25) << left << dsKhieuNai[i].getThoiGian() << dsKhieuNai[i].getNoiDung() << endl;
	}
	while (IsUserContinue("Ban co muon xu ly khieu nai. Tiep tuc?"))
	{
		SuaTTNguoiDungScene suaTT(quanTri);
		suaTT.show();
	}

}

XuLyKhieuNaiScene::~XuLyKhieuNaiScene()
{
}
