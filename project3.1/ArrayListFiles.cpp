#pragma once
#include "DataFile.h"
#include "ArrayListFiles.h" 

const int MAX = 256;

ArrayListFiles::~ArrayListFiles()
{
	/*for (int i = 0; i < size; i++)
	{
		delete arrOfFiles[i];
	}*/
	delete[] arrOfFiles;
}

class ArrayListFiles& ArrayListFiles::operator=(const ArrayListFiles& arr)
{
	if (this != &arr)
	{
		this->size = arr.size;
		arrOfFiles = new DataFile * [size];
		for (int i = 0; i < size; i++)
		{
			arrOfFiles[i] = arr.arrOfFiles[i];
		}
	}
	return *this;
}

ArrayListFiles::ArrayListFiles(const ArrayListFiles& other)
{
	arrOfFiles = NULL;
	*this = other;
}

class ArrayListFiles& ArrayListFiles::operator+=(const DataFile& d)
{
	for (int i = 0; i < this->size; i++)
	{
		if (arrOfFiles[i][0] == d)
		{
			cout << "This file is already exist" << endl;
			return *this;
		}
	}
	ArrayListFiles temp = *this;
	delete[] this->arrOfFiles;
	size++;
	arrOfFiles = new DataFile * [size];
	for (int i = 0; i < size - 1; i++)
	{
		arrOfFiles[i] = new DataFile;
		arrOfFiles[i] = temp.arrOfFiles[i];
	}
	arrOfFiles[size - 1] = new DataFile;
	arrOfFiles[size - 1][0] = d;
	return *this;
}

const int ArrayListFiles::bigFile()
{
	int biggest = 0;
	for (int i = 1; i < size; i++)
	{
		if (arrOfFiles[biggest] > arrOfFiles[i])
			biggest = i;
	}
	return biggest;
}

const ArrayListFiles& ArrayListFiles::readAllFile(const char* fileName)
{
	char buff[MAX], temp[MAX];
	ifstream in(fileName);
	int i = 0, p = 0, _time = 0, space = 0;
	while (!in.eof())
	{
		in.getline(buff, MAX);//puts the line into buff
		DataFile d;
		while (space < 2)
		{
			if (*(buff + _time) == 32)
				space++;
			_time++;
		}
		while (*(buff + p + _time) != 32)
		{
			temp[p] = buff[_time + p];
			p++;
		}
		p++;
		d.setName(temp);
		d.setData(buff + _time + p);
		*this += d;
		arrOfFiles[i][0].lastUpdate = timeUpdate(buff);
		_time = 0; space = 0; p = 0; i++;
	}
	in.close();
	return *this;
}

tm& ArrayListFiles::timeUpdate(char* buff)
{
	tm tm;
	char* date = strtok(buff, " ");
	char* time = strtok(NULL, "\n");
	tm.tm_mday = atoi(strtok(date, "/"));
	tm.tm_mon = atoi(strtok(NULL, "/"));
	tm.tm_year = atoi(strtok(NULL, "/"));
	tm.tm_hour = atoi(strtok(time, ":"));
	tm.tm_min = atoi(strtok(NULL, ":"));
	tm.tm_sec = atoi(strtok(NULL, ":"));
	return tm;
}




