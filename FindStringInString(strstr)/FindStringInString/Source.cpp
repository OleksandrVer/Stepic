#include<iostream>
using namespace std;

//This function find the first occurrence of the pattern in the text.
//As the first parameter, the function takes a text(C - style string) in which to search for a template.
//As the second parameter, the template string(C - style string) to find.
//The function returns the position of the first occurrence of the template string if it is present in the string
//(remember that in C ++ we count from 0), and -1 if there is no template in the text.
//Note that an empty pattern(string of length 0) can be found anywhere in the text.

int strStr(const char* text, const char* pattern)
{
    if (*pattern == '\0') { return 0; }
    int mark = 0, counterText = 0, counterPattern = 0;
    bool patternIsHere = false;
    while (*text != '\0')
    {
        if (*text == *pattern)
        {
            counterText = 0;
            counterPattern = 0;
            while (pattern[counterPattern] != '\0')
            {
                patternIsHere = true;
                if (pattern[counterPattern] != text[counterText])
                {
                    patternIsHere = false;
                    break;
                }
                ++counterPattern;
                ++counterText;
            }
            if (patternIsHere) { return mark; }
        }
        ++mark;
        ++text;
    }
    if (!patternIsHere) { return -1; }
}

int main()
{
    const char* str1 = "Grasshopper";
    const char* str2 = "hop";
    cout << strStr(str1, str2);
    return 0;
}