#include "QuanTri.h"
#include<iostream>

using namespace std;

QuanTri::QuanTri()
{
	username[0] = '\0';
	password[0] = '\0';
}

void QuanTri::Input()
{
	cout << "Nhap vao ten nguoi dung: ";
	cin >> username;
	cout << "Nhap vao mat khau: ";
	cin >> password;
	Nguoi::Input();
}

void QuanTri::Output()
{
	Nguoi::Output();
}

std::string QuanTri::getUsername()
{
	return username;
}

void QuanTri::setUsername(std::string uname)
{
	strcpy(username, uname.c_str());
}

string QuanTri::getPassword()
{
	return password;
}
void QuanTri::setPassword(string pword)
{
	strcpy(password, pword.c_str());
}
QuanTri::~QuanTri()
{
}
