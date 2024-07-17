#include<iostream>
using namespace std;
template <class dataType>
class stack{
    dataType arr[10];
    int i;
    public:
    stack(){
        i=-1;
    }
    void push( dataType val){
        i++;
        arr[i]=val;
    }
    void pop(){
        i--;
    }
    dataType top(){
        // if(i==-1) return ;
        return arr[i];
    }
    bool isempty(){
        if(i==-1) return true;
        return false;
        }
};
int main(){
    stack<int>* s = new stack<int>();
    s->push(5);
    s->push(9);
    s->push(7);
    s->push(2);
    s->pop();
    cout<<s->top()<<endl;
    s->pop();
    cout<<s->top()<<endl;
    s->pop();
    cout<<s->top()<<endl;
    stack<char>*s1= new stack<char>();
    s1->push('a');
    s1->push('d');
    s1->push('p');
    cout<<s1->top()<<endl;
    s1->pop();
    cout<<s1->top();
    }
    
    
    
    
    
    
    
    
    
