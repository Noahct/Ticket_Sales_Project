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
    TicketManeger manager;  //will not work until class constructor hes been created

    while (true){
        //display menu of options with cout
        cout << "menu items:\n" << "1) display seats\n" << "2) request tickets\n" << "3) sales report\n" << "4) quit\n";

        //get and validate user input with a function
        int menuItem = getInput(1, 4);

        if (menuItem == 1)  
            manager.displayChart();  //use the displayChart() method in the TicketManeger class

        if (menuItem == 2){  //ticketRequest purchase 
            //bool status = false;  //do seats exist and are they available
            string mesg;
            string buy;
            double money;
            while (true){
                int numseats = getInput(0, 30);
                int row = getInput(0, 15);
                int startseat = getInput(0, 30);
                double price = manager.ticketRequest(numseats, row, startseat);
                if (price != -1){  //a price of -1 indicates that seats don't exist or are not available
                    cout << "good message" << '\n';
                    cout << "Would you like to buy these seats?" << '\n';
                    cin >> buy;
                    if (buy == "y" or buy == "yes"){
                        do{ //get input until user provides enough money to buy seats
                            money = getInput(0, price);
                        }while (not manager.purchase(money));
                    }else{
                        cout << "bad message" << '\n';
                        break;
                    }
                }
            }
        }

        if (menuItem == 3)  
            manager.report()  //display a sales report 

        if (menuItem == 4)  //quit the program
            return 0;
	}
}

int getInput(int min, int max){
    int input;
    do{
        cout << "Enter a number between " << min << " and " << max << '\n';
        cin >> input;
    }while (input > max or input < min);
    
    return input;
}
