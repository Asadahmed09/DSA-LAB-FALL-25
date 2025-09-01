#include <iostream>
/*Task #1:
Implement a program that dynamically allocates a 1D array of integers.
=> The size should be given by the user.
=> Initialize all elements with zero.
=> Then, let the user update values at different positions.
=> Finally, print the array and deallocate memory properly.*/
using namespace std;
int main()
{
    int size = 0;
    cout << "Enter the size of Array : " ;
    cin >> size ;
    int* arr = new int[size];
    for(int i = 0 ; i < size ; i++)
    {
        arr[i] = 0;
    }
    while(1)
    {
        cout << "Select the operation : 1 - Update Value. 2 - Exit" << endl;
        int operation = 0;
        cin >> operation;
        if(operation == 1)
        {
            cout << "Enter the index to update the value : " << endl;
            int index = -1;
            cin >> index;
            cout << "Enter the value to update in that index : " << endl;
            cin >> arr[index] ;
            cout << "Value updated in index : " << index << " as a value : " << arr[index] << endl;
        }
        else
        {
            break;
        }
    }
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " " ;
    }
    delete[] arr;
}
