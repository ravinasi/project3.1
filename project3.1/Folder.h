#pragma once
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
#include "DataFile.h"
#include "ArrayListFiles.h"
using namespace std;

class Folder {

	char* folderName;
	char* folderpath;

public:

	ArrayListFiles ALF;
	Folder(const char* _folderName,const char* _path );
	Folder(Folder& F);
	/*const char* getName() { return folderName; };
	const char* getPath() { return folderpath; };*/
	class Folder& operator =(const Folder& F);
	~Folder();
	friend ostream& operator<<(ostream& out, const Folder& F);
	const bool operator ==(const Folder& other);
};