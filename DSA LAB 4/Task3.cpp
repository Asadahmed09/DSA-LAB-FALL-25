#include"iostream"
using namespace std;
void SelectionSort(int arr[] , int size)
{
  for(int i = 0 ; i < size-1 ; i++)
  {
    int MinIndex = i;
    for(int j = i+1 ; j < size ; j++)
    {
      if(arr[j]<arr[MinIndex])
      {
        MinIndex = j;
      }
    }
    swap(arr[i],arr[MinIndex]);
  }
}
int main()
{
  int arr[] = { 2 , 5 , 1 , -9 , 3 , 9};
  SelectionSort(arr,sizeof(arr)/4);
  for(int i = 0 ; i < sizeof(arr)/4  ; i++)
  {
    cout << arr[i] << " ";
  }
}
