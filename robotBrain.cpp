/* 
	Virtual Robot Brain
	Author: Katherine Sandoval
	Date: 10/14/2013
	Contact: kate_sandoval27@hotmail.com
    Description: This program has an improvement to only allow 
	technicians to load different scripts into the robot’s brain; 
	It prompts the technician for a file name, then the code reads 
	that file’s contents into the actions array, then executes the 
	commands found in the array. The commands are often called a script. 
*/

#include "windows.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

void motor(int);

/* Global variables */
// Command/script codes
const int BEEP = -1; 
const int TURN_LEFT = 0; 
const int STOP = 1; 
const int START = 2;
const int FORWARD = 3;	 // move forward N steps
const int GOTO_STEP = 4; // action to jump back to. Infinite loops
const int TURN_RIGHT = 5; 
const int MOVE_STEPS = 6;
const int WAIT_SECONDS = 7;
const int QUIT = 99; 

string fileName;
string line;
int counter = 0;
int actions[100];
int step = 0; // Start robot’s script at step zero

int main()
{
	/* Import File:  It reads a list of numbers from the txt file  */
	cout << "Enter file name (.txt)" << endl;
	cin >> fileName;
	
	ifstream filein( fileName.c_str() );
	
	if ( ! filein.good() )
		cout << "File not found!! \n" << endl;
	else
		while( filein.good() )
		{
			getline(filein, line);
			step = atoi( line.c_str() );
			actions[counter] = step;
			counter++;
		}

	for (int i = 0; i < counter; i++)
	{
		switch ( actions[i] ) // Actions that the Virtual Robot can take. 
		{
			case START:						//command
				cout << "START \n" << endl; // action
				break;
            
			case TURN_LEFT:						// command
				cout << "TURN LEFT \n" << endl; // action
				break;

			case TURN_RIGHT:					 // command
				cout << "TURN RIGHT \n" << endl; // action
				break;
            
			case MOVE_STEPS:										 // command
				cout << "MOVE " << actions[++i] << " STEPS" << endl; // action
				motor( actions[i] ); 
				cout << endl;
				break;
	
			case WAIT_SECONDS:											  // command
				cout << "WAIT " << actions[++i] << " SECONDS \n" << endl; // action
				Sleep(actions[i] * 1000); 
				break;
            
			case GOTO_STEP:					  // command
				i = actions[++i];
				cout << "goto " << i << endl; // action
				break;

			case FORWARD:												//command
				cout << "FORWARD " << actions[++i] << " STEPS" << endl; // action
				motor( actions[i] );
				cout << endl;
				break;
            
			case BEEP:			//command
				Beep(800, 600); // action
				break;
        
			case STOP:					//command
				cout << "STOP" << endl; // action
				break;

			case QUIT:					//command
				cout << "QUIT" << endl; // action
				break;

		} // end switch
		cout << endl;
	} // end for

	cout << "SHUTTING DOWN ROBOT" << endl; 
	cout << endl;
	
	system("pause");
	return 0;
} // end main 


// Simulation of the robot moving.
void motor(int rotate) 
{
	for(int i = 0; i < rotate; i++)
	{
		cerr << '+';
		Sleep(1000);
	}
 
}