#include <iostream>
using namespace std;

void InsertionSort(int arr[], int size)
{
  for (int i = 1; i < size; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int BinarySearch(int arr[], int size, int target)
{
  int left = 0, right = size - 1;

  while (left <= right)
  {
    int mid = (left + right) / 2;

    if (arr[mid] == target)
      return mid;
    else if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return -1; 
}

int main()
{
  int arr[] = {2, 5, 1, -9, 3, 9};
  int size = sizeof(arr) / sizeof(arr[0]);

  InsertionSort(arr, size);

  cout << "Sorted Array: ";
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  int target = 5;
  int result = BinarySearch(arr, size, target);

  if (result != -1)
  {
    cout << "Target " << target << " found at index: " << result << endl;
  }
  else
  {
    cout << "Target not found" << endl;
  }
}
