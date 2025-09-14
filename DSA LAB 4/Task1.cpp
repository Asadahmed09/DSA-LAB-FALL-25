#include "iostream"
using namespace std;
int LinearSearch(int arr[], int size ,int target)
{
  int flag = 0;
  for(int i = 0 ; i < size ; i++)
  {
    if(arr[i]==target)
    {
      return i;
    }
  }
  return flag;
}
int main()
{
  int arr[] = {3,4,5,6,7,57,66};
  int target = 9;
  int size  = sizeof(arr)/sizeof(arr[0]);
  if(LinearSearch(arr,size,target))
  {
    cout << "Target found at index : " << LinearSearch(arr,size,target) << endl;
  }
  else
  {
    cout << "Target : "<< target <<" not found" << endl;
  }
}
