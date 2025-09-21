#include <iostream>
using namespace std;

int sumTail(int n, int total)
{
  if (n == 0)
    return total;
  return sumTail(n - 1, total + n);
}

int sumNonTail(int n)
{
  if (n == 0)
    return 0;
  return sumNonTail(n - 1) + n;
}

int main()
{
  int n = 10;
  int s1 = sumTail(n, 0);
  int s2 = sumNonTail(n);
  cout << s1 << " " << s2 << "\n";
  return 0;
}
