#include"iostream"
using namespace std;
int main()
{
  int rows = 0 , cols = 0;
  cout << "enter the number of students : " << endl;
  cin >> rows;
  int** arr = new int*[rows];
  int* colSize = new int[rows];
  for(int i = 0 ; i < rows ; i++)
  {
    cout << "Enter the number of courses for student : " << i+1 << endl;
    cin >> colSize[i] ;
    arr[i] = new int[colSize[i]];
  }
  for(int i = 0 ; i < rows ; i++)
  {
    cout << "Enter the marks for student : " << i+1 << endl;
    for(int j = 0 ; j < colSize[i] ; j++)
    {
      cout << "Enter the marks for course : " << j+1 << " : ";
      cin >> arr[i][j];
    }
    cout << endl;
  }
  double* avgMarks = new double[rows];
  for(int i = 0 ; i < rows ; i++)
  {
    for(int j = 0 ; j < colSize[i] ; j++)
    { 
      avgMarks[i]+=arr[i][j];
    }
    avgMarks[i]/=colSize[i];
    cout << endl;
  }
  for(int i = 0 ; i < rows ; i++)
  {
    cout << "The average marks for student : " << i+1 << " : " << avgMarks[i] << endl;
  }
  for (int i = 0; i < rows; i++)
{
    delete[] arr[i];
}
  delete[] arr;   
  delete[] colSize;
  
}
