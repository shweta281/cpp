#include<iostream>
using namespace std;

class Employee{
    public:
    float salary;
    Employee(){
        count++;
    }
    void show(){
        cout<<this->salary<<endl;
    }
    static int count;
    static void getStat(){
        cout<<"Employee count is: "<<count<<endl;
    }
};
int Employee::count = 0;
int main(){
    Employee e1;
    e1.getStat();
    Employee::getStat();
    cout<<Employee::count<<endl;
    cout<<e1.count<<endl;
    Employee e2;
    e2.getStat();
}
