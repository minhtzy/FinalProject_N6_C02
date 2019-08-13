#include "FileLoger.h"
#include <iostream>
#include <fstream>

using namespace std;

void FileLoger::WriteLog(std::string filePath, std::string message)
{

	ofstream oFile;
	oFile.open(filePath, ios::out | ios::app);

	if (oFile.fail())
	{
		cout << "Khong mo duoc file " << filePath << endl;
		return;
	}
	oFile.seekp(0,ios::end);
	oFile << message << endl;

	oFile.close();

}
