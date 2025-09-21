#include <iostream>
using namespace std;

void printNumbers(int n)
{
    if(n<=0) return;
    cout<<n<<" ";
    printNumbers(n-1);
}

int main()
{
    int n=10;
    printNumbers(n);
    cout<<"\n";
    return 0;
}
