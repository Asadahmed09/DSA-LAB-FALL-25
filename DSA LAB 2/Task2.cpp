#include "iostream"
using namespace std;
int main()
{
    int rows = 0 , cols = 0;
    cout << "Enter the number of rows and coloms : " << endl;
    cin >> rows >> cols ;
    int** arr = new int*[rows];
    for(int i = 0 ; i < rows ; i++){
        arr[i] = new int[cols];
    }
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++)
        {arr[i][j] = 0;}
    }
    while(1)
    {
        cout << "Enter the operation :  1 - fill seat 2 - exit" << endl;
        int operation = 0;
        cin >> operation;
        if(operation==1)
        {
            cout << "enter the row and colom number to fill the seat" << endl;
            int rows = 0 , cols = 0;
            cin >> rows >> cols;
            arr[rows-1][cols-1] = 1;
            cout << "- seat is now filled ." << endl;
        } 
        else
        {
            break;
        }
    }
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
