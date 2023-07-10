#include <iostream>
#include "Customer.h"
#include "Seat.h"
#include <string>
#include <sstream>
#pragma once
using namespace std;

Seat::Seat(){
    seatNumber = -1;
  }
Seat::Seat(int num, Customer newCustomer){
  seatNumber = num;
  contactInfo = newCustomer;
  available = false;
}
Seat::Seat(int num, int type, Customer newCustomer){
  seatNumber = num;
  typeOfSeat = type;
  contactInfo = newCustomer;
  available = false;
}

void Seat::addCustomer(Customer &newCustomer){
    contactInfo = newCustomer;
    available = false;
}

// void Seat::deleteCustomer(){
//     contactInfo = NULL;
       //available = true; 
// }

void Seat::setSeatType(int n){
  typeOfSeat = n;
  if (n == 1){
    price = 150;
  }
  else if (n == 2){
    price = 300;
  }
  else if (n == 3){
    price = 500;
  }
  else{
    price = 100;
  }
}

Customer Seat::getCustomerInfo(){
  return contactInfo;
}

string Seat::printSeatInformation(){
    string seatType;
    if (typeOfSeat == 1){
      seatType = "Economy Plus ";
    }
    else if (typeOfSeat == 2){
      seatType = "Business Class";
    }
    else if (typeOfSeat == 3){
      seatType = "First Class";
    }
    else{
      seatType = "Economy";
    }
		ostringstream s1;
		s1 << "Seat Information:\n"<< "\tSeat Number: "<<to_string(seatNumber)<<"\n\tClass: "<<seatType<<"\n\tPrice: "<<to_string(price);
    ostringstream s2;
    s2<<"\n\n"<<contactInfo.toString();
		string s3 = s1.str() + s2.str();
		return s3;

	}

void Seat::reset(){
  contactInfo.reset();
}



