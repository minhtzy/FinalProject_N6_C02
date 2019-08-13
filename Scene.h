#pragma once

class Scene
{
public:
	Scene();
	virtual void show() = 0;
	bool IsUserContinue(const char * msg = "Tiep tuc: ");
	void InputChoice(int &iChoice, int iMin, int iMax, const char * msg = "Nhap lua chon: ");
	virtual ~Scene();

private:

};