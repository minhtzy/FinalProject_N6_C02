#pragma once
#include "Sence.h"
#include "NguoiDung.h"
class NguoiDungSence : public Sence
{
public:
	NguoiDungSence();
	virtual void show() = 0;
	NguoiDungSence(NguoiDung * user);
	~NguoiDungSence();

protected:
	NguoiDung* user;
};