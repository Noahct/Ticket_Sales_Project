// ticketmanager.cpp
// Noah Tucker, Richard Stadnick, Derek Morgan and Petra Gates
// This program is where the ticketmanager class is defined
//This file needs more comments

#include "ticketmanager.h"					// include header file ticketmanager.h, by Richard S

						/********************************
						*	Constructor	* Rich Stadnick *
						********************************/
TicketManager::TicketManager(){ 				//load files create 2-D array of seat structs
    seat_availability.open("./SeatAvailability.dat");		// open Seat Availability file
    prices.open("./SeatPrices.dat");// Open SeatPrices file
    char ch;
    double price_array[ROWS];// Create an array to hold the price information
    for(int i = 0; i < ROWS; i++){
        prices >> price_array[i];// fill the price array
    }
    for(int row = 0; row < ROWS; row++){			// step through rows
        for(int col = 0; col < COLS; col++){			// and columns
            seat_availability >> ch;
            if(ch == '#'){
                seats[row][col].available = true;		// set availability to true if '#'
                seats[row][col].price = price_array[row];// Assign price to row
            }else if(ch == '*'){
                seats[row][col].available = false;		// set availability to false if '*'
                seats[row][col].price = price_array[row];// Assign pricec to row
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
            *	Rich Stadnick                                                           *
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
                    *	Rich Stadnick                                       *
					****************************************************************/
void TicketManager::purchase(int num_seats, int row_num, int start_seat){
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
                    *	Rich Stadnick                       *
					************************************************/
double TicketManager::get_price(int num_seats, int row_num, int start_seat){	// calculating/retrieving
    double total = 0.0;
    for(int i = start_seat; i < (start_seat + num_seats); i++){			// accumulating price of available requested seats
        total += seats[row_num][i].price;
    }
    return total;
}


						/************************
						*	Destructor	        *
                        *	Rich Stadnick       *
						************************/
TicketManager::~TicketManager(){ 						//write and close files
    seat_availability.close();
    prices.close();
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
