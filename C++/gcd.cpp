#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 

int gcd(int a, int b)
{
    if (b==0)
    return a;
    gcd(b, a%b);
}

int main() {
    int a=15,b=5;
    cout<<gcd(a,b);
    return 0;

}