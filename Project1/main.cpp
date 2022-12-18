#pragma once
#include <iostream>
#include <cstring>
#include "DataFile.h"
#include "Folder.h"
using namespace std;

void main()
{
	//check for memory leaks
	/*Folder F("folder1", "c:");
	string path(F.folderPath);
	string add = "\\";
	path += add;
	path += this->FileName;*/


	//Folder* root = new Folder(Folder::mainFolder,"c:");
	Folder* root = &Folder::mainFolder;
	Folder* curr = root;
	bool quit = false; string path;
	string command, p_command;
	char echoStream[256];

	do {
		string path = curr->getFullPath();
		std::cout << curr->getFullPath()<< ">";
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> command;
		if (command == "cd") {
			try {
				cin.ignore(1);
				cin >> p_command;
				if (p_command == root->getNmae())
					curr = root;
				else curr = Folder::cd(p_command);
			}
			catch (const char* msg) {
				cout << msg << endl;
				quit = true;
			};
			continue;
		}
		if (command == "mkdir") {
			try {
				cin.ignore(1);
				cin >> p_command;
				curr->mkDir(p_command);
			}
			catch (const char* msg) {
				cout << msg << endl;
				quit = true;
			}
			continue;
		}
		if (command == "dir") {
			curr->dir();
			continue;
		}
		if (command == "echo") {
			cin.ignore(1);
			std::cin.getline(echoStream, 256);
			command = echoStream;
			try {
				curr->mkfile(command.substr(0, command.find('<') -
					1), command.substr(command.find('<') + 1));
			}
			catch (const char* msg) {
				cout << msg << endl;
				quit = true;
			};
			continue;
		}
		if (command == "infolder")
		{
			cin.ignore(1);
			cin >> p_command;
			curr->intoFolder(p_command);
		
		}
	} while (!quit);
	cout << "The end!" << endl;


	/*string _path = "c:\\myfiles\folder2";
	int place = _path.find_first_of(92);
	string sub = _path.substr(0, place);
	_path = _path.substr(place + 1);
	*/

	/*Folder Fmain("Fmain", "c");
	Folder F1("folder1", "Fmain");
	Folder F2("folder2", "Fmain");
	DataFile D("file1.txt","hello world");
	DataFile D2("file2.txt", "jsdcbcjjjjjjjknnbvjm,vjasgdbvkasdv");
	const string path = "Fmain";
	try {
		Fmain.addFileToArray(F1);
		Fmain.addFileToArray(F2);
		Fmain.addFileToArray(D);
		Fmain.addFileToArray(D2);
	}
	catch (const char* s)
	{
		cout << s;
	}
	catch (...)
	{
		cout << "unexprcted error";
	}
	Fmain.dir();*/
	/*DataFile** temp = new DataFile * [1];
	temp[0] = new DataFile(d1);

	delete temp[0];
	delete[] temp;

	Folder F1("folder1", "c\\ravin");
	try {
		F1.addFileToArray(d1);
		F1.addFileToArray(d1);
	}

	catch (char* s)
	{
		cout << s;
	}
	catch (...)
	{
		cout << "unexpected error";
	}*/
}

