/*******************************************************************
* tictactoe.cpp
* Plays Tic-Tac-Toe game.  Only draws board, does not decide winner.
* For PIC 10A HW3.  This version uses functions.
* Note that every function is commented.
*
* Todd Wittman, 10/20/08
*******************************************************************/

#include "ccc_win.h"

//Declare functions.
void DrawGrid( );
Point getClickX();
Point getClickO();
void DrawX (Point p);
void DrawO (Point p);

/*****************************************************************
* DrawGrid: Draws the tic-tac-toe grid on the screen.
* Parameters: none
* Returns nothing.
******************************************************************/
void DrawGrid( ) {
	cwin.coord(-0.5,3.5,3.5,-0.5);
	cwin << Line( Point(0,2),Point(3,2) )
		 << Line( Point(0,1),Point(3,1) )
		 << Line( Point(1,0),Point(1,3) )
		 << Line( Point(2,0),Point(2,3) );
	return;
}


/*****************************************************************
* getClickX: Prompts the user to click on position of X.
* Parameters: none
* Returns Point indicating center of X.
******************************************************************/
Point getClickX() {
	return cwin.get_mouse("Click for X.");
}


/*****************************************************************
* getClickO: Prompts the user to click on position of O.
* Parameters: none
* Returns Point indicating center of O.
******************************************************************/
Point getClickO() {
	return cwin.get_mouse("Click for O.");
}


/*****************************************************************
* DrawX: Draws an X on the screen at the specified point.
* Parameters: Point p indicating center of X
* Returns nothing.
******************************************************************/
void DrawX (Point p) {
	const double Xwidth = 0.4;
	cwin << Line (Point(p.get_x()-Xwidth,p.get_y()+Xwidth)
		         ,Point(p.get_x()+Xwidth,p.get_y()-Xwidth))
         << Line (Point(p.get_x()-Xwidth,p.get_y()-Xwidth)
		         ,Point(p.get_x()+Xwidth,p.get_y()+Xwidth));
	return;
}


/*****************************************************************
* DrawO: Draws an O on the screen at the specified point.
* Parameters: Point p indicating center of O
* Returns nothing.
******************************************************************/
void DrawO (Point p) {
	const double Oradius = 0.4;
	cwin << Circle (p, Oradius);
	return;
}


/******************************************************************
* main
* See how crisp and clean our main routine is when we use functions?
********************************************************************/
int ccc_win_main ( ) {
	string response = "y";  //User response y/n if they want to play game again.
	int turn;    //Tracks the turn number.  Takes values 1-9.
	while ( response == "y" || response == "Y")  {
		DrawGrid ( );
		turn = 1;
		while ( turn <= 9)  {
			if (turn%2 == 1) {
				DrawX ( getClickX( ) );
			}
			else {
				DrawO ( getClickO( ) );
			}
			turn++;
		}
		response = cwin.get_string ( "Do you want to play again? (y/n)" );
		cwin.clear( );
	}
	return 0;
}
