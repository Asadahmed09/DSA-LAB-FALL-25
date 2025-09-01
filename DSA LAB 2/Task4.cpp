#include "iostream"
using namespace std;
int main()
{
  int months = 0;
  cout << "Enter the number of months to store the expenses : " << endl;
  cin >> months;
  int *expensesForMonths = new int[months];
  for (int i = 0; i < months; i++)
  {
    int expenses = 0;
    cout << "Enter the expenses for month : " << i + 1 << " - ";
    cin >> expenses;
    expensesForMonths[i] = expenses;
  }
  while (1)
  {
    int opr = 0;
    cout << "Enter the operation to perform the task : 1 - Resize the array 2 - display average expenses 3 - display total expenses 4 - leave" << endl;
    cin >> opr;
    if (opr == 1)
    {
      int newMonths = 0;
      cout << "Enter the new months for storing expenses : " << endl;
      cin >> newMonths;
      int *newArr = new int[newMonths];
      for (int i = 0; i < months; i++)
      {
        newArr[i] = expensesForMonths[i];
      }
      delete[] expensesForMonths;
      expensesForMonths = newArr;
      for (int i = months; i < newMonths ; i++)
      {
        int expenses = 0;
        cout << "Enter the expenses for month : " << i + 1 << " - ";
        cin >> expenses;
        expensesForMonths[i] = expenses;
      }

      months = newMonths;
    }
    else if (opr == 2)
    {
      double avgExpenses = 0;
      for (int i = 0; i < months; i++)
      {
        avgExpenses += expensesForMonths[i];
      }
      avgExpenses /= months;
      cout << "The average expenses for months : " << months << " are : " << avgExpenses << endl;
    }
    else if (opr == 3)
    {
      double totalExpenses = 0;
      for (int i = 0; i < months; i++)
      {
        totalExpenses += expensesForMonths[i];
      }
      cout << "The total expenses for months : " << months << " are : " << totalExpenses << endl;
    }
    else
    {
      break;
    }
  }
  delete[] expensesForMonths;
}
