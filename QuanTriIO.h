#pragma once
#include "QuanTri.h"

class QuanTriIO
{
public:
	QuanTriIO();
	QuanTri * getQuanTri(std::string username);
	bool checkLogin(std::string username, std::string password);
	bool addQuanTri(QuanTri * quantri);
	~QuanTriIO();

private:

};
