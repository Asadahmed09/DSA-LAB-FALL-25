#include <iostream>
using namespace std;
#define N 9
void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;
    return true;
}

bool solveSudoku(int grid[N][N])
{
    int row = -1, col = -1;
    bool emptyFound = false;
    for (int i = 0; i < N && !emptyFound; i++)
    {
        for (int j = 0; j < N && !emptyFound; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                emptyFound = true;
            }
        }
    }
    if (!emptyFound)
        return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int grid[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 0, 0, 6, 8},
        {9, 0, 0, 8, 0, 6, 0, 0, 5},
        {0, 5, 0, 0, 0, 0, 0, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    if (solveSudoku(grid))
        printGrid(grid);
    else
        cout <<"No solution exists" << endl;
}
