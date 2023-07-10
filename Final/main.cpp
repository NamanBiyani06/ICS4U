#include <iostream>
#include <ncurses.h>
#include <string>
#include "Customer.h"
#include "User.h"
#include "Flight.h"
#include "Seat.h"
#include <unistd.h> // For usleep function


void splitCharacterArray(const char* charArray, std::string& firstString, std::string& secondString) {
    std::string_view inputString(charArray);
    size_t spaceIndex = inputString.find(' ');

    if (spaceIndex != std::string::npos) {
        firstString = std::string(inputString.substr(0, spaceIndex));
        secondString = std::string(inputString.substr(spaceIndex + 1));
    } else {
        // If no space found, assign the entire input to the first string
        firstString = std::string(inputString);
        secondString = "";
    }
}

int findCustomerIndex(Customer arr[], int size, string firstName, string lastName) {
    for (int i = 0; i < size; i++) {
        if (arr[i].getFirstName() == firstName && arr[i].getLastName() == lastName) {
            return i; // Found the customer, return the index
        }
    }
    return -1; // Customer not found
}

int findFlightIndex(Flight arr[], int size, string destination) {
    for (int i = 0; i < size; i++) {
        if (arr[i].getDestination() == destination) {
            return i; // Found the flight, return the index
        }
    }
    return -1; // Flight not found
}

int numberOfCustomers = 0;
int numberOfFlight = 0;

Customer *hashMapCustomers = new Customer[1000];
Flight *hashMapFlights = new Flight[10];

