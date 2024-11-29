#include<iostream>
using namespace std;

class base{
public:
    // void show(){
    //     cout<<"Base"<<endl;
    // } 
    virtual void show(){
        cout<<"Base"<<endl;
    } 
    virtual ~base(){
        cout<<"base destroyed"<<endl;
    }
};
class child1:public base{
    public:
    void show(){
        cout<<"Child 1<"<<endl;
    }
    ~child1(){
        cout<<"child 1 destroyed"<<endl;
    }
};
class child2 :public base{
    public:
    void show(){
        cout<<"Child 2<"<<endl;
    }
    ~child2(){
        cout<<"child 2 destroyed"<<endl;
    }
};
int main(){
    base *ptr = new child1();
    // after making show in base virtual
    ptr->show();
    // after making base destructor virtual
    delete ptr;
}
