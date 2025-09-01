#include "iostream"
using namespace std;
int main()
{
  int rows, cols;
  cout << "Enter number of rows and columns : ";
  cin >> rows >> cols;

  int **mat = new int *[rows];
  for (int i = 0; i < rows; i++)
  {
    mat[i] = new int[cols];
  }

  cout << "Enter matrix elements : " << endl;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cin >> mat[i][j];
    }
  }

  cout << "matrix in normal form : " << endl;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }

  cout << "matrix in compressed form --- row, column, value ---:" << endl;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (mat[i][j] != 0)
      {
        cout << i << " " << j << " " << mat[i][j] << endl;
      }
    }
  }

  for (int i = 0; i < rows; i++)
  {
    delete[] mat[i];
  }
  delete[] mat;

  return 0;
}
