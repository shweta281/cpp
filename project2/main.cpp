#include<iostream>
#include<fstream>
using namespace std;

class newUser{
private:
    string username;
    string password;
    string name;
    string phone_no;
    string email;
public:
    //newUser( string username, string password): username(username), password(password){}
    //getters and setters
    string getName(){
        return name;
    }
    string getEmail(){
        return email;
    }
    string getPhone(){
        return phone_no;
    }
    string getUsername(){
        return username;
    }
    string getPassword(){
        return password;
    }
    void setName( string nam){
        this->name=nam;
    }
    void setEmail( string emai){
        this->email=emai;
    }
    void setPhoneNo( string phon){
        this->phone_no=phon;
    }
    void setUsername( string u){
        this->username=u;
    }
    void setPassword(string p){
        this->password=p;
    }
    //friend class LoggedIn;
};


void storeInDatabase(newUser* newUserObject){
    fstream file;
    file.open("details.txt", ios::app );
    if(file.is_open()){
        file<<"username:"+newUserObject->getUsername()+" password:"+newUserObject->getPassword()<<endl;
        file<<"Name:"+newUserObject->getName()+"  Email:"+newUserObject->getEmail()+"  Phone no.:"+newUserObject->getPhone()<<endl;
        cout<<"Account created succesfully!"<<endl;
        //tryLogin();
    }
    else{
        cout<<"Database error please try again later youre in store database"<<endl;
    }
    file.close();
}

void storeAccountsDetails(newUser* newUserObject){
    fstream file;
    file.open("accountsDatabase.txt", ios::app);
    if(file.is_open()){
        file<<"username:"+newUserObject->getUsername()+" password:"+newUserObject->getPassword()<<endl;
        storeInDatabase(newUserObject );
    }
    else{
        cout<<"COULDN't CREATE THE ACCOUNT PLEASE TRY AGAIN LATER youre in storeaccounts"<<endl;
    }
    file.close();
}

void registerNewUser(){
    newUser* l= new newUser();
    string username;
    string password;
    string passwordVerify;
    string name;
    string phone_no;
    string email;
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter your phone number: ";
    cin>>phone_no;
    cout<<"Enter your email address: ";
    cin>>email;
    cout<<"Enter a username: ";
    cin>>username;
    cout<<"Enter a strong password: ";
    cin>>password;
    //enter password again
    cout<<"Enter the password again: ";
    cin>>passwordVerify;
    while(password!=passwordVerify){
        cout<<"The passwords dont match: ";
        cout<<"Enter the password again: ";
        cin>>passwordVerify;
    }
    // l is the new user object
    l->setName(name);
    l->setEmail(email);
    l->setPhoneNo(phone_no);
    l->setUsername(username);
    l->setPassword(password);
    storeAccountsDetails(l); // l is the new user object

}

void logIn( string username, string password){
    fstream file;
    file.open("details.txt", ios::in | ios:: app);
    if(!file.is_open()){
        cout<<"DATABASE ERROR TRY AGAIN LATER youre in login"<<endl;
    }
    else{
        int flag=0;
        file.seekg(0);
        string line;
        while(!file.eof()){
            getline(file, line);
            if(flag==1){
                cout<<"Your details:"<<endl;
                cout<<line<<endl;
                flag=0;
                break;
            }
            if(line=="username:"+username+" password:"+password){
                flag=1;
            }
        }
    }
    file.close();
}

bool userExists( string username, string password){
    fstream file;
    file.open("accountsDatabase.txt", ios:: in | ios:: app);
    if(!file.is_open()){
        cout<<"DATABASE ERROR TRY AGAIN LATER youre in user exits"<<endl;
    }
    else{
        file.seekg(0);
        string line;
        while(!file.eof()){
            getline(file, line);
            if(line=="username:"+username+" password:"+password){
                file.close();
                return true;
            }
        }
    }
    file.close();
    return false;
}

bool logOut(string username, string password){
    cout<<"Log out? (y/n) "<<endl;
    char logout;
    cin>>logout;
    if(logout=='y'){
        cout<<"Logged out of "+username;
        return true;// change to obj
    }
    return false;
}

void tryLogin(){
    cout<<"Please enter your username and password:"<<endl;
    string username,password;
    cin>>username;
    cin>>password;
    //checking if the password and username already exists in the database or the user needs to create a new accountv
    if(userExists(username, password)) {
        cout<<"Login succesful"<<endl;
        logIn(username, password);
        if(!logOut( username, password)){
            cout<<"Continue with another account? (y/n)"<<endl;
            char continueWithAnotherAccount;
            cin>> continueWithAnotherAccount;
            if( continueWithAnotherAccount=='y'){
                tryLogin();
            }
        }
    }
    else{
        cout<<"account doesn't exists, please register as new user:"<<endl;
        registerNewUser();
        cout<<"Try logging in: "<<endl;
        tryLogin();
    }
}

int main(){
    tryLogin();
}
