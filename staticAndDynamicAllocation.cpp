#include<iostream>
using namespace std;

class parent{
    public:
    parent(){ cout<<"const called"<<endl;}
    ~parent(){ cout<<"destr called"<<endl;}
    };
int main(){
    //static allocation
    parent p1;
    //dynamic allocation
    parent* p2= new parent();
    delete p2;
    }
