/* 
- Price
- Type: First Class, Business, Economy, Economy Plus
- Available 
- SeatID

*/

#include <iostream>
#include <string>
#include "Customer.h"
#pragma once

#ifndef SEAT_H
#define SEAT_H

class Seat
{
  private:
  int typeOfSeat;
  int seatNumber;
  Customer contactInfo;
  int price = 100;

  public:
  bool available = true; 
  Seat();
  Seat(int seatNum, Customer newCustomer);
  Seat(int seatNum, int typeOfSeat, Customer newCustomer);
  //Setters
  void addCustomer(Customer &newCustomer);
  void deleteCustomer();
  void setSeatType(int n);

//Getters
  Customer getCustomerInfo();

//Instance
  string printSeatInformation();
  bool isSeatAvailable();
  void reset();
  
};

#endif

