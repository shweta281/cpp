#include<iostream>
using namespace std;
//friend function 
 
class bank{
private:
    int account_balance;
    string account_number;
public:
    // int get_balance(){
    //     return account_balance;
    //     }
    bank(): account_balance(0), account_number("XXX"){}
    void transfer( int cash){
        this->account_balance+=cash;
        }
    friend void make_transaction(bank &b, int cash);
    friend void get_balance(bank b);
    };
void make_transaction(bank &b, int cash){
        b.account_balance-=cash;
    }
void get_balance(bank b){
        cout<<b.account_balance<<endl;
    }
int main(){
    bank b;
    b.transfer(10000);
    make_transaction(b,500);
    get_balance(b);
    }
    
    
    
    
