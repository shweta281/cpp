#include<iostream>
using namespace std;

class p{
    public:
    int* num;
    p(int val){
        num= new int;
        *num = val;
        cout<<"const called"<<endl;
        }
    ~p(){
        delete(num);
        cout<<"object destroyed"<<endl;
        }
    };
    
int main(){
    p obj1(1);
    p* obj2= new p(1);
    }    
    
