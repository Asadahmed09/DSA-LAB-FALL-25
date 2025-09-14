#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void BubbleSort(int arr[], int n, long long &comparisons, long long &swaps)
{
  comparisons = swaps = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      comparisons++;
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swaps++;
      }
    }
  }
}

void InsertionSort(int arr[], int n, long long &comparisons, long long &swaps)
{
  comparisons = swaps = 0;
  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0)
    {
      comparisons++;
      if (arr[j] > key)
      {
        arr[j + 1] = arr[j];
        swaps++;
        j--;
      }
      else
        break;
    }
    arr[j + 1] = key;
  }
}

void ShellSort(int arr[], int n, long long &comparisons, long long &swaps)
{
  comparisons = swaps = 0;
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < n; i++)
    {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap; j -= gap)
      {
        comparisons++;
        if (arr[j - gap] > temp)
        {
          arr[j] = arr[j - gap];
          swaps++;
        }
        else
          break;
      }
      arr[j] = temp;
    }
  }
}

int main()
{
  const int n = 1000;
  int arr[n], arr1[n], arr2[n], arr3[n];

  for (int i = 0; i < n; i++)
  {
    arr[i] = rand() % 10000; 
    arr1[i] = arr2[i] = arr3[i] = arr[i];
  }
  long long comp, swp;
  auto start = high_resolution_clock::now();
  BubbleSort(arr1, n, comp, swp);
  auto end = high_resolution_clock::now();
  cout << "Bubble Sort :  Comparisons: " << comp << ", Swaps: " << swp
       << ", Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

  start = high_resolution_clock::now();
  InsertionSort(arr2, n, comp, swp);
  end = high_resolution_clock::now();
  cout << "Insertion Sort :  Comparisons: " << comp << ", Swaps: " << swp
       << ", Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

  start = high_resolution_clock::now();
  ShellSort(arr3, n, comp, swp);
  end = high_resolution_clock::now();
  cout << "Shell Sort :  Comparisons: " << comp << ", Swaps: " << swp
       << ", Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

}
