#include <iostream>
using namespace std;

bool ok(int col[], int r, int c)
{
  for (int i = 0; i < r; i++)
  {
    if (col[i] == c)
      return false;
    if (abs(col[i] - c) == abs(i - r))
      return false;
  }
  return true;
}

void printb(int col[], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << (col[i] == j ? 'Q' : '.') << " ";
    cout << "\n";
  }
  cout << "\n";
}

void solve(int r, int n, int col[])
{
  if (r == n)
  {
    printb(col, n);
    return;
  }
  for (int c = 0; c < n; c++)
  {
    if (ok(col, r, c))
    {
      col[r] = c;
      solve(r + 1, n, col);
    }
  }
}

int main()
{
  int n = 8;
  int col[20];
  for (int i = 0; i < n; i++)
    col[i] = -1;
  solve(0, n, col);
}
