#pragma once
#include "Sence.h"
#include "NguoiDung.h"
class NguoiDungSence : public Sence
{
public:
	NguoiDungSence();
	NguoiDungSence(NguoiDung * user);
	~NguoiDungSence();

protected:
	NguoiDung* user;
};