int main() {
    initscr(); // Initialize ncurses
    cbreak(); // Disable line buffering
    noecho(); // Don't display input characters
    keypad(stdscr, TRUE); 

    // Set up colors
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK); // Color for text
    init_pair(2, COLOR_BLACK, COLOR_WHITE); // Color for selected option
    init_pair(3, COLOR_RED, COLOR_BLACK); // Color for menu bar

    // Get screen dimensions
    int screen_height, screen_width;
    getmaxyx(stdscr, screen_height, screen_width);

    while (true) {
        clear(); // Clear the screen

        // Create the main window
        WINDOW* main_win = newwin(screen_height - 2, screen_width - 2, 1, 1);
        wbkgd(main_win, COLOR_PAIR(1));
        box(main_win, 0, 0); // Draw a box around the window

        // Create the navigation bar
        WINDOW* nav_bar = newwin(1, screen_width - 2, 1, 1);
        wbkgd(nav_bar, COLOR_PAIR(3));
        mvwprintw(nav_bar, 0, 0, " [ X ]"); // Red 'X' symbol
        wrefresh(nav_bar);

        // Display the header
        std::string header = "Airline Management System";
        int header_x = (screen_width - header.length()) / 2;
        mvwprintw(main_win, 1, header_x, header.c_str());

        // Display the options
        std::string options[] = {
            "1. Create new customer",
            "2. Add Flight",
            "3. Reserve seat for customer",
            "4. Remove customer from seat",
            "5. View all flights",
            "6. View customer information",
            "7. Exit program"
        };
        int num_options = sizeof(options) / sizeof(options[0]);
        int start_y = (screen_height - num_options) / 2;

        for (int i = 0; i < num_options; ++i) {
            if (i == 0) {
                wattron(main_win, A_STANDOUT); // Highlight the first option
            }
            mvwprintw(main_win, start_y + i, (screen_width - options[i].length()) / 2, options[i].c_str());
            wattroff(main_win, A_STANDOUT);
        }

        // Refresh the windows
        wrefresh(main_win);
        wrefresh(nav_bar);

        // Wait for user input
        int choice = wgetch(main_win) - '0'; 
        // Perform action based on user input
        switch (choice) {
            case 1: {
                // Create new customer
                char name[100], address[100], phone[100];
                int age;

                clear(); // Clear the screen

                // Create the input window
                WINDOW* input_win = newwin(8, 40, (screen_height - 8) / 2, (screen_width - 40) / 2);
                wbkgd(input_win, COLOR_PAIR(1));
                box(input_win, 0, 0); // Draw a box around the window

                // Get customer details from the user
                mvwprintw(input_win, 1, 1, "Enter customer details:");
                mvwprintw(input_win, 3, 1, "Name: ");
                echo(); // Enable echoing of input characters
                wgetstr(input_win, name);
                noecho(); // Disable echoing of input characters
                mvwprintw(input_win, 4, 1, "Age: ");
                echo();
                wscanw(input_win, "%d", &age);
                noecho();
                mvwprintw(input_win, 5, 1, "Address: ");
                echo();
                wgetstr(input_win, address);
                noecho();
                mvwprintw(input_win, 6, 1, "Phone: ");
                echo();
                wgetstr(input_win, phone);
                noecho();
                string f,l;
                splitCharacterArray(name,f,l);

                // Create the customer object
                hashMapCustomers[numberOfCustomers] = Customer(f,l, age, address, phone);
                string fullName = hashMapCustomers[numberOfCustomers].getFirstName() + " " + hashMapCustomers[numberOfCustomers].getLastName();

                // Display the created customer
                clear(); // Clear the screen
                mvprintw(10, 1, "New customer created:");
                mvprintw(12, 1, "Name: %s", fullName.c_str());
                mvprintw(13, 1, "Age: %d", hashMapCustomers[numberOfCustomers].getAge());
                mvprintw(14, 1, "Address: %s", hashMapCustomers[numberOfCustomers].getAddress().c_str());
                mvprintw(15, 1, "Phone: %s", hashMapCustomers[numberOfCustomers].getPhone().c_str());
                numberOfCustomers++;
                // Wait for user input to continue
                mvprintw(screen_height - 3, 1, "Press any key to continue...");
                getch();
                break;
            }
            case 2: {
                clear(); // Clear the screen
                      // Create the input window
                WINDOW* input_win = newwin(8, 40, (screen_height - 8) / 2, (screen_width - 40) / 2);
                wbkgd(input_win, COLOR_PAIR(1));
                box(input_win, 0, 0); // Draw a box around the window

                // Get flight details from the user
                mvwprintw(input_win, 1, 1, "Enter flight details:");
                mvwprintw(input_win, 3, 1, "Duration: ");
                int duration;
                echo();
                wscanw(input_win, "%d", &duration);
                noecho();
                mvwprintw(input_win, 4, 1, "Destination: ");
                char destination[100];
                echo();
                wgetstr(input_win, destination);
                noecho();
                mvwprintw(input_win, 5, 1, "ID: ");
                char id[100];
                echo();
                wgetstr(input_win, id);
                noecho();
                mvwprintw(input_win, 6, 1, "Aircraft Model: ");
                char aircraft_model[100];
                echo();
                wgetstr(input_win, aircraft_model);
                noecho();
                hashMapFlights[numberOfFlight] = Flight(10,destination,id,duration,aircraft_model);
                // Display the entered flight details
                clear(); // Clear the screen
                mvprintw(10, 1, "Flight Details:");
                mvprintw(12, 1, "Duration: %d", hashMapFlights[numberOfFlight].getDuration());
                mvprintw(13, 1, "Destination: %s", hashMapFlights[numberOfFlight].getDestination().c_str());
                mvprintw(14, 1, "ID: %s", hashMapFlights[numberOfFlight].getID().c_str());
                mvprintw(15, 1, "Aircraft Model: %s", hashMapFlights[numberOfFlight].getCraft().c_str());
                numberOfFlight++;
                // Wait for user input to continue
                mvprintw(screen_height - 3, 1, "Press any key to continue...");
                getch();

        break;
            }
            case 3:{
  

              char firstName[100], lastName[100], destination [100];
              int seatNumber;
              int indexOfCustomer;
              int indexOfFlight;

              // clear(); // Clear the screen

              // Create the input window
              // WINDOW* input_win = newwin(8, 40, (screen_height - 8) / 2, (screen_width - 40) / 2);
              // wbkgd(input_win, COLOR_PAIR(1));
              // box(input_win, 0, 0); // Draw a box around the window

              // Get customer details from the user
              bool validInput = false;
              while (!validInput) {
                              clear(); // Clear the screen

                WINDOW* input_win = newwin(8, 40, (screen_height - 8) / 2, (screen_width - 40) / 2);
                wbkgd(input_win, COLOR_PAIR(1));
                box(input_win, 0, 0); // Draw a box around the window
                  mvwprintw(input_win, 1, 1, "Enter customer details:");
                  mvwprintw(input_win, 3, 1, "First Name: ");
                  echo(); // Enable echoing of input characters
                  wgetstr(input_win, firstName);
                  noecho(); // Disable echoing of input characters

                  mvwprintw(input_win, 4, 1, "Last Name: ");
                  echo();
                  wgetstr(input_win, lastName);
                  noecho();

                  mvwprintw(input_win, 5, 1, "Destination: ");
                  echo();
                  wgetstr(input_win, destination);
                  noecho();
                 indexOfCustomer = findCustomerIndex(hashMapCustomers,numberOfCustomers,firstName,lastName);
                 indexOfFlight = findFlightIndex(hashMapFlights,numberOfFlight,destination);


                  // Validate customer details
                  // Replace the condition below with your own logic to check if the first and last name are registered
                  if (indexOfCustomer == -1 || indexOfFlight == -1) {
                      // Invalid input, shake the visual
                      // clear(); // Clear the screen
                      // // Shake the visual by changing the color temporarily
                      // wbkgd(input_win, COLOR_PAIR(2));
                      // box(input_win, 0, 0);
                      // mvwprintw(input_win, 1, 1, "Enter details:");
                      // mvwprintw(input_win, 3, 1, "First Name: ");
                      // mvwprintw(input_win, 4, 1, "Last Name: ");
                      // mvwprintw(input_win, 5, 1, "Destination: ");
                      // wbkgd(input_win, COLOR_PAIR(1));
                      // box(input_win, 0, 0);
                      // wrefresh(input_win);
                      usleep(100000); // Pause for a short duration (100ms) to create the shaking effect
                      clear(); // Clear the screen
                      validInput = false;
                  } else {
                      validInput = true;
                  }
              }

              clear(); // Clear the screen
                char charArray[10];

                sprintf(charArray, "%d", hashMapFlights[indexOfFlight].getSpaceOnFlight());

                // Display seat availability
                mvprintw(1, 1, ("There are " + string(charArray) + " seats available on the flight at this moment").c_str());
                mvprintw(3, 1, "These seats are unreserved at the moment:");

                // Display the unreserved seat numbers
                    int availableSeatsCount = 0;
                    for (int i = 0; i < 10; i++) {
                        if (hashMapFlights[indexOfFlight].checkSeatAvailability(i)) {
                            mvprintw(i + 5, 1, "Seat %d", i);
                            availableSeatsCount++;
                        }
                        else{
                            mvprintw(i + 5, 1, "   X  ");
                        }
                    }



                seatNumber = -1;
                bool validSeat = false;
                while (!validSeat) {
                    mvprintw(screen_height - 3, 1, "Please enter the seat number you would like to book: ");
                    // Read the seat number input from the user
                    scanw("%d", &seatNumber);
                    // Validate the seat number
                    if (seatNumber >= 0 && seatNumber < 10) {
                        validSeat = true;
                    } else {
                        clear(); // Clear the screen
                        mvprintw(6, 1, "Invalid seat number. Please try again.");
                        getch();
                        validSeat = false;
                    }
                }

                clear(); // Clear the screen
                hashMapFlights[indexOfFlight].reserveSeat(seatNumber,hashMapCustomers[indexOfCustomer]);


                // Display seat and customer information
                mvprintw(1, 1, "Seat Information:");
                mvprintw(3, 1, "Seat Number: %d", seatNumber);
                mvprintw(4, 1, "Class:"); // Replace with actual class information
                mvprintw(5, 1, "Price:"); // Replace with actual price information

                mvprintw(1, 40, "Customer Information:");
                mvprintw(3, 40, "Name: %s %s", hashMapCustomers[indexOfCustomer].getFirstName().c_str(), hashMapCustomers[indexOfCustomer].getLastName().c_str());
                mvprintw(4, 40, "Address: %s", hashMapCustomers[indexOfCustomer].getAddress().c_str()); // Replace with actual address information
                mvprintw(5, 40, "Age: %d", hashMapCustomers[indexOfCustomer].getAge()); // Replace with actual age information
                mvprintw(6, 40, "Phone Number: %s", hashMapCustomers[indexOfCustomer].getPhone().c_str()); // Replace with actual phone number information
                mvprintw(7, 40, "Passport ID: %s", hashMapCustomers[indexOfCustomer].getID().c_str()); // Replace with actual passport ID information
                mvprintw(8, 40, "Meal Plan: Vegetarian"); // Replace with actual meal plan information

                // Wait for user input to continue
                mvprintw(screen_height - 3, 1, "Press any key to continue...");
                getch();
                break;
            }
            case 4:
            {

              char firstName[100], lastName[100], destination [100];
              int seatNumber;
              int indexOfCustomer;
              int indexOfFlight;

              // clear(); // Clear the screen

              // Create the input window
              // WINDOW* input_win = newwin(8, 40, (screen_height - 8) / 2, (screen_width - 40) / 2);
              // wbkgd(input_win, COLOR_PAIR(1));
              // box(input_win, 0, 0); // Draw a box around the window

              // Get customer details from the user
              bool validInput = false;
              while (!validInput) {
                              clear(); // Clear the screen

                WINDOW* input_win = newwin(8, 40, (screen_height - 8) / 2, (screen_width - 40) / 2);
                wbkgd(input_win, COLOR_PAIR(1));
                box(input_win, 0, 0); // Draw a box around the window
                  mvwprintw(input_win, 1, 1, "Enter customer details:");
                  mvwprintw(input_win, 3, 1, "First Name: ");
                  echo(); // Enable echoing of input characters
                  wgetstr(input_win, firstName);
                  noecho(); // Disable echoing of input characters

                  mvwprintw(input_win, 4, 1, "Last Name: ");
                  echo();
                  wgetstr(input_win, lastName);
                  noecho();

                  mvwprintw(input_win, 5, 1, "Destination: ");
                  echo();
                  wgetstr(input_win, destination);
                  noecho();
                 indexOfCustomer = findCustomerIndex(hashMapCustomers,numberOfCustomers,firstName,lastName);
                 indexOfFlight = findFlightIndex(hashMapFlights,numberOfFlight,destination);


                  // Validate customer details
                  // Replace the condition below with your own logic to check if the first and last name are registered
                  if (indexOfCustomer == -1 || indexOfFlight == -1) {
                      usleep(100000); // Pause for a short duration (100ms) to create the shaking effect
                      clear(); // Clear the screen
                      validInput = false;
                  } else {
                      validInput = true;
                  }
              }

                clear(); // Clear the screen
                hashMapFlights[indexOfFlight].deleteSeat(hashMapCustomers[indexOfCustomer]);

                clear(); // Clear the screen

                // Display seat and customer information
                mvprintw(1, 1, "Seat Has Been Deleted:");


                mvprintw(1, 40, "Customer Information:");
                mvprintw(3, 40, "Name: %s %s", hashMapCustomers[indexOfCustomer].getFirstName().c_str(), hashMapCustomers[indexOfCustomer].getLastName().c_str());
                mvprintw(4, 40, "Address: %s", hashMapCustomers[indexOfCustomer].getAddress().c_str()); // Replace with actual address information
                mvprintw(5, 40, "Age: %d", hashMapCustomers[indexOfCustomer].getAge()); // Replace with actual age information
                mvprintw(6, 40, "Phone Number: %s", hashMapCustomers[indexOfCustomer].getPhone().c_str()); // Replace with actual phone number information
                mvprintw(7, 40, "Passport ID: %s", hashMapCustomers[indexOfCustomer].getID().c_str()); // Replace with actual passport ID information
                mvprintw(8, 40, "Meal Plan: Vegetarian"); // Replace with actual meal plan information

                // Wait for user input to continue
                mvprintw(screen_height - 3, 1, "Press any key to continue...");
                getch();
                break;
            }
            case 5:
            {
                clear(); // Clear the screen

        // Display all flights
        mvprintw(1, 1, "Flights in the System:");
        
        for (int i = 0; i < numberOfFlight; i++) {
            mvprintw((i + 3) + (15 * i), 1, "<----------------------------->");
            mvprintw((i + 6)  + (15 * i), 1, "Flight ID: %s", hashMapFlights[i].getID().c_str());
            mvprintw((i + 9) + (15 * i), 1, "Destination: %s", hashMapFlights[i].getDestination().c_str());
            mvprintw((i + 12) + (15 * i), 1, "Duration: %d", hashMapFlights[i].getDuration());
            mvprintw((i + 15) + (15 * i), 1, "<----------------------------->");
        }
        
        // Prompt the user to continue
        mvprintw(screen_height - 3, 1, "Press any key to continue...");
        getch();
        
        break;
            }
            case 6:{
                // print out all customer information using the customer hashmap
                clear(); // Clear the screen
                mvprintw(1, 1, "Customer Information:");
                for (int i = 0; i < numberOfCustomers; i++) {
                    mvprintw(3,(i + 3) + (i * 25), "Customer %d", i+1);
                    mvprintw(4,(i + 3) + (i * 25), "Name: %s %s", hashMapCustomers[i].getFirstName().c_str(), hashMapCustomers[i].getLastName().c_str());
                    mvprintw(5,(i + 3) + (i * 25), "Address:%s ",hashMapCustomers[i].getAddress().c_str()); // Replace with actual address information
                    mvprintw(6,(i + 3) + (i * 25), "Age:%d ",hashMapCustomers[i].getAge()); // Replace with actual age information
                    mvprintw(7,(i + 3) + (i * 25), "Phone Number:%s ",hashMapCustomers[i].getPhone().c_str()); // Replace with actual phone number information
                    mvprintw(8,(i + 3) + (i * 25), "Passport ID:%s ",hashMapCustomers[i].getID().c_str()); // Replace with actual passport ID information
                }
                mvprintw(screen_height - 3, 1, "Press any key to continue...");
                getch();
                break;
            }
            case 7:
                endwin(); // End ncurses
                return 0;
        }
    }

    endwin(); // End ncurses
    return 0;
}
