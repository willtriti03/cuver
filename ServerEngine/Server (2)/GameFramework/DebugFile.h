#pragma once

#ifndef _DEBUGFILE_H_
#define _DEBUGFILE_H_

#include <Windows.h>
#include <iostream>
#include <fstream>
#define Debugs DebugFile::GetInstance()
using namespace std;
class DebugFile
{
public:
	static DebugFile* GetInstance();

	DebugFile();
	~DebugFile();
	void Debug();
};
#endif
