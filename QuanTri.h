#pragma once
#include "Nguoi.h"
using namespace std;
class DSQuanTri;
class QuanTri : public Nguoi {
	public:
		QuanTri();
		void Input() override;
		void Output() override;
		string getUsername();
		void setUsername(string uname);
		string getPassword();
		void setPassword(string pword);
		~QuanTri();
		bool checklogin(string name, string pass);
		int docfile(ifstream &)
		friend DSQuanTri;
		
	protected:
		string username;
		string password;
};
class DSQuanTri{
	private:
		int num;
		QuanTri ds[100];
	public:
		void doc();
};


