#include<iostream>
using namespace std;
//virtual destructor
class parent{
    public:
    parent(){ cout<<"parent class cons"<<endl; }
    virtual ~parent(){ cout<<"parent class destructor"<<endl; }
    };
class child: public parent{
    public:
    child(){ cout<<"child class cons"<<endl; }
    ~child(){ cout<<"child class destructor"<<endl; }
    };
int main(){
    parent* p= new child();
    delete p;
    }
//9, 
