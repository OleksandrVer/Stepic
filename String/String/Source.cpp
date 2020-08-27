#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

//Let's create our own simple analogue of the standard string class for convenient work with strings.

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
	//For a string, you might find a fill constructor useful(for example, to create a string of spaces).
	//The fill constructor takes a numberand a characterand creates a string with the specified number 
	//of repetitions of the passed character.
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
	//append method appends a copy of the argument string to the end of the current line
	//(i.e.to the end of the line on which it was called).
	void append(String& other) 
	{
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
	String(const String& other)  //called when copying an existing object (b (a))
	{
		size = strlen(other.str);
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[size] = '\0';
	}
	String(String&& other)  //called when copying a temporary object
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
	}
	String& operator =(const String& other)  //called when assigning an object
	{		
		if (this->str != nullptr)
		{
			delete[] str;
		}
		this->size = strlen(other.str);
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[size] = '\0';
		return *this;
	}
	

	bool operator ==(const String& other)
	{
		if (this->size != other.size)
		{
			return false;
		}
		
		for (int i = 0; i < this->size; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}
		
	bool operator !=(const String& other)
	{
		return !(this->operator==(other));
	}

	String operator +(const String& other)
	{
		String newStr;
		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);
		newStr.str = new char[thisLength + otherLength + 1];
		newStr.size = thisLength + otherLength;
		int i = 0;
		for (; i < thisLength; ++i)
		{
			newStr.str[i] = this->str[i];
		}
		for (int j = 0; j < otherLength; ++j,++i)
		{
			newStr.str[i] = other.str[j];
		}
		newStr.str[thisLength + otherLength] = '\0';
		return newStr;
	}
		
	char& operator [](int index)
	{
		return this->str[index];
	}

	size_t size;
	char* str;
};