// Group Project
// ticketsales.cpp
// Noah Tucker 
// some description


#include "ticketmanager.h"
#include <iostream>
#include <string>
using namespace std;

double getInput(double, double);  //declare getInput func

int main(){
    //create var of type TicketManeger
    TicketManager manager;  //will not work until class constructor hes been created
    
    //loop until quits program
    while (true){
        //display menu of options with cout
        cout << "menu items:\n" << "1) display seats\n" << "2) request tickets\n" << "3) sales report\n" << "4) reset data\n" << "5) quit\n";

        //get and validate user input with a function
        cout << "Enter menu option. ";
        int menuItem = getInput(1, 5);

        if (menuItem == 1)  
            //display a chart of seating a '#' represents available seats a '*' represents unavailable seats
            manager.displayChart();  

        if (menuItem == 2){  //request and buy seats
            //string mesg;  
            string buy;  //holds a string that determines if a user wants to buy certain seats
            bool puchased = false;  //determines whether seats have been purchased yet
            double payment;  //holds the users payment
            while (not puchased){
                cout << "How many seat would you like to buy? (0, 30) ";
                int numseats = getInput(0, 30);
                cout << "Enter a row number. (0, 15) ";
                int row = getInput(0, 15) - 1;
                cout << "Enter the index of the leftmost seat. (0, 30) ";
                int startseat = getInput(0, 30) - 1;
                if (manager.ticketRequest(numseats, row, startseat)){  //do seats exist and are they available
                    double price = manager.get_price(numseats, row, startseat);  //get the price of the requested seats
                    cout << "These seats will cost $" << price << '\n';
                    cout << "Would you like to buy these seats?" << '\n';
                    cin >> buy;
                    if (buy == "y" or buy == "yes"){  
                        do{ //get input until user provides enough money to buy seats
                            cout << "Enter your payment. If you want to reconsider enter -1. ";
                            payment = getInput(0, price);
                            if (payment == price){
                                manager.purchase(numseats, row, startseat); //cout << "purchased\n";  //purchase seats
                                puchased = true;
                                break;
                            }
                        }while (payment != -1);  //a payment of -1 indicates the has changed his mind
                    }else{
                        cout << "Buy different seating? ";
                        cin >> buy;
                        if (buy != "y" or buy != "yes")
                            break;
                    }
                }else{
                    cout << "You entered seats that do not exist or have already been sold." << '\n';
                }
            }
        }

        if (menuItem == 3)  
            manager.report();  //display a sales report 

        if (menuItem == 4)  //quit the program
            return 0;
	}
}

double getInput(double min, double max){
    double input;
    do{
        cout << "Enter a number between " << min << " and " << max << '\n';
        cin >> input;
    }while (input > max or input < min);
    
    return input;
}
