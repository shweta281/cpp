#include <iostream>

using namespace std;

class Employee{
private:
    int age;
    string name;
    float salary;
public:
    // Employee(): age(0), name("New Employee"){}
    Employee(string n = "New Employee", int a = 0, float s = 0.0f): age(a), name(n), salary(s){}
    // Employ
    void getData(){
        cout<<"salary: "<<salary<<"\n"<<"age: "<<age<<"\n"<<"name: "<<name<<endl;
    }
};
int main() {
    Employee e1("shweta", 21, 7.011f);
    Employee e2(e1);
    e1.getData();
    e2.getData();
    return 0;
}













