#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include "DataFile.h"
using namespace std;
//using std::ostream;

class DataFile;
class ArrayListFiles
{
	DataFile** arrOfFiles;
	int size;
	//friend class DataFile;

public:
	ArrayListFiles() : arrOfFiles(NULL), size(0) {}
	~ArrayListFiles();
	const int getSize() { return size; };
	class ArrayListFiles& operator = (const ArrayListFiles& arr);
	ArrayListFiles(const ArrayListFiles& other);
	class ArrayListFiles& operator += (const DataFile& d);
	const int bigFile();
	const ArrayListFiles& readAllFile(const char* fileName);
	//void ArrayListFiles::readAllFiles(const char* o);
	tm& timeUpdate(char* buff);


};




