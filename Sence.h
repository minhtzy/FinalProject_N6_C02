#pragma once

class Sence
{
public:
	Sence();
	virtual void show() = 0;
	bool IsUserContinue(const char * msg = "Tiep tuc: ");
	void InputChoice(int &iChoice, int iMin, int iMax, const char * msg = "Nhap lua chon: ");
	virtual ~Sence();

private:

};