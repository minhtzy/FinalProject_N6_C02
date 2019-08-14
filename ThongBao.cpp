#include "ThongBao.h"
#include <ctime>
#include <fstream>
#include "Definations.h"

using namespace std;
ThongBao::ThongBao()
{
}
void ThongBao::pushThongBao(NguoiDung * nguoiDung, std::string noiDung)
{
	time_t now = time(NULL);
	std::tm * ptm = localtime(&now);
	char time_buffer[32];
	//Format: Mo, 15.06.2009 20:20:00
	std::strftime(time_buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);

	std::string message;
	message.append(nguoiDung->getSoTaiKhoan()).append(" [").append(time_buffer).append("] ").append(noiDung);
	fstream file;
	file.open(THONG_BAO_FILE_PATH, ios::app | ios::out);
	file.seekp(0, ios::end);
	file << message << endl;
}

std::vector<std::string> ThongBao::danhSachThongBao(std::string soTaiKhoan)
{
	std::vector<std::string> thongBao;
	string data;
	ifstream iFile;
	iFile.open(THONG_BAO_FILE_PATH);
	if (iFile.is_open())
	{
		getline(iFile, data);
		while (!iFile.eof())
		{
			int found = data.find_first_of(' ');
			if (found != std::string::npos)
			{
				std::string soTK = data.substr(0, found); // tách lấy số tài khoản
				if (soTK.compare(soTaiKhoan) == 0) thongBao.push_back(data.substr(found + 1));
			}
			getline(iFile, data);
		}
	}

	return thongBao;
}

ThongBao::~ThongBao()
{
}
