#include <iostream>
#include "Customer.h"
#include "Seat.h"

using namespace std;

#ifndef FLIGHT_H
#define FLIGHT_H

class Flight{
private:
	Seat * flightSeats; 
  int capacity;
  string flightID;
  int flightDuration;
  string destination;
  string aircraftType;
  int currentSeatNum;
  int spaceOnFlight = 10; 
  Customer * flightCustomers;

public:
  Flight();
  Flight(int cap, string des);
  Flight(int cap, string des, string id, int duration, string craft);
  
  void reserveSeat(int seatNum, Customer user);
  bool checkSeatAvailability(int seatNum);
  void availableSeats();
  string toString();
  string getSeatInformation(int seatNum);
  void passengerList();
  friend void bubbleSort(Customer arr[], int size);
  void deleteSeat(Customer user);

  // accessors 
  int getCapacity();
  string getID();
  string getDestination();
  string getCraft();
  int getDuration();
  int getSpaceOnFlight();
  
  // mutators
  void setDestination(string);
  void setDuration(int);

//Recursive Functions:
friend int binarySearch(Customer arr[], int length, const Customer& target);
friend int linearSearch(Customer arr[], int length, const Customer& target);
bool operator>(const Flight& other) const;
bool operator<(const Flight& other) const;
bool operator==(const Flight& other) const;

};

#endif