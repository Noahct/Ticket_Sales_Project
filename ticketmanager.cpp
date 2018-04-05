// ticketmanager.cpp
// Noah Tucker, Richard Stadnick, and
// This program will determine lots of random things

#include "ticketmanager.h"

TicketManager::TicketManager(){ //load files create 2-D array of seat structs
    struct Seat{
        double price;
        bool available;
    };
    ifstream seat_availability;
    seat_availability.open("./SeatAvailability.dat");
    Seat seats[ROWS][COLS];
    char ch;
    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLS; col++){
            seat_availability >> ch;
            if(ch == '#'){
                seats[row][col].available = true;
            }else if(ch == '*'){
                seats[row][col].available = false;
            }
            if(row < 4){
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

string TicketManager::displayChart(){  //represent seats by a chart of * and # chars

}

double TicketManager::ticketRequest(){ //determine if requested seats are available and give the seating price

}
void TicketManager::purchase(){ //purchase seats update date accordingly

}

void TicketManager::report(){ //display sales report from salesReport.dat

}

TicketManager::~TicketManager(){ //write and close files

}

