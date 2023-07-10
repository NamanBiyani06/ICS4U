#include <string>
#include <iostream> 
using namespace std;

#ifndef USER_H
#define USER_H

class User {
protected:
    string firstName;
    string lastName;
    int age; 
    string address;
    string phone;

public:    //~Fraction();
    User();
    User(string first, string last);
    User(string first, string last, int age);
    User(string first, string last, int age, string add, string phn);
    string getFirstName();
    string getLastName();
    string getAddress();
    int getAge();
    string getPhoneNumber();
    void setFirstName(string n);
    void setLastName(string n);
    void setAddress(string a);
    void setAge (int a);
    void setPhone (string p);
    // virtual string toString();
  
};
#endif