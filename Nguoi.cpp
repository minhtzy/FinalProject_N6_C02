#include "Nguoi.h"

#include<iostream>

#include "TimeUtils.h"

using namespace std;

Nguoi::Nguoi()
{
}

Nguoi::Nguoi(char * soCMND, char * hoVaTen, char * diaChi, Date ngaySinh)
	: ngaySinh(ngaySinh)
{
	strcpy(this->soCMND, soCMND);
	strcpy(this->hoVaTen, hoVaTen);
	strcpy(this->diaChi, diaChi);
}

void Nguoi::Input()
{
	int year, month, day;
	cout << "Nhap so chung minh nhan dan: ";
	cin >> soCMND;
	cout << "Nhap ho va ten: ";
	cin.ignore();
	cin.getline(hoVaTen,20);
	cout << "Nhap ngay thang nam sinh: ";
	cin >> day >> month >> year;
	setNgaySinh(day, month, year);
	cout << "Nhap dia chi: " << endl;
	cin.ignore();
	cin.getline(diaChi,50);
}

void Nguoi::Output()
{
	cout << "So CMND: " << soCMND << endl;
	cout << "Ho va ten: " << hoVaTen << endl;
	cout << "Ngay sinh: " << ngaySinh.getDay()<< "/" << ngaySinh.getMonth() << "/" << ngaySinh.getYear() << endl;
	cout << "Dia chi: " << diaChi <<endl;
}

std::string Nguoi::getSoCMND()
{
	return soCMND;
}

void Nguoi::setSoCMND(char * soCMND)
{
	strcpy(this->soCMND, soCMND);
}

std::string Nguoi::getHoTen()
{
	return hoVaTen;
}

void Nguoi::setHoTen(char * hoTen)
{
	strcpy(this->hoVaTen, hoTen);
}

std::string Nguoi::getDiaChi()
{
	return diaChi;
}

void Nguoi::setDiaChi(char * diaChi)
{
	strcpy(this->diaChi, diaChi);
}

Date Nguoi::getNgaySinh()
{
	return ngaySinh;
}

void Nguoi::setNgaySinh(int day, int month, int year)
{
	this->ngaySinh = Date(day, month, year);
}

Nguoi::~Nguoi()
{
	//delete this;
}
