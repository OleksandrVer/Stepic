#include<iostream>
using namespace std;

//strLen calculates the length of a C-style line.
//strCat takes two C-style lines as input and appends the second to the end of the first
//so that the first line is one C-style line equal to the concatenation of the two original ones.
int strLen(const char* str)
{
	int count = 0;
	//while (str[count] != '\0')
	while (*str++)
	{
		count++;
	}
	return count;
}
void strCat(char* to, const char* from)
{
	/*int countTo = 0, countFrom = 0;
	while (to[countTo] != '\0') { ++countTo; }
	while (from[countFrom] != '\0')
	{
		to[countTo] = from[countFrom];
		++countTo;
		++countFrom;
	}*/
	while (*to) { ++to; }
	while (*to++ = *from++);
	//to[countTo] = from[countFrom];
}

void main()
{
	char str1[20] = "Hello";
	char str2[20] = " World";
	cout<<strLen(str1)<<endl;
	strCat(str1, str2);
	cout << strLen(str1) << endl;
	cout << str1<<endl;	
}