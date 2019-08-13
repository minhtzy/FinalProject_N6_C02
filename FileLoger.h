#pragma once

#include <string>

class FileLoger
{
public:
	static void WriteLog(std::string filePath, std::string message);
};