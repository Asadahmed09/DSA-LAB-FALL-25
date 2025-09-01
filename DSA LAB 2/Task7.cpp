#include"iostream"
using namespace std;
int main()
{
  int rows = 0 , cols = 0;
  cout << "Enter the number of departments : " ;
  cin >> rows;
  int** arr = new int*[rows];
  int* colSize = new int[rows];
  for(int i = 0 ; i < rows ; i++)
  {
    cout << "Enter the number of employees for Department : " << i+1 << endl;
    cin >> colSize[i];
    arr[i] = new int[colSize[i]];
  }
  for(int i = 0 ; i < rows ; i++)
  {
    cout << "Enter the salaries for Departent : " << i+1 << endl;
    for(int j = 0 ; j < colSize[i] ; j++)
    {
      cout << "Enter the Salary for Employee : " << j << " : ";
      cin >> arr[i][j];
    }
  }
  double* avg = new double[rows];
  int* max = new int[rows];
  for(int i = 0 ; i < rows ; i++){
    avg[i] = 0;
    max[i] =  INT_MIN;
  }
  for(int i = 0; i < rows ; i++)
  {
    for(int j = 0 ; j < colSize[i] ; j++)
    {
      if(max[i]<arr[i][j])
      {
        max[i] = arr[i][j];
      }
      avg[i]+=arr[i][j];
    }
    avg[i]/=colSize[i];
  }
  for(int i = 0  ; i < rows ; i++)
  {
    cout << "Max from department : " << i+1 << " is : " << max[i] << endl;
  }
  double MaxAvg = -999 , MaxAvgIndex = -1;
  for(int i = 0 ; i < rows ; i++)
  {
    if(MaxAvg<avg[i])
    {
      MaxAvg = avg[i];
      MaxAvgIndex  = i+1;
    }
  }
  cout << "The department with max average salary is : " << MaxAvgIndex << endl;
  for(int i = 0 ; i < rows ; i++)
  {
    delete[] arr[i];
  }
  delete[] arr;
  delete[] colSize;
  delete[] avg;
  delete[] max;
}
