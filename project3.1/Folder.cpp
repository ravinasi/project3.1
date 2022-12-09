#pragma once
#include "DataFile.h"
#include "ArrayListFiles.h" 
#include "Folder.h"

Folder::Folder(const char* _folderName, const char* _path)
{
	folderpath = new char[strlen(_path) + 1];
	strcpy(folderpath, _path);
	folderName = new char[strlen(_folderName) + 1];
	strcpy(folderName, _folderName);
	ALF = ArrayListFiles();
}

Folder::Folder(Folder& F)
{
	folderName = NULL;
	folderpath = NULL;
	*this = F;
}

Folder& Folder::operator=(const Folder& F)
{
	
	folderpath = new char[strlen(F.folderpath) + 1];
	strcpy(folderpath, F.folderpath);
	folderName = new char[strlen(F.folderName) + 1];
	strcpy(folderName, F.folderName);
	ALF = F.ALF;
	return *this;
}

Folder::~Folder()
{
	delete[] folderName;
	delete[] folderpath;
}

const bool Folder::operator==(const Folder& other)
{
	int res = 1;
	if (strcmp(folderName, other.folderName) != 0)
		res = 0;
	if (strcmp(folderpath, other.folderpath) != 0)
		res = 0;
	if (ALF.getSize() != other.ALF.getSize())
		res = 0;
	if (!res)
		return false;
	for (int i = 0; i < ALF.getSize(); i++)
	{
		if (ALF.arrOfFiles[i][0] == other.ALF.arrOfFiles[i][0])
			res = 1;
		else return false;
	}
	return true;
}

ostream& operator<<(ostream& out, const Folder& F)
{
	cout << F.folderpath << "\\";
	cout << F.folderName << endl;
	for (int i = 0; i < F.ALF.getSize(); i++)
	{
		//cout << F.ALF.arrOfFiles[i];
	}
	
	return out;
}
