#include <iostream>
using namespace std;



class MyString
{
public:
	static int objectCount;

	MyString()
	{
		str = new char[81];
		objectCount++;
	}
	MyString(int size)
	{
		str = new char[size + 1];
		objectCount++;
	}
	MyString(const char* userInput)
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
	~MyString()
	{
		delete[] this->str;
		objectCount--;
	}

	MyString(const MyString& other)
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

	MyString& operator = (const MyString& other)
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
	void Input()
	{
		cin.getline(str, 80);
	}
	void Output()
	{
		cout << str << endl;
	}
	void MyStrcpy(MyString& obj)
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
	bool MyStrStr(const char* str)
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

	int MyChr(char c)
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
	int MyStrLen()
	{
		return strLength(str);
	}

	MyString operator+(const MyString& other)
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
	void MyDelChr(char c)
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
	int MyStrCmp(MyString& b)
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

private:
	int size;
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
int MyString::objectCount = 0;
int main()
{
	MyString str("Hello");
	MyString str2("World");

	cout << "Comparison result: " << str2.MyStrCmp(str) << endl;
	MyString result = str + str2;

	result.Output();
	cout << "Length of result: " << result.MyStrLen() << endl;


	MyString str3("Hello, World!");
	str3.Output();
	if (str3.MyStrStr("ello"))
		cout << "sub found!" << endl << endl;
	else
		cout << "sub not found!" << endl << endl;


	result.Output();
	result.MyDelChr('o');
	result.Output();
	cout << "Comparison result: " << result.MyStrCmp(str) << endl;

	cout << "Number of MyString objects created: " << MyString::objectCount << endl;


	return 0;
}