#include<iostream>
using namespace std;
int main(){
    int a=5;
    int* p=&a;
    void* ptr=&a;
    cout<<p<<" "<<ptr<<endl;
    // cout<<*ptr; not allowed, void pointers cannot be derefereced 
    cout<<*p<<endl;
    }
