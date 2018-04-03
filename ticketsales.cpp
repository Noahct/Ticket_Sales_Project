// Group Project
// ticketsales.cpp
// Noah Tucker 
// some description


#include "ticketmaneger.h"
#include <iostream>
#include <string>
using namespace std;

int getInput(int, int);  //declare getInput func

int main(){
    //create var of type TicketManeger
    TicketManeger manager();  //will not work until class constructor hes been created

    while (true){
        //display menu of options with cout
        cout << "menu items:\n" << "1) display seats\n" << "2) request tickets\n" << "3) sales report\n" << "4) quit\n";

        //get and validate user input with a function
        menuItem = getInput(1, 4);

        if (menuItem == 1)  
            manager.displayChart();  //use the displayChart() method in the TicketManeger class

        if (menuItem == 2){  //ticketRequest purchase 
            bool status = false;  //do seats exist and are they available
            string mesg;
            while (true){
                int numseats = getInput(0, 30);
                int row = getInput(0, 15);
                int startseat = getInput(0, 30);
                mesg, status = manager.ticketRequest(numseats, row, startseat);
                cout << mesg << '\n';
                if (not status)
                    cout << "Would you like to buy these seats?" << '\n';
                    cin >> buy;
                    if (buy == "y" or buy == "yes"){
                        do{ //get input until user provides enough money to buy seats
                            double money = getInput();
                        }while (not manager.purchase(money));
                    }else{
                        break;
                }
            }
        }

        if (menuItem == 3)  
            manager.report()  //get sales report 

        if (menuItem == 4)
            return 0;
	}
}

int getInput(int min, int max){
    do{
        cout << "Enter a number between " << min << " and " << max << '\n';
        cin >> input;
    }while (input > max or input < min);
    
    return input;
}