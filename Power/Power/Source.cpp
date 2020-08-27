#include<iostream>
using namespace std;

//This function implements the raising of an integer to a non-negative integer power.
int power(int x, unsigned p) {
    int answer;
    if (p == 0) { return 1; }
    answer = x * power(x, p - 1);    
    return answer;
}