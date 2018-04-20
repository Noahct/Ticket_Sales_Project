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
        cout << "menu items:\n" << "1) display seats\n" << "2) request tickets\n" << "3) sales report\n" << "4) quit\n";

        //get and validate user input with a function
        cout << "Enter menu option. (1, 4) ";
        int menuItem = getInput(1, 4);

        if (menuItem == 1)  
            manager.displayChart();  //use the displayChart() method in the TicketManeger class

        if (menuItem == 2){  //ticketRequest purchase 
            //bool status = false;  //a price of -1 indicates that seats don't exist or are not available
            string mesg;
            string buy;
            double payment;
            while (true){
                cout << "How many seat would you like to buy? (0, 30) ";
                int numseats = getInput(0, 30);
                cout << "Enter a row number. (0, 15) ";
                int row = getInput(0, 15);
                cout << "Enter the index of the leftmost seat. (0, 30) ";
                int startseat = getInput(0, 30);
                if (manager.ticketRequest(numseats, row, startseat)){  //do seats exist and are they available
                    double price = 20.00;//manager.getPrice();  //get the price of the requested seats
                    cout << "These seats will cost $" << price << '\n';
                    cout << "Would you like to buy these seats?" << '\n';
                    cin >> buy;
                    if (buy == "y" or buy == "yes"){  
                        do{ //get input until user provides enough money to buy seats
                            cout << "Enter your payment. If you want to reconsider enter -1. ";
                            payment = getInput(0, price);
                            if (payment == price){
                                cout << "purchased\n"; //manager.purchase(payment);  //purchase seats
                                break;
                            }
                        }while (payment != -1);
                    }else{
                        cout << "You entered seats that do not exist or have already been sold." << '\n';
                        break;
                    }
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
