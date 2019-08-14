#include "KhieuNai.h"
#include <fstream>
#include "Definations.h"
#include <ctime>

using namespace std;
KhieuNai::KhieuNai()
{
}

KhieuNai::KhieuNai(std::string soTaiKhoan, std::string noiDung) : soTaiKhoan(soTaiKhoan), noiDung(noiDung)
{
	time_t now = time(NULL);
	std::tm * ptm = localtime(&now);
	char time_buffer[32];
	//Format: Mo 15.06.2009 20:20:00
	std::strftime(time_buffer, 32, "%a %d.%m.%Y %H:%M:%S", ptm);

	thoiGian = string(time_buffer);
}

std::string KhieuNai::getSoTaiKhoan()
{
	return soTaiKhoan;
}

std::string KhieuNai::getThoiGian()
{
	return thoiGian;
}

std::string KhieuNai::getNoiDung()
{
	return noiDung;
}

void KhieuNai::WriteToFile()
{
	fstream file;
	file.open(KHIEU_NAI_FILE_PATH, ios::app | ios::out);
	file.seekp(0, ios::end);
	string msg = toString();
	file << msg << endl;
}

std::vector<KhieuNai> KhieuNai::danhSachKhieuNai()
{
	std::vector<KhieuNai> dsKhieuNai;
	string data;
	ifstream iFile;
	iFile.open(KHIEU_NAI_FILE_PATH);
	if (iFile.is_open())
	{
		getline(iFile, data);
		while (!iFile.eof())
		{
			KhieuNai khieuNai;
			khieuNai.parseFromString(data);
			dsKhieuNai.push_back(khieuNai);
			getline(iFile, data);
		}
	}
	return dsKhieuNai;
}

void KhieuNai::parseFromString(std::string data)
{
	int found = data.find_first_of(',');
	if (found != string::npos)
	{
		soTaiKhoan = data.substr(0,found);
		int found1 = data.find_first_of(',', found + 1);
		thoiGian = data.substr(found + 1, found1 - found);
		noiDung = data.substr(found1 + 1);
	}
}

std::string KhieuNai::toString()
{
	return std::string(soTaiKhoan).append(",").append(thoiGian).append(",").append(noiDung);
}
