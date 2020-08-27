#include <iostream>
using namespace std;


//This program reverses a sequence of positive integers.
//The input is a sequence of space - separated positive integers.
//The sequence is zero - terminated.
//You want to print this sequence in reverse order.
//On the output, the numbers must also be separated by spaces.
//The trailing zero is just an indicator of the end of the sequence,
//it is not part of it, i.e.you do not need to display it.

int foo()
{
    int a;
    cin >> a;
    if (a == 0) { return a; }
    foo();
    cout << a << ' ';
}

int main()
{
    foo();
    return 0;
}