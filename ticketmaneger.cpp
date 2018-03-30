//
// ticketmaneger.cpp
// Noah Tucker
// This program will determine lots of random things


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "ticketmaneger.h"
using namespace std;

class TicketManeger{
    private:
    
    public:
    TicketManeger //load files create 2-D array of seat structs
	string displayChart  //represent seats by a chart of * and # chars
	double ticketRequest //determine if requested seats are available and give the seating price
	void purchase //purchase seats update date accordingly
	void report //display sales report from salesReport.dat
	~TicketManeger //write and close files


}