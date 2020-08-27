#include <iostream>
using namespace std;

//The getline function reads the input stream character by character until it reaches the end of the stream
//or a newline character('\ n'), and returns a C - style string with the characters read.
//Note that since the size of the input is not known in advance, you will need to re - allocate memory
//while reading if there are more characters in the input stream than you expected.


char* add_size(char* str, unsigned& size)
{
    char* newStr = new char[2 * size];
    for (unsigned i = 0; i < size; ++i)
    {
        newStr[i] = str[i];
    }
    size *= 2;
    delete[] str;
    return newStr;
}

char* getline()
{
    unsigned size = 10;
    char* line = new char[size];
    line[0] = '\0';
    char symbol;
    int i = 0;
    while (cin.get(symbol) && symbol != '\n' && !cin.eof())
    {
        if (i == size - 1)
        {
            line = add_size(line, size);
        }
        line[i] = symbol;
        ++i;
    }
    line[i] = '\0';
    return line;
}