#include<iostream>
using namespace std;
class BankAccount{
    private:
    double* balance;
    public:
    BankAccount(double amount){
        balance = new double;
        *balance = amount;
        cout << "The Account is created : " << *balance << endl;

    }
    BankAccount(){
        balance = new double;

        *balance = 0;
        cout << "The Account is created : " << *balance << endl;
    }
    BankAccount(const BankAccount& other){
        balance = new double(*other.balance);
    }
    void withdraw(double amount){
        *balance-=amount;
        cout << "THE amount : " << amount << "Has been withdrawn from your account . New Balance is : " << *balance<< endl;
    }
    void deposit(double amount){
        *balance+=amount;
        cout << "THE amount : " << amount << "Has been deposited from your account . New Balance is : " << *balance<< endl;
    }
    void printBalance(){cout << "Balance is : " << *balance << endl;}
    ~BankAccount(){
        delete balance;
    }
};
int main(){
    BankAccount account1;
    BankAccount account2(1000);
    BankAccount account3 = account2;
    account3.withdraw(200);
    account3.printBalance();
    account2.printBalance();
}