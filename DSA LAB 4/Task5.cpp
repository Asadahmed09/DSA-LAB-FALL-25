#include <iostream>
using namespace std;
int InterpolationSearch(int arr[], int size, int target)
{
  int left = 0, right = size - 1;
  while (left <= right && target >= arr[left] && target <= arr[right])
  {
    int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);

    if (arr[pos] == target)
      return pos;
    else if (arr[pos] < target)
      left = pos + 1;
    else
      right = pos - 1;
  }

  return -1;
}

int main()
{
  int size;
  cout << "Enter size of array: ";
  cin >> size;
  int arr[size];
  cout << "Enter " << size << " sorted elements (uniformly distributed): ";
  for (int i = 0; i < size; i++)
  cin >> arr[i];

  int target;
  cout << "Enter target value: ";
  cin >> target;
  int result = InterpolationSearch(arr, size, target);

  if (result != -1)
    cout << "Element found at index: " << result << endl;
  else
    cout << "Element not present in the array." << endl;

}
