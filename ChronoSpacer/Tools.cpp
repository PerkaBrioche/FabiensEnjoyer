#pragma once
#include <iostream>
#include <windows.h>

std::string GetDirectories(std::string dname)
{
	std::string appPath = GetAppPath();
	appPath = appPath + dname + "\"";
	return appPath;
}

std::string GetAppPath()
{
	char cExeFilePath[256];
	GetModuleFileNameA(NULL, cExeFilePath, 256);
	std::string exeFilePath = cExeFilePath;
	int exeNamePos = exeFilePath.find_last_of("\\/");
	std::string appPath = exeFilePath.substr(0, exeNamePos + 1);
	return appPath;
}

