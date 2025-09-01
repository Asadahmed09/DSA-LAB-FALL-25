#include"iostream"
using namespace std;
int main()
{
  int rows  = 0 , cols = 0;
  cout << "Enter the number of rows and cols for matrix 1 and 2 : " << endl;
  cin >> rows >> cols;
  int** matrixOne = new int*[rows];
  int **matrixTwo = new int *[rows];
  for(int i = 0 ; i < rows ; i++)
  {
    matrixOne[i] = new int[cols];
    matrixTwo[i] = new int[cols];
  }
  for(int i = 0 ; i < rows ; i++)
  {
    cout << "Enter the values for row "<< i+1 <<" of matrix 1 and 2 : " << endl;
    for(int j = 0 ; j < cols ; j++)
    {
      cout << "Enter value for col : " << j+1 << " of both matrices : " ;
      cin >> matrixOne[i][j] >> matrixTwo[i][j];
    }
  }
  while(1)
  {
    int opr = 0;
    cout << "Enter the operation to perform : 1 - addition of 2 matrix . 2 - subtraction of 2 matrix" << endl;
    cin >> opr;
    if(opr==1)
    {
      int** addMatrix = new int*[rows];
      for (int i = 0; i < rows; i++)
      {
        addMatrix[i] = new int[cols];
      }
      for(int i = 0 ; i < rows ; i++)
      {
        for(int j = 0 ; j < cols ; j++)
        {
          addMatrix[i][j] = matrixOne[i][j]+matrixTwo[i][j];
          cout << addMatrix[i][j] << " ";
        }
        cout << endl;
      }
      for(int i = 0 ; i < rows ; i++)
      {
        delete[] addMatrix[i];
      }
      delete[] addMatrix;
    }
    else if(opr==2)
    {
      int **subMatrix = new int *[rows];
      for (int i = 0; i < rows; i++)
      {
        subMatrix[i] = new int[cols];
      }
      for (int i = 0; i < rows; i++)
      {
        for (int j = 0; j < cols; j++)
        {
          subMatrix[i][j] = matrixOne[i][j] - matrixTwo[i][j];
          cout << subMatrix[i][j] << " ";
        }
        cout << endl;
      }
      for (int i = 0; i < rows; i++)
      {
        delete[] subMatrix[i];
      }
      delete[] subMatrix;
    }
    else{
      break;
    }

  }
  for(int i = 0 ; i < rows ; i++)
  {
    delete[] matrixOne[i];
    delete[] matrixTwo[i];
  }
  delete[] matrixOne;
  delete[] matrixTwo;
}
