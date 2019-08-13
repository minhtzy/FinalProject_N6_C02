#include "NguoiDungIO.h"
#include <fstream>
#include "Definations.h"

using namespace std;

NguoiDungIO::NguoiDungIO()
{
}

NguoiDung * NguoiDungIO::getNguoiDung(std::string soTaiKhoan)
{
	ifstream iFile;
	iFile.open(NGUOI_DUNG_FILE_PATH, ios::in | ios::binary);

	NguoiDung * temp= new NguoiDung;
	iFile.read((char *)(temp), sizeof(NguoiDung));
	while (!iFile.eof())
	{
		
		if (temp->getSoTaiKhoan().compare(soTaiKhoan) == 0)
		{ 
			NguoiDung* result =  new NguoiDung();
			*result = *temp; // fix __vtptr error
			return result;
		}

		iFile.read((char *)(temp), sizeof(NguoiDung));
	}
	//delete temp;
	return nullptr;
}

bool NguoiDungIO::addNguoiDung(NguoiDung * thongTin)
{
	ofstream oFile;
	oFile.open(NGUOI_DUNG_FILE_PATH,ios::out | ios::binary | ios::app);
	oFile.seekp(0,oFile.end);
	oFile.write((char *)thongTin, sizeof(NguoiDung));
	return true;
}

bool NguoiDungIO::updateNguoiDung(NguoiDung * thongTin)
{
	fstream file;
	file.open(NGUOI_DUNG_FILE_PATH, ios::in | ios::out | ios::binary);
	streampos posg = file.beg;
	NguoiDung * temp = new NguoiDung();
	file.read((char *)temp, sizeof(NguoiDung));
	while (!file.eof())
	{
		if (temp->getSoTaiKhoan().compare(thongTin->getSoTaiKhoan()) == 0)
		{
			file.seekp(posg);
			file.write((char *)thongTin, sizeof(NguoiDung));
			//delete temp;
			return true;
		}
		posg = file.tellg();
		file.read((char *)temp, sizeof(NguoiDung));
	}

	//delete temp;
	return false;
}

bool NguoiDungIO::deleteNguoiDung(std::string soTaiKhoan)
{
	return false;
}

bool NguoiDungIO::checkLogin(std::string soTaiKhoan, std::string matKhau)
{
	ifstream iFile;
	iFile.open(NGUOI_DUNG_FILE_PATH, ios::in | ios::binary);

	NguoiDung * temp = new NguoiDung;
	iFile.read((char *)(temp), sizeof(NguoiDung));
	while (!iFile.eof())
	{
		if (temp->getSoTaiKhoan().compare(soTaiKhoan) == 0 && temp->getMatKhau().compare(matKhau) == 0)
		{
			return true;
		}
		iFile.read((char *)(temp), sizeof(NguoiDung));
	}
	return false;
}

NguoiDungIO::~NguoiDungIO()
{
}
