#include "DataFile.h"

DataFile::DataFile(string name, string data):AD_File(name)
{
	this->data = data;
}

bool DataFile::operator==(const DataFile other) const
{
	if (AD_File::FileName == other.FileName)
		if (this->data == other.data)
			return true;
	return false;
}

int DataFile::getSize()
{
	int size = this->data.size();
	return size;
}


