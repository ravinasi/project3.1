#pragma once
#include <iomanip>
#include <string>
#include "AD_File.h"
#include "DataFile.h"

class Folder :public AD_File
{
	DataFile** arrDataFile;
	int sizeADF;
	Folder** arrFolder;
	int sizeAF;
	string folderPath;
	

	Folder* findFolderPointer(string path, int currentPlace, string currentFolder, int pathSize)throw(const char*);

public:
	static Folder mainFolder;
	Folder(string folderName, string foldderPath);
	string getFullPath();
	void addFileToArray(const DataFile& d)throw(char*);
	void addFileToArray(const Folder& F);
	void mkfile(string fileName, string data);
	Folder(const Folder& other)throw(const string);
	Folder(const Folder& other, const string path);
	void mkDir(string _filename);
	void dir();
	string intoFolder(string _foldername);
	static Folder* cd(string path)throw(const string);
	
};

