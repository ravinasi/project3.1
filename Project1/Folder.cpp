#include "Folder.h"

Folder Folder::mainFolder("root", "c:");

Folder::Folder(string folderName, string foldderPath) : AD_File::AD_File(folderName)
{
	this->folderPath = foldderPath;
	sizeADF = 0;
	sizeAF = 0;
}

string Folder::getFullPath()
{
	return folderPath;
}

void Folder::addFileToArray(const DataFile& d) throw(const char*)
{
	for (int i = 0; i < this->sizeADF; i++)
		if (this->arrDataFile[i][0] == d)
		{
			throw "File allready exists";
		}
			
	DataFile** temp = new DataFile * [sizeADF];
	for (int i = 0; i < sizeADF; i++)// copy to temp array
		temp[i] = new DataFile(arrDataFile[i][0]);
	
	delete[] arrDataFile;
	sizeADF++;
	arrDataFile = new DataFile * [sizeADF];//alllocate new array
	for (int i = 0; i < sizeADF - 1; i++)
	{
		arrDataFile[i] = new DataFile(temp[i][0]);
		delete temp[i];
	}
	arrDataFile[sizeADF - 1] = new DataFile(d);
	delete[] temp;
}

void Folder::addFileToArray(const Folder& F)throw(const char*)
{
	for (int i = 0; i < sizeAF; i++)
	{
		if (arrFolder[i]->FileName == F.FileName)
			throw "Folder allready exist";
	}
	Folder** temp = new Folder * [sizeAF];
	for (int i = 0; i < sizeAF; i++)// copy to temp array
		temp[i] = new Folder(arrFolder[i][0],arrFolder[i][0].folderPath);

	delete[] arrFolder;
	sizeAF++;
	arrFolder = new Folder * [sizeAF];//alllocate new array
	for (int i = 0; i < sizeAF - 1; i++)
	{
		arrFolder[i] = new Folder(temp[i][0],temp[i][0].folderPath);
		delete temp[i];
	}
	arrFolder[sizeAF - 1] = new Folder(F,FileName);
	delete[] temp;
}

void Folder::mkfile(string fileName, string data)
{
	DataFile d(fileName, data);
	this->addFileToArray(d);
}

Folder::Folder(const Folder& other, const string path):AD_File::AD_File(other.FileName)
{
	folderPath = path;
	for (int i = 0; i < sizeADF; i++)// delete old array of data file
		delete arrDataFile[i];
	delete[] arrDataFile;
	for (int i = 0; i < sizeAF; i++)// delete old array of Folders
		delete arrFolder[i];
	delete[] arrFolder;

	for (int i = 0; i < other.sizeADF; i++)
		addFileToArray(arrDataFile[i][0]);
	for (int i = 0; i < sizeAF; i++)
		addFileToArray(arrFolder[i][0]);

}

void Folder::mkDir(string _filename)
{
	Folder newfolder(_filename,this->folderPath);
	this->addFileToArray(newfolder);
}

void Folder::dir()
{
	cout << "________________________________" << endl;
	cout << "Files in folder " << this->FileName << ":" << endl;
	for (int i = 0; i < sizeAF; i++)
	{
		cout << arrFolder[i]->getTime() << "   <DIR>\t     " << arrFolder[i]->FileName << endl;
	}
	for (int i = 0; i < sizeADF; i++)
	{
		float size = (float)arrDataFile[i][0].getSize() / 1024;
		cout << arrDataFile[i]->getTime() << "\t\t";
		cout << fixed << setprecision(2) << size << " KB " << arrDataFile[i][0].getNmae() << endl;
	}
}

Folder* Folder::cd(string path) throw(const string)
{
	int folderPlace = 0;
	int cureentPlace = path.find_first_of(92);
	string currentFolder = path.substr(0, cureentPlace); // copy the current folder
	path = path.substr(cureentPlace + 1); // enter the next path (without current)
	Folder* pfolder = Folder::mainFolder.findFolderPointer(path, cureentPlace, currentFolder, path.size());
	return nullptr;
}

string Folder::intoFolder(string _foldername)
{
	string newpath(this->folderPath);
	newpath += "\\";
	newpath += FileName;
	return newpath;
}

Folder* Folder::findFolderPointer(string path, int currentPlace, string currentFolder, int pathSize) throw(const char*)
{
	if (pathSize == 0)
		return this;
	for (int i = 0; i < this->sizeAF; i++)
	{
		if (arrFolder[i][0] == currentFolder)
		{
			currentPlace = path.find_first_of(92);
			currentFolder = path.substr(0, currentPlace);
			path = path.substr(currentPlace + 1);
			findFolderPointer(path, currentPlace, currentFolder, path.size());
		}
		else throw "There is not such path";
	}
	return nullptr;
}

Folder::Folder(const Folder& other)throw(const char*) :AD_File::AD_File(other.FileName)
{
	throw "no copy constructor";
}


