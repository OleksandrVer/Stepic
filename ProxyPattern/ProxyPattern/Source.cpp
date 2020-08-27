#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

//In this task, you need to implement the[] operator for the String class you already know.
//However, this time the operator must implement non - standard behavior:
//the operator must be implemented in such a way that str[i][j] can be written for a str object of the String class
//and this expression returns a substring starting at position i(counting from 0) and ending at position j(not including).
//For example :
//String const hello("hello");
//String const hell = hello[0][4]; //  now the substring "hell" is stored in hell
//String const ell = hello[1][4]; // now ell stores the substring "ell"


struct String {
    String(const char* str = "")
    {
        this->size = strlen(str);
        this->str = new char[size + 1];
        for (size_t i = 0; i < size; ++i)
        {
            this->str[i] = str[i];
        }
        this->str[size] = '\0';
    }
    String(size_t n, char c) :size(n)
    {
        str = new char[size + 1];
        for (size_t i = 0; i != size; ++i)
        {
            str[i] = c;
        }
        str[size] = '\0';
    }
    ~String()
    {
        delete[] str;
    }
    String(char* chars, size_t size)
    {
        this->str = new char[size + 1];
        this->size = size;
        for (size_t i = 0; i < size; ++i)
        {
            this->str[i] = chars[i];
        }
        this->str[size] = '\0';
    }

    struct InsideString {
        const String& insString;
        size_t i;
        InsideString(const InsideString&) = default;
        InsideString(const String& outString, size_t i) :insString(outString), i(i) 
        {

        }
        String operator [](size_t j) const
        {
            return String(insString.str + i, size_t(j - i));
        }
    };
    InsideString operator [](size_t i)const
    {
        return InsideString(*this, i);
    }

    String(const String& other) 
    {
        size = strlen(other.str);
        this->str = new char[size + 1];
        for (size_t i = 0; i < size; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[size] = '\0';
    }
    String& operator=(const String& other) 
    {
        if (this->str != nullptr)
        {
            delete[] str;
        }
        this->size = strlen(other.str);
        this->str = new char[size + 1];
        for (size_t i = 0; i < size; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[size] = '\0';
        return *this;
    }
    void append(const String& other) {
        char* new_str = new char[this->size + other.size + 1];
        size_t i = 0;
        for (; i < this->size; ++i)
        {
            new_str[i] = str[i];
        }
        for (size_t j = 0; j < other.size; ++i, ++j)
        {
            new_str[i] = other.str[j];
        }
        size = this->size + other.size;
        new_str[size] = '\0';
        delete[] this->str;
        str = new_str;
    }

    size_t size;
    char* str;
};
