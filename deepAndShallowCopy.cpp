#include<iostream>
#include<cstring>
using namespace std;
//deep and shallow copy
// default copy constructor creates a shallow copy
class record{
    public:
    string name;
    char* address;
    record(){
        address= new char[10];
        }
    void print(){
        cout<<name<<" "<<address<<endl;
        }
    // making a deep copy to avoid shallow copy of default constructor
    record( record &r){
        this->name= r.name;
        char* newchar= new char[strlen(r.address)]; //strlen strcpy
        strcpy(newchar, r.address);
        this->address= newchar;
        }
    };

int main(){
    record r1;
    r1.name="name1";
    char add1[10]="manish";
    r1.address= add1;
    record r2(r1);
    //record r2=r1;
    r1.print();
    r2.print();
    r1.address[0]='p';
    r1.print();
    r2.print();
    }
