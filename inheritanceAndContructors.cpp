#include<iostream>
using namespace std;

class a{
  public:
  a(){
      cout<<"class a"<<endl;
  }
  a(int x ){
      cout<<"class a parametrized constructor"<<endl;
  }
};
class b{
  public:
  b(){
      cout<<"class b"<<endl;
  }
  b(int x){
      cout<<"class b parametrized constructor"<<endl;
  }
};
class c : public a, public b{
  public:
  c(){
      cout<<"class c"<<endl;
  }
  c(int x) : a(x), b(x){
      cout<<"class c parametrized constructor"<<endl;
  }
};
int main(){
    c objc1(3);
}

