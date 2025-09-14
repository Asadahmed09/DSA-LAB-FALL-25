#include "iostream"
using namespace std;
void BubbleSort(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[j] > arr[i])
      {
        swap(arr[j], arr[i]);
      }
    }
  }
}
int main()
{
  int arr[] = {7, -1, 6, 5, 4, 3, -7, -3};
  cout << "Before Sorting : ";
  for (int i = 0; i < sizeof(arr) / 4; i++)
  {
    cout << arr[i] << " ";
  }

  BubbleSort(arr,sizeof(arr)/4);
  cout << endl;
  cout << "After Sorting :";
  for (int i = 0; i < sizeof(arr) / 4; i++)
  {
    cout << arr[i] << " ";
  }
}
