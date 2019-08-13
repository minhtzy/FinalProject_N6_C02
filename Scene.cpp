#include "Scene.h"
#include <iostream>

using namespace std;
Scene::Scene()
{
}

bool Scene::IsUserContinue(const char * msg)
{

	char cChooice;
	cout << msg <<"(Y/N) ";
	cin.ignore();
	cin.clear();
	cChooice = cin.get();
	return (cChooice == 'Y' || cChooice == 'y');
}

void Scene::InputChoice(int & iChoice, int iMin, int iMax, const char * msg)
{

	do
	{
		cout << msg << endl;
		cin >> iChoice;
	} while (iChoice < iMin || iChoice > iMax);

}

Scene::~Scene()
{
}
