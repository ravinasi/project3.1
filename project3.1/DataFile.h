#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
//using std::ostream;

class DataFile {
	char* fileName;
	tm lastUpdate;
	char* data;
	static int counter;

	bool findChar(char* name);
	float getSize();

public:
	DataFile();
	DataFile(const char* _fileName, const char* _data);
	DataFile(const DataFile& d);
	char* getName() const { return fileName; };
	char* getData() const { return data; };
	char* getUpdate() const;
	void setName(const char* newName);
	void setData(const char* newData);
	void setUpdate();
	void setUpdate(tm time);
	void dir();
	const DataFile& operator=(const DataFile& o);
	//static void changeCounter(int num) { counter += num; };
	const bool operator == (const DataFile& file1);
	const bool operator < (const DataFile& file1);
	const bool operator > (const DataFile& file1);
	//const void operator << (ostream& printc );
	friend ostream& operator<<(ostream& out, const DataFile& f);
	friend class ArrayListFiles;
	friend class Folder;
	//friend class ostream;
	~DataFile();

};

