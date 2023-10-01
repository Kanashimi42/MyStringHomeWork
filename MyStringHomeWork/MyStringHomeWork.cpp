#include "MyString.h"
#include <iostream>
using namespace std;

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

	MyString sString("Hello world");
	cout << sString[0] << endl;
	for (int i = 0; i < sString.GetLength(); i++)
		cout << sString[i];
	cout << endl;

	MyString tStr;
	tStr("Hello()");
	tStr.Output();
	cout << endl << endl;


	MyString test("test");
	MyString test1 = test + "a";
	test1.Output();
	cout << endl;
	MyString test2("test2");
	MyString test3 = 'a' + test2;
	test3.Output();
	cout << endl;

	MyString test4("a");
	MyString test5 = 10 + test4;
	test5.Output();
	cout << endl;

	MyString text6("text");
	MyString text7 = text6 + 10;
	text7.Output();
	cout << endl;

	cout << "obj++" << endl;
	MyString testA = test4++;
	testA.Output();
	cout << endl;
	test4.Output();
	cout << endl << endl;
	MyString test6("B");
	cout << "++obj" << endl;
	testA = ++test6;
	testA.Output();
	cout << endl;
	test6.Output();
	cout << endl << endl;

	cout << "MoveConstruct: " << endl;
	MyString moveStr;
	moveStr = move(str);
	moveStr.Output();
	cout << endl;



	return 0;
}