#include<iostream>
using namespace std;

//This function calculates base 2 integer logarithm
int log(int a);
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a;
        cin >> a;
        cout << log(a) << endl;
    }
    return 0;
}
int log(int a)
{
    a = a >>= 1;
    int b = 0;
    while (a)
    {
        a = a >>= 1;
        ++b;
    }
    return b;
}