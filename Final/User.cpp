#include <iostream>
#include "User.h"
#include <string>
#include <sstream>
#pragma once
using namespace std;

//Constructors for the Person Class
User::User(){
  lastName = " "; 
  firstName = " "; 
  age = 0;
  address = " ";}
  
User::User(string first, string last){
  lastName = last; 
  firstName = first; 
  age = 0;
  address = "unknown";}
User::User(string first, string last, int num){
  lastName = last; 
  firstName = first; 
  age = num;
  address = "unknown";}
User::User(string first, string last, int num, string add, string phn){
  lastName = last; 
  firstName = first; 
  age = num;
  address = add;
  phone = phn;
	}

//Acessor Methods
string User::getFirstName(){return firstName;}
string User::getLastName(){return lastName;}
string User::getAddress(){return address;}
int User::getAge(){return age;}
string User::getPhoneNumber(){return phone;}


//Mutator Methods:
void User::setFirstName(string name){firstName = name;}
void User::setLastName(string name){lastName = name;}
void User::setAddress(string addr){address = addr;}
void User::setAge(int num){age = num;}
void User::setPhone(string p){phone = p;}


//Instance Methods
//Virtual functions (inherited functions) toString
// string User::toString(){
//     string newAge = to_string(age);
// 		ostringstream s1;
// 		s1 << "Info:\n"<< "\tName: "<<firstName<<" "<<lastName<<"\n\tAddress: "<<address<<"\n\tAge: "<<newAge<<"\n\tPhone Number: "<<phone;
// 		string s2 = s1.str();
// 		return s2;
// 	}
