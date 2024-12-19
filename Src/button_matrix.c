#include <stdio.h>
#include <stdlib.h>


//========== HARDWARE DECLARATIONS ==========

int rowX = 0;
int columnY = 0;
//place holders for buttons

int FF = 440; //fundamental frequency
int lowC = ((FF)/2)*(2^(3/12))
//calculates the lowest C on the keyboard

// ===== FUNCTIONS =====

float calculate12TET(int semitone)
{
    //calculates the note x semitones up from the lowC, using 12 tone equal temperament
    return lowC*(2^((semitone/12)))
}



// ===== MATRIX ARRAY =====

int buttonMatrix[5][5] = 
{
    //recieves high inputs from pins rox x and column y as buttonMatrix[x][y]
    //translates the input into a frequency
    {lowC, calculate12TET(1), calculate12TET(2), calculate12TET(3), calculate12TET(4)}, 
    {calculate12TET(5), calculate12TET(6), calculate12TET(7), calculate12TET(8), calculate12TET(9)},
    {calculate12TET(10), calculate12TET(11), lowC*2, calculate12TET(13), calculate12TET(14)},
    {calculate12TET(15), calculate12TET(16), calculate12TET(17), calculate12TET(18), calculate12TET(19)},
    {calculate12TET(20), calculate12TET(21), calculate12TET(22), calculate12TET(23), calculate12TET(24)}
}

int currentFrequency = buttonMatrix[rowX][columnY];


