#pragma once
#include "Nguoi.h"

class QuanTri : public Nguoi {
	public:
		QuanTri();
		void Input() override;
		void Output() override;
		std::string getUsername();
		void setUsername(std::string uname);
		std::string getPassword();
		void setPassword(std::string pword);
		~QuanTri();
		bool checklogin(std::string name, std::string pass);
		int docfile(std::ifstream &);
	protected:
		char username[20];
		char password[20];
};


