#include"iostream"
using namespace std;
class Box{
    private:
    int *length , *width;
    public:
    Box(int length , int width ){
        this->length = new int(length);
        this->width = new int(width);
        cout << "Copy constructor called ." << endl;
    }
    Box(){
        length = new int;
        width = new int;
        cout << "Copy constructor called ." << endl;
    }
    Box(const Box& other){
        length = new int(*other.length);
        width = new int(*other.width);
        cout << "Deep copy constructor called ." << endl;
    }
    Box &operator =(Box& other){
        if(this!=&other){
            delete length , width;
            length = new int(*other.length);
            width = new int(*other.width);
            cout << "Copy assignment operator called ." << endl;
        }
        return *this;
    }
    void displayValue(){
        cout << "Length : " << *length << endl << "Width : " << *width << endl;
    }
    void modifyValue(int l , int w){
        *length = l;
        *width = w;
        cout << "After modifying values : " ;
        cout << "Length : " << *length << endl << "Width : " << *width << endl;
    }
    ~Box(){
        delete length;
        delete width;
    }
};
int main()
{
    Box b1(5,5);
    Box b2(6,5);
    b1.displayValue();
    b2.displayValue();
    b1 = b2;
    b1.modifyValue(10,10);
    b2.displayValue();
}