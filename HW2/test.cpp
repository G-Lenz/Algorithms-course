#include <iostream>
#include <math.h>
using namespace std;

int main()
{
     int size;
     cin >> size;
     int m = 2*size/3 + (((2*size) % 3) != 0);
     cout << m;
     return 0;
}

