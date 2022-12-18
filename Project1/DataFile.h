#pragma once
#include "AD_File.h"

class DataFile :public AD_File
{
	string data;

public:
	DataFile(string name, string data);
	bool operator == (const DataFile other) const;
	int getSize();
	
};