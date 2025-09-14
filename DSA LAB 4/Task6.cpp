#include <iostream>
using namespace std;

void CombSort(int arr[], int n, int &comparisons, int &swaps)
{
  int gap = n;
  bool swapped = true;

  while (gap > 1 || swapped)
  {
    gap = (gap * 10) / 13;
    if (gap < 1)
      gap = 1;

    swapped = false;
    for (int i = 0; i + gap < n; i++)
    {
      comparisons++;
      if (arr[i] > arr[i + gap])
      {
        swap(arr[i], arr[i + gap]);
        swaps++;
        swapped = true;
      }
    }
  }
}

int main()
{
  int n;
  cout << "Enter size of array: ";
  cin >> n;

  int arr[n];
  cout << "Enter " << n << " integers:" << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int comparisons = 0, swaps = 0;

  CombSort(arr, n, comparisons, swaps);

  cout << "\nSorted array:\n";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  cout << "\nTotal Comparisons: " << comparisons << endl;
  cout << "Total Swaps: " << swaps << endl;
}
