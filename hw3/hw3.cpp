/*****************************************************
**hw3.cpp
**Tic Tac Toe Game
**Patrick Xie, (01/29/2010)
*****************************************************/

#include "ccc_win.h"
int ccc_win_main() {

	//string userResponse = cwin.get_string ("Would you like to play? (y/n): ");
	string userResponse = "y"; //Assigning the intial variable to start the game
	while (userResponse == "y" || userResponse == "Y") { //1st loop with conditions to start game

		//tic tac toe grid outline
		Line outline1 (Point(9,-3), Point(-9,-3));
		Line outline2 (Point(9,3), Point(-9,3));
		Line outline3 (Point(-3,9), Point(-3,-9));
		Line outline4 (Point(3,9), Point(3,-9));
		cwin << outline1 << outline2 << outline3 << outline4;
			
		int turnNumber = 1;
			while (turnNumber <= 9){ /*Second loop to repeat the alternating X's and O's
										only 5 X's and 4 O's should display.*/

				if (turnNumber %2 != 0){ /*if even then divide by 2 
											should be zero, if not then is odd number*/
					//Creates X's in the game
					Point mouseClick = cwin.get_mouse ("X's Turn");
					Line rightLine (Point(mouseClick.get_x()-2,mouseClick.get_y()-2),
									Point(mouseClick.get_x()+2,mouseClick.get_y()+2));
					Line leftLine (Point (mouseClick.get_x()+2,mouseClick.get_y()-2),
									Point(mouseClick.get_x()-2,mouseClick.get_y()+2));
					cwin << rightLine << leftLine;
					turnNumber++; /*increases the turn count so when more than 
									9 then this while statement will stop*/
				}
				else { //if odd then it is O's turn
					//creates O's in the game
					Point mouseClick2 = cwin.get_mouse ("O's Turn");
					cwin << Circle (Point(mouseClick2), 2);
					turnNumber++; /*increases the turn count so when turnNumber 
									is greater than 9, this while statement will stop*/
				}
			}
		//asking the user to play again and loop the game again
		userResponse = cwin.get_string ("Play again? (y/n): ");
		cwin.clear();
	}	
	cwin.clear();
	return 0;
}