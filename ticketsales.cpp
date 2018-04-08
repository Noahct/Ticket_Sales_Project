// Group Project
// ticketsales.cpp
// Noah Tucker and 
// This program will


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
  
 // View Price member function
void TicketManager::viewPrice()
{
	for (int row = 0; row < 15; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			cout << theater[row][col].cost<< " ";
		}

		cout << endl;
	}
}
