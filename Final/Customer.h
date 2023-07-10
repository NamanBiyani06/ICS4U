#include <iostream>
#include "User.h"

#pragma once
using namespace std;

//Student database copy 

class Customer: public User{
private:
	string passportId;
  string mealPlan;
  bool onFlight;
  //Seat currentSeat
  //Flight currentFlight; 
  bool isValidId(string);

public:
  Customer();
    Customer(string,string);
    Customer(string,string,int,string,string);
  Customer (string,string,int,string,string,string);
  Customer (string,string,int,string,string,string,string);
  string toString();
  string getFirstName();
  string getLastName();
    string getAddress();
  string getPhone();
    string getID();
  int getAge();
  bool operator>(const Customer& other) const;
  bool operator<(const Customer& other) const;
  bool operator==(const Customer& other) const;
  void reset();

  //void deleteExistingFlight();
  //void rescheduleFlight (Flight& other)
  //void newFlight(Flight& other)
  //void changeSeat(Seat& other)


};