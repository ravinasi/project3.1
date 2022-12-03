#include "DataFile.h"

//using std::ostream;

const int MAX = 200;
int DataFile::counter = 0;

DataFile::DataFile()
{
	counter++;
	this->data = NULL;
	this->fileName = new char[MAX];
	char name[20] = "new_file";
	name[8] = (char)counter;
	strcpy(fileName, name);
	setUpdate();
}

DataFile::DataFile(char* _fileName, char* _data)
{
	counter++;
	this->setData(_data);
	this->setName(_fileName);
	this->setUpdate();
}

DataFile::DataFile(const DataFile& d)
{
	counter++;
	fileName = NULL;
	data = NULL;
	//*this = d;
	this->data = new char[strlen(d.data) + 1];
	this->fileName = new char[strlen(d.fileName) + 1];
	strcpy(this->data, d.data);
	strcpy(this->fileName, d.fileName);
	this->lastUpdate = d.lastUpdate;
}

char* DataFile::getUpdate() const
{
	char buf[80];
	strftime(buf, sizeof(buf), "%d/%m/%Y %X", &lastUpdate);
	char* stringTime = new char[strlen(buf) + 1];
	strcpy(stringTime, buf);
	return stringTime;
}

void DataFile::setName(char* newName)
{
	char* temp = new char;
	temp = newName;
	char prob = 92;
	char prob1 = 34;
	while (!findChar(temp))
	{
		cout << "A file name can't contain the following characters: /:*?<>|" << prob << prob1 << endl;
		cout << "Please enter a new name:" << endl;
		cin.getline(temp, MAX);
	}
	delete[] fileName;
	this->fileName = new char[strlen(temp) + 1];
	strcpy(this->fileName, temp);
}

void DataFile::setData(char* newData)
{
	data = NULL;
	data = new char[strlen(newData) + 1];
	strcpy(data, newData);
}

void DataFile::setUpdate()
{
	time_t t1 = time(0);
	struct tm* now = localtime(&t1);
	lastUpdate = *now;
}

void DataFile::setUpdate(tm time)
{
	lastUpdate = time;
}

float DataFile::getSize()
{
	return strlen(data);
}

void DataFile::dir()
{
	float size = getSize() / 1024;
	cout << getUpdate() << " ";
	cout << fixed << setprecision(2) << size << "  KB  ";
	cout << this->fileName << endl;
}

const DataFile& DataFile::operator=(const DataFile& o)
{
	if (this != &o)
	{
		delete[] data;
		delete[] fileName;
		data = new char[strlen(o.getName()) + 1];
		fileName = new char[strlen(o.getData()) + 1];
		strcpy(this->data, o.getData());
		strcpy(this->fileName, o.getName());
		this->lastUpdate = o.lastUpdate;
	}
	return *this;
}

const bool DataFile::operator==(const DataFile& file1)
{
	int res = 0;
	if (!strcmp(file1.fileName, this->fileName))
		res++;
	if (!strcmp(file1.data, this->fileName))
		res++;
	if (res == 2)
		return true;
	return false;
}

const bool DataFile::operator<(const DataFile& file1)
{
	if (strlen(this->data) < strlen(file1.data))
		return true;
	return false;
}

const bool DataFile::operator>(const DataFile& file1)
{
	if (strlen(this->data) > strlen(file1.data))
		return true;
	return false;
}

DataFile::~DataFile()
{
	counter--;
	delete[] this->data;
	delete[] this->fileName;
	//delete this->lastUpdate;
}

bool DataFile::findChar(char* name)
{
	int i = 0;
	while (name[i] != NULL)
	{
		if (name[i] == '<' || name[i] == '?' || name[i] == '>' || name[i] == '*'
			|| name[i] == ':' || name[i] == '|' || name[i] == '/' || name[i] == 92)
			return false;
		i++;
	}
	return true;
}

ostream& operator<<(ostream& out, const DataFile& f)
{
	float size = (float)strlen(f.data) / 1024;
	cout << f.getUpdate() << " ";
	cout << fixed << setprecision(2) << size << "  KB  ";
	cout << f.fileName << endl;
	return out;
}
