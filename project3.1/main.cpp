#pragma once
#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <ctime>
//#include <fstream>
//#include <iomanip>
#include "DataFile.h"
#include "ArrayListFiles.h" 
#include "Folder.h"
using namespace std;

const int MAX = 256;


void main()
{
	
	const char* foldeName = "repos";
	const char* folderPath = "C:\\Users\\ravin\\source\\repos\\project3.1";
	const char* _fileName = "ListDataFiles.txt";
	Folder F(foldeName, folderPath);
	F.ALF.readAllFile(_fileName);
	cout << F;

	char* name = new char;
	char* data = new char;
	cout << "Enter file's name:" << endl;
	cin.ignore();
	cin.getline(name,MAX);
	cout << "Enter file's data: " << endl;
	cin.ignore();
	cin.getline(data, MAX);
	DataFile F1(name, data);
	F.ALF += F1;
	F.ALF += F1; // CHACK IF ADD AGAIN
	cout << F;
	int bigestFile = F.ALF.bigFile();
	cout << F.ALF.arrOfFiles[bigestFile][0];
	char* folderName1 = new char;
	char* folderPath1 = new char;
	
	// new differnt folder
	cout << "Enter folder's name:" << endl;
	cin.ignore();
	cin.getline(folderName1, MAX);
	cout << "Enter folder's path: " << endl;
	cin.ignore();
	cin.getline(folderPath1, MAX);
	Folder F2(folderName1, folderPath1);
	DataFile D1("file1", "hello world");
	DataFile D2("file2", "empty");
	DataFile D3, D4;
	F2.ALF += D1;
	F2.ALF += D2;
	F2.ALF += D3;
	F2.ALF += D4;
	if (F2 == F)
		cout << "the folders are the same" << endl;
	else cout << "the folders are diffrent" << endl;

	//try the same folder
	Folder F3(folderName1, folderPath1);
	F3.ALF += D1;
	F3.ALF += D2;
	F3.ALF += D3;
	F3.ALF += D4;

	if (F3 == F2)
		cout << "the folders are the same" << endl;
	else cout << "the folders are diffrent" << endl;





	
	

	
}
	 


