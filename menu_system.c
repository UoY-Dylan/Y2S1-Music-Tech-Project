#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//========== HARDWARE DECLARATIONS ==========

//place holder variables
int buttonLpressed = 0;
int buttonRpressed = 0;


// ===== STATE VARIABLES =====

int currentLayer = 0;
//0 = variable
//1 = select
int currentVariable = 0;
//0 = wave select
//1 = reverb
//2 = chorus
//3 = filter
int menuLocation[2] = {0, 0}; 
//[0] layer: constrined to 0-1
//[1] select: constrained to 0-4
//stores the value with wrapping 

int variableValue[4] = {0, 0, 0, 0}; //counters for each variable
//wave, reverb, chorus, filter

int variableValueWrap[4] = {0, 0, 0, 0}; //stores the value with wrapping 
//[0] = wave select: sin, tri, sqr, saw
//[1] = reverb: on, off
//[2] = chorus: on, off
//[3] = filter: on, off

char locationToString[4] = {"Wave Select", "Reverb", "Chorus", "Filter"};

char variableToString[4][4] = 
{
    {"Sine", "Triangle", "Square", "Saw"}, //wave
    {"ON", "OFF", "ON", "OFF"}, //reverb
    {"ON", "OFF", "ON", "OFF"}, //chorus
    {"ON", "OFF", "ON", "OFF"} //filter
};

//========== FUNCTIONS ==========

void displayLCD(char *str inputString)
{
    printf(inputString);
}


void lrSelection(int offset) 
{
    //runs whenever a left or right button is pressed 
    //offset dictates direction: -1 for left, 1 for right

    if(menuLocation[0] == 0) //variable layer
    {
        currentVariable = currentVariable+offset;
        menuLocation[1] = abs(currentVariable)%4;

        displayLCD(locationToString[menuLocation[2]]);
    }

    else if(menuLocation[0] == 1) //select layer
    {
        variableValue[menuLocation[1]] = variableValue[menuLocation[1]]+offset;
        variableValueWrap[menuLocation[1]] = abs()%4;

        displayLCD(variableToString[menuLocation[1]][variableValueWrap[menuLocation[1]]]);
    }
}

void udSelection()
{
    //runs whenever a up or down button is pressed 
    menuLocation[0] = !menuLocation[0];
}