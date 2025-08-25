#include"iostream"
using namespace std;
class exam{
    private:
    string* name ,* date ;
    int* score;
    public:
    exam(){
        name = new string;
        date = new string;
        score = new int;
    }
    exam(string name , string date , int score){
        this->name = new string(name);
        this->date = new string(date);
        this->score = new int(score);
    }
    void setDetails(string n , string d , int s)
    {
        *name = n ; *date = d ; *score = s;
    }
    void displayDetails()
    {
        cout << "Name : " << *name << endl << "Date : " << *date << endl << "score : " << *score << endl;
    }
    ~exam(){
        delete name , date , score;
    }
};
int main()
{
    exam s1("asad","14 august", 100);
    exam s2 = s1;
    s2.setDetails("lucky","15 august",200);
    s1.displayDetails();
    s2.displayDetails();
}