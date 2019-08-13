#include "Sence.h"
#include <iostream>

using namespace std;
Sence::Sence()
{
}

bool Sence::IsUserContinue(const char * msg)
{

	char cChooice;
	cout << msg <<"(Y/N) ";
	cin.ignore();
	cin.clear();
	cChooice = cin.get();
	return (cChooice == 'Y' || cChooice == 'y');
}

void Sence::InputChoice(int & iChoice, int iMin, int iMax, const char * msg)
{

	do
	{
		cout << msg << endl;
		cin >> iChoice;
	} while (iChoice < iMin || iChoice > iMax);

}

Sence::~Sence()
{
}
