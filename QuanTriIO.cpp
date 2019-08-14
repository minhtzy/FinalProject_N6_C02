#include "QuanTriIO.h"
#include "Definations.h"
#include <fstream>

using namespace std;

QuanTriIO::QuanTriIO()
{
}

QuanTri * QuanTriIO::getQuanTri(std::string username)
{
	ifstream iFile;
	iFile.open(NGUOI_DUNG_FILE_PATH, ios::in | ios::binary);

	QuanTri * temp = new QuanTri;
	iFile.read((char *)(temp), sizeof(QuanTri));
	while (!iFile.eof())
	{

		if (temp->getUsername().compare(username) == 0)
		{
			QuanTri* result = new QuanTri();
			*result = *temp; // fix __vtptr error
			return result;
		}

		iFile.read((char *)(temp), sizeof(QuanTri));
	}
	return nullptr;
}

bool QuanTriIO::checkLogin(std::string username, std::string password)
{
	ifstream iFile;
	iFile.open(QUAN_TRI_FILE_PATH, ios::in | ios::binary);

	QuanTri * temp = new QuanTri;
	iFile.read((char *)(temp), sizeof(QuanTri));
	while (!iFile.eof())
	{
		if (temp->getUsername().compare(username) == 0 && temp->getPassword().compare(password) == 0)
		{
			return true;
		}
		iFile.read((char *)(temp), sizeof(QuanTri));
	}
	return false;
}

bool QuanTriIO::addQuanTri(QuanTri * quantri)
{
	ofstream oFile;
	oFile.open(QUAN_TRI_FILE_PATH, ios::out | ios::binary | ios::app);
	oFile.seekp(0, oFile.end);
	oFile.write((char *)quantri, sizeof(QuanTri));
	oFile.close();
	return true;
}

QuanTriIO::~QuanTriIO()
{
}
