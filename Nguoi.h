#pragma once

#include <string>
#include "Date.h"

class Nguoi
{

public:
	Nguoi();
	Nguoi(char * soCMND, char * hoVaTen,char * diaChi, Date ngaySinh);
	virtual void Input();
	virtual void Output();
	std::string getSoCMND() ;
	void setSoCMND( char * soCMND);
	std::string getHoTen();
	void setHoTen( char * hoTen);
	std::string getDiaChi();
	void setDiaChi( char * diaChi);
	Date getNgaySinh();
	void setNgaySinh(int day, int month, int year);
	virtual ~Nguoi();
protected:
	char soCMND[15];
	char hoVaTen[20];
	char diaChi[50];
	Date ngaySinh;
};