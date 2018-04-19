// ticketmanager.cpp
// Noah Tucker, Richard Stadnick, Derek Morgan and Petra Gates
// This program is where the ticketmanager class is defined
//This file needs more comments

#include "ticketmanager.h"					// include header file ticketmanager.h, by Richard S
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

						/************************
						*	Constructor	*
						************************/
TicketManager::TicketManager(){ 				//load files create 2-D array of seat structs
    seat_availability.open("./SeatAvailability.dat");		// open Seat Availability file
    char ch;
    for(int row = 0; row < ROWS; row++){			// step through rows
        for(int col = 0; col < COLS; col++){			// and columns
            seat_availability >> ch;
            if(ch == '#'){
                seats[row][col].available = true;		// set availability to true if '#'
            }else if(ch == '*'){
                seats[row][col].available = false;		// set availability to false if '*'
            }
            if(row < 4){					// loops for seat pricing tiers
                seats[row][col].price = 12.50;
            }else if(row >= 4 && row < 8){
                seats[row][col].price = 10.00;
            }else if(row >= 8 && row < 12){
                seats[row][col].price = 8.00;
            }else{
                seats[row][col].price = 5.00;
            }
            
        }
    }
}


				/************************************************************************
				*	represent seats/availability by a chart/array of * and # chars	*
				************************************************************************/
void TicketManager::displayChart(){
    cout << setw(39) << "012345678901234567890123456789\n";
    for(int row = 0; row < ROWS; row++){
        cout << setw(4) << "row " << setw(3) << row << " ";
        for(int col = 0; col < COLS; col++){
            if(seats[row][col].available)
                cout << '#';
            else{
                cout << '*';
            }
        }
        cout << '\n';
    }
}


			/********************************************************************************
			*	determine if requested seats are available and give the seating price	*
			********************************************************************************/
bool TicketManager::ticketRequest(int num_seats, int row_num, int start_seat){
    bool available = true;
    int seat = start_seat;
    if(start_seat > COLS || start_seat < 0 || (start_seat + num_seats) > COLS || row_num > ROWS || row_num < 0){
        return false;						// seat request validation
    }
    while(seat < (start_seat + num_seats) && available){	// determining availability of requested seats
        if(!seats[row_num][seat].available){
            available = false;
        }
        seat++;
    }
    return available;
}


					/****************************************************************
					*	purchase seats and update availability accordingly	*
					****************************************************************/
void TicketManager::purchase(int num_seats, int row_num, int start_seat){
    double price = get_price(num_seats, row_num, start_seat);
    if(price == 0.0){
        cout << "The seats you requested are not available." << endl;		// display seats unavailable if price evaluates to $0
    }else{
        cout << fixed << showpoint << setprecision(2);
        cout << "Your total is $" << price << endl;				// display sales total of available seats
    }
    for(int i = start_seat; i < (start_seat + num_seats); i++){			// set availability of purchased seats to false
        seats[row_num][i].available = false;
    }
}


			/************************************************************************************************
			*	 sales report method, displaying seats available/unavailable and total sales 		*
			************************************************************************************************/
void TicketManager::report(){ 					//display sales report
    int seatsAvailable = 0,					// accumulators
		seatsUnavailable = 0;
	double totalSales = 0;

	for (int row = 0; row < ROWS; row++)			// Calculating number of seats Available, Unavailable, and Total Sales
	{
		for (int col = 0; col < COLS; col++)
		{
			if (seats[row][col].available == true)
			{
				seatsAvailable++;		// add to available seats accumulator
			}
			else if (seats[row][col].available == false)
			{
				seatsUnavailable++;		// add to unavailable seats accumulator
				totalSales += seats[row][col].price;
			}
		}
	}
		
	/******** displaying sales report on number of seats available/unavailable and total sales *******/
	cout << setw(20) << left << "Seats Available" << setw(22) << left << "Seats Unavailable";
	cout << setw(10) << "Total Money Collected" << endl;
	cout << "===============================================================" << endl;
	cout << setw(20) << left << seatsAvailable << setw(22) << left << seatsUnavailable;
	cout << setprecision(2) << fixed << showpoint;
	cout << setw(10) << totalSales << endl;
}


					/************************************************
					*	getting price of requested seats	*
					************************************************/
double TicketManager::get_price(int num_seats, int row_num, int start_seat){	// calculating/retrieving
    bool available = ticketRequest(num_seats, row_num, start_seat);		// total sale price of requested seats
    double total = 0.0;
    if(!available){								// if seats unavailable, returns $0 total
        return total;
    }
    for(int i = start_seat; i < (start_seat + num_seats); i++){			// accumulating price of available requested seats
        total += seats[row_num][i].price;
    }
    return total;
}


						/************************
						*	Destructor	*
						************************/
TicketManager::~TicketManager(){ 						//write and close files
    seat_availability.close();
    output_seat.open("./SeatAvailability.dat");


    for(int row = 0; row < ROWS; row++){					// writing to SeatAvailability.dat
        for(int col = 0; col < COLS; col++){					// stepping through seats array
            if(seats[row][col].available){
                output_seat << '#';
            }else{
                output_seat << '*';
            }
        }
        output_seat << endl;
    }
    
    output_seat.close();							// close SeatAvailability.dat
}
