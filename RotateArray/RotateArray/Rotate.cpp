#include<iostream>
using namespace std;

// This function shifts the contents of the array to the left by the specified number of positions (cyclic shift).
void rotate(int a[], unsigned size, int shift)
{
    if (size != shift)
    {
        int firstEl = 0;
        unsigned count = shift % size > 0 ? shift % size : shift;

        for (unsigned i = 0; i < count; ++i)
        {
            firstEl = a[0];
            for (unsigned i = 0; i < size - 1; ++i)
            {
                a[i] = a[i + 1];
            }
            a[size - 1] = firstEl;
        }
    }
}
void showArr(int* arr, unsigned size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
int main()
{
    const unsigned SIZE = 5;
    int a[SIZE] = { 1, 2, 3, 4, 5 };
    showArr(a, SIZE);
    rotate(a, SIZE, 3);
    showArr(a, SIZE);
    return 0;
}