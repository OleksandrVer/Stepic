
#include <cstddef>

//Implement a function copy_n for copying elements  from a source array of type U* to a target array of type T*, 
//where T and U are arbitrary types for which a conversion from U to T is defined.
//The function takes as input two pointers and the number of elements to be copied.
//An example of calling the copy_n function :
//int ints[] = { 1, 2, 3, 4 };
//double doubles[4] = {};
//copy_n(doubles, ints, 4); // now the doubles array contains elements 1.0, 2.0, 3.0 and 4.0

template<typename T, typename U>
void copy_n(T* const T1, U* const U1, size_t const n)
{
    for (size_t i = 0; i < n; ++i)
    {
        T1[i] = (T)U1[i];
    }
}