
#include <iostream>
using namespace std;
int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    return n * factorial(n-1);
}
int main() {
    cout << "Enter a number to check its factorial : " << endl;
    int n ; cin >> n;
    cout << "Factorial of " << n << " : " << factorial(n);

    return 0;
}
