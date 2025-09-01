#include "iostream"
using namespace std;

int main()
{
  int categories;
  cout << "Enter number of categories : ";
  cin >> categories;
  int *booksPerCat = new int[categories];
  int **library = new int *[categories];

  for (int i = 0; i < categories; i++)
  {
    cout << "Enter number of books in category " << i + 1 << " : ";
    cin >> booksPerCat[i];

    library[i] = new int[booksPerCat[i]];

    cout << "Enter book ids for category " << i + 1 << " : " << endl;
    for (int j = 0; j < booksPerCat[i]; j++)
    {
      cin >> library[i][j];
    }
  }

  int searchID;
  cout << "Enter Book ID to search : ";
  cin >> searchID;

  bool found = false;
  int foundCat = -1;
  for (int i = 0; i < categories; i++)
  {
    for (int j = 0; j < booksPerCat[i]; j++)
    {
      if (library[i][j] == searchID)
      {
        found = true;
        foundCat = i;
        break;
      }
    }
    if (found)
      break;
  }

  if (found)
    cout << "Book ID " << searchID << " is available in category " << foundCat + 1 << endl;
  else
    cout << "Book ID " << searchID << " is not available." << endl;

  for (int i = 0; i < categories; i++)
  {
    delete[] library[i];
  }
  delete[] library;
  delete[] booksPerCat;
}
