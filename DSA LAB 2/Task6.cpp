#include"iostream"
using namespace std;
class safePointer
{
  private:
  int* value;
  public:
  safePointer()
  {
    value = new int;
  }
  void setValue(int value)
  {
    *this->value = value;
  }
  int getValue()
  {
    return *this->value;
  }
  void release()
  {
    delete value;
    value = nullptr;
  }
};
int main()
{
  int arr[5] = {100,88,76,87,99};
  safePointer students[5];
  for(int i = 0 ; i < 5 ; i++)
  {
    students[i].setValue(arr[i]);
  }
  for(int i = 0 ; i < 5 ; i++)
  {
    cout << "Student " << i+1 << " Marks : " << students[i].getValue() << endl;
  }
  for (int i = 0; i < 5; i++)
  {
    students[i].release();
  }
}
