#include"iostream"
using namespace std;
int main()
{
  int days = 0 , times = 0;
  cout << "enter the number of days and number of times: " << endl;
  cin >> days >> times;
  int** TempReading = new int*[days];
  for(int i = 0  ; i < days ; i++)
  {
    TempReading[i] = new int[times];
  }
  for(int i = 0 ; i < days ; i++)
  {
    cout << "Enter the temperatures for day : " << i+1 << endl;
    for(int j = 0 ; j < times ; j++)
    {
      cout << "time : " << j+1 << " - ";
      cin >> TempReading[i][j];
    }
  }
  double* avg = new double[days];
  for(int i = 0 ; i < days ; i++)
  {
    for(int j = 0 ; j < times ; j++)
    {
      avg[i]+=TempReading[i][j];
    }
    avg[i]/=times;
    cout << "The average temperature of day : " << i+1 << " is : " << avg[i] << endl;
  }
  int hottest = 0, coldest = 0;
  for (int i = 1; i < days; i++)
  {
    if (avg[i] > avg[hottest])
      hottest = i;
    if (avg[i] < avg[coldest])
      coldest = i;
  }

  cout << "Hottest day is Day " << hottest + 1 << " with average " << avg[hottest] << endl;
  cout << "Coldest day is Day " << coldest + 1 << " with average " << avg[coldest] << endl;

  for (int i = 0; i < days; i++)
  {
    delete[] TempReading[i];
  }
  delete[] TempReading;
  delete[] avg;
}
