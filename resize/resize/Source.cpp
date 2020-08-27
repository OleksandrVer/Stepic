
//The resize function takes three arguments as input: 
//a pointer to the memory area allocated using the new [] operator, 
//the size of the area (size) and the new size (new_size). 
//The function must allocate memory of size new_size, 
//copy data into it from the transferred memory area, 
//free the old memory area and return the allocated memory area of the new size with the copied data.

char* resize(const char* str, unsigned size, unsigned new_size)
{
    size = size < new_size ? size : new_size;
    char* newStr = new char[new_size];
    for (unsigned i = 0; i < size; ++i)
    {
        newStr[i] = str[i];
    }
    delete[] str;
    return newStr;
}
