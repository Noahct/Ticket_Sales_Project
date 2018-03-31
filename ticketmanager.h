// ticketmanager.h
// Noah Tucker
// This program will
// This is start of the header guard.  ticketmanager_h can be any unique name.  By convention, you use the name of the header file.
#ifndef ticketmanager_h
#define ticketmanager_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
// This is the content of the .h file, which is where the declarations go
class TicketManager{
    private:
    
    public:
    TicketManager(); //load files create 2-D array of seat structs
	string displayChart();  //represent seats by a chart of * and # chars
	double ticketRequest(); //determine if requested seats are available and give the seating price
	void purchase(); //purchase seats update date accordingly
	void report(); //display sales report from salesReport.dat
	~TicketManager(); //write and close files

};
// This is the end of the header guard
#endif
