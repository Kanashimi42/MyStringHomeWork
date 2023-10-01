#include <iostream>
using namespace std;



class MyString
{
public:
	MyString();
	MyString(int size);
	MyString(const char* userInput);
	~MyString();
	MyString(const MyString& other);
	MyString& operator = (const MyString& other);
	void Input();
	void Output();
	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* str);
	int MyChr(char c);
	int MyStrLen();
	MyString operator+(const MyString& other);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);
	void SetStr(const char* st);
	void SetLength(int size);
	char* GetStr() const;
	int GetLength() const;
	char& operator[](const unsigned int index);
	void operator()(const char* input);
	static int objectCount;
private:

	int size;
	int lenght;
	int strLength(const char* str)
	{
		int counter = 0;

		while (str[counter] != '\0')
		{
			counter++;
		}

		return counter;
	}
	char* str;
};
ostream& operator<<(ostream& os, const MyString& obj);
istream& operator>>(istream& is, MyString& obj);
MyString operator+(const MyString obj1, const char obj2);
MyString operator+(const char obj2, const MyString obj1);
MyString operator+(const MyString obj1, const int quantity);
MyString operator+(const int quantity, const MyString obj1);
MyString operator++(MyString& obj, int);
MyString& operator++(MyString& obj);
