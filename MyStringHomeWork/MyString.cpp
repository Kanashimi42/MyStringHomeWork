#include "MyString.h"
static int objectCount;

MyString::MyString()
{
	str = new char[81];
	objectCount++;
}
MyString::MyString(int size)
{
	str = new char[size + 1];
	objectCount++;
}
MyString::MyString(const char* userInput)
{
	int length = strLength(userInput);
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = userInput[i];
	}
	str[length] = '\0';
	objectCount++;
}
MyString::~MyString()
{
	delete[] this->str;
	objectCount--;
}

MyString::MyString(const MyString& other)
{
	int length = strLength(other.str);
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = other.str[i];
	}
	str[length] = '\0';
	objectCount++;

}

MyString& MyString::operator = (const MyString& other)
{
	if (this != &other)
	{
		delete[] str;
		int length = strLength(other.str);
		str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			str[i] = other.str[i];
		}
		str[length] = '\0';
	}
	return *this;
}
void MyString::Input()
{
	cin.getline(str, 80);
}
void MyString::Output()
{
	cout << str << endl;
}
void MyString::MyStrcpy(MyString& obj)
{
	int length = strLength(obj.str);
	delete[] str;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = obj.str[i];
	}
	str[length] = '\0';
}
bool MyString::MyStrStr(const char* str)
{
	int i = 0, j = 0;

	while (this->str[i] != '\0') {
		if (this->str[i] == str[j]) {
			while (this->str[i] == str[j]) {
				i++;
				j++;
			}

			if (str[j] == '\0')
				return true;
		}
		else
			i++;
	}

	return false;
}

int MyString::MyChr(char c)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
		{
			return i;
		}
	}
	return -1;
}
int MyString::MyStrLen()
{
	return strLength(str);
}

MyString MyString::operator+(const MyString& other)
{
	MyString newStr;

	int thisLength = strLength(this->str);
	int otherLength = strLength(other.str);

	newStr.str = new char[thisLength + otherLength + 1];
	int i = 0;
	for (; i < thisLength; i++)
	{
		newStr.str[i] = this->str[i];

	}
	for (int j = 0; j < otherLength; j++, i++)
	{
		newStr.str[i] = other.str[j];
	}

	newStr.str[thisLength + otherLength] = '\0';

	return newStr;
}
void MyString::MyDelChr(char c)
{
	int thisLength = strLength(str);
	int count = 0;
	for (int i = 0; i < thisLength; i++)
	{
		if (str[i] != c)
		{
			str[count++] = str[i];
		}
	}
	str[count] = '\0';
}
int MyString::MyStrCmp(MyString& b)
{
	int length1 = strLength(str);
	int length2 = strLength(b.str);

	if (length1 < length2)
	{
		return -1;
	}
	else if (length1 > length2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void MyString::SetStr(const char* st)
{
	str = new char[strLength(st) + 1];
	strcpy_s(str, strLength(st) + 1, st);
}
void MyString::SetLength(int size)
{
	if (size < 0) {
		cout << "Число должно быть больше 0" << endl;
		return;
	}

	lenght = size;
}
char* MyString::GetStr() const
{
	return str;
}
int MyString::GetLength() const {
	return lenght;
}
char& MyString::operator[](const unsigned int index)
{
	if (index >= 0 && index < lenght - 1)
		return str[index];
	return str[0];
}
void MyString::operator()(const char* input) {
	lenght = strLength(input) + 1;
	str = new char[lenght];
	strcpy_s(str, strLength(input) + 1, input);
}
ostream& operator<<(ostream& os, const MyString& obj)
{
	os << obj.GetStr() << endl;

	return os;
}
istream& operator>>(istream& is, MyString& obj) {
	cout << "istream& operator>>(istream& is, MyString& obj)" << endl;

	char buff[100];

	cin.getline(buff, strlen(buff) + 1);

	obj.SetStr(buff);

	return is;
}
MyString operator+(const MyString obj1, const char obj2) {
	int newLenght = strlen(obj1.GetStr()) + 2;
	char* newStr = new char[newLenght];

	strcpy_s(newStr, newLenght - 1, obj1.GetStr());

	newStr[newLenght - 2] = obj2;
	newStr[newLenght - 1] = '\0';

	return MyString(newStr);
}
MyString operator+(const char obj2, const MyString obj1) {
	int newLenght = strlen(obj1.GetStr()) + 2;
	char* newStr = new char[newLenght];

	strcpy_s(newStr, newLenght - 1, obj1.GetStr());

	newStr[newLenght - 2] = obj2;
	newStr[newLenght - 1] = '\0';

	return MyString(newStr);
}


MyString operator+(const MyString obj1, const int quantity) {
	int newLenght = strlen(obj1.GetStr()) + quantity + 1;
	char* newStr = new char[newLenght];

	strcpy_s(newStr, strlen(obj1.GetStr()) + 1, obj1.GetStr());

	for (int i = strlen(obj1.GetStr()); i < newLenght - 1; i++)
		newStr[i] = 'a';

	newStr[newLenght - 1] = '\0';

	return MyString(newStr);
}
MyString operator+(const int quantity, const MyString obj1) {
	int newLenght = strlen(obj1.GetStr()) + quantity + 1;
	char* newStr = new char[newLenght];

	strcpy_s(newStr, strlen(obj1.GetStr()) + 1, obj1.GetStr());

	for (int i = strlen(obj1.GetStr()); i < newLenght - 1; i++)
		newStr[i] = 'a';

	newStr[newLenght - 1] = '\0';

	return MyString(newStr);
}
MyString operator++(MyString& obj, int) {
	MyString temp(obj);

	int newLenght = strlen(obj.GetStr()) + 2;
	char* newStr = new char[newLenght];

	strcpy_s(newStr, newLenght - 1, obj.GetStr());

	newStr[newLenght - 2] = 'b';
	newStr[newLenght - 1] = '\0';

	obj.SetStr(newStr);
	obj.SetLength(newLenght);

	return temp;
}
MyString& operator++(MyString& obj) {
	int newLenght = strlen(obj.GetStr()) + 2;
	char* newStr = new char[newLenght];

	for (int i = 1; i < newLenght - 1; i++)
		newStr[i] = obj.GetStr()[i - 1];

	newStr[0] = 'b';
	newStr[newLenght - 1] = '\0';

	obj.SetStr(newStr);
	obj.SetLength(newLenght);

	return obj;
}
int MyString::objectCount = 0;