#include <iostream>
#include "Customer.h"
#include "User.h"
#include <string>
#include <sstream>
#pragma once
using namespace std;

//    Delete Existing Flight
//    Reschedule Flight
//    Book New Flight
//    Change Seat

//ID Check
	bool Customer::isValidId(string id){
		if((id.at(0)=='t' || id.at(0)=='T') && id.length() == 10)
			return true;
		return false;
	}

//Constructors
	Customer::Customer(): User(){
    passportId = "Not entered";
    mealPlan = "Vegetarian";
        //currentSeat = null;
  //currentFlight = null;
  }
	Customer::Customer(string f,string l): User(f,l){
    passportId = "Not entered";
    mealPlan = "Vegetarian";
        //currentSeat = null;
  //currentFlight = null;
  }


	Customer::Customer(string f, string l, int num, string a, string p) : User(f, l,num,a,p){
    passportId = "Not entered";
    mealPlan = "Vegetarian";
        //currentSeat = null;
  //currentFlight = null;
  }

	Customer::Customer(string f, string l, int num, string a, string p, string passPort) : User(f, l,num,a,p){
  if(isValidId(passPort)==true)
      passportId = passPort;
		else
			passportId = "invlaid id";
    mealPlan = "Vegetarian";
        //currentSeat = null;
  //currentFlight = null;
  }

	Customer::Customer(string f, string l, int num, string a, string p, string passPort, string meal) : User(f, l,num,a,p){
    if(isValidId(passPort)==true)
      passportId = passPort;
		else
		passportId = "invlaid id";
    mealPlan = meal;
    //currentSeat = null;
  //currentFlight = null;
  }

	string Customer::toString(){
    string newAge = to_string(age);
		ostringstream s1;
		s1 << "Customer Information:\n"<< "\tName: "<<firstName<<" "<<lastName<<"\n\tAddress: "<<address<<"\n\tAge: "<<newAge<<"\n\tPhone Number: "<<phone<<"\n\tPassport ID: "<<passportId<<"\n\tMeal Plan: "<<mealPlan;
		string s2 = s1.str();
		return s2;
	} 

  string Customer::getFirstName(){
    return firstName;
  }
  string Customer::getLastName(){
    return lastName;
  }
  string Customer::getAddress(){
    return address;
  }
  string Customer::getPhone(){
    return phone;
  }
  int Customer::getAge(){
    return age; 
  }
string Customer::getID(){
    return passportId;
  }


  bool Customer::operator>(const Customer& other) const {
        if (lastName == other.lastName) {
            return firstName > other.firstName;
        }
        return lastName > other.lastName;
    }
  bool Customer::operator<(const Customer& other) const {
        if (lastName == other.lastName) {
            return firstName < other.firstName;
        }
        return lastName < other.lastName;
    }
  bool Customer::operator==(const Customer& other) const {
        return firstName == other.firstName && lastName == other.lastName;
    }


  
  /* void Customer::deleteExistingFlight(){
      onFlight = false; 
      currentSeat = null;
      currentFlight = null;
  } */
  /* void Customer::rescheduleFlight (Flight& other){
        onFlight = true;
        currentSeat = null;
        currentFlight = other;
        //Find available seat...
        //Return flight info (new)

  } */
  /* void Customer::newFlight(Flight& other){
      onFlight = true; 
      currentFlight = other;
      //Find available seat...
      //Return flight info (new)

  } */
  /* void Customer::changeSeat(Seat& other){    
  currentSeat = null;
  } */

void Customer::reset(){
	string passportId = "";
  string mealPlan = "";
  bool onFlight = false;
  firstName = "";
  lastName = "";
  address = "";
  phone = "";
  //Seat currentSeat
  //Flight currentFlight; 

}
