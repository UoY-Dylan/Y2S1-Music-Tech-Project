#

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
int menuLocation[2] = {0, 0}; //stores the value with wrapping 

//holds the value of each variable
int selectWave = 0;
int selectReverb = 0;
int selectChorus = 0;
int selectFilter = 0;

int variableValue[4] = {0, 0, 0, 0}; //stores the value with wrapping 
//[0] = wave select: sin, tri, sqr
//[1] = reverb: on, off
//[2] = chorus: on, off
//[3] = filter: on, off

char variableToStrings[] 

//========== FUNCTIONS ==========

void displayLCD(char *str inputString)
{
    print(inputString);
}


void lrSelection(int offset) 
{
    //runs whenever a left or right button is pressed 
    //offset dictates direction: -1 for left, 1 for right

    if(menuLocation[0] == 0) //variable layer
    {
        currentVariable = currentVariable+offset;
        menuLocation[1] = abs(currentVariable)%4;
    }

    else if(menuLocation[0] == 1) //select layer
    {
        switch(menuLocation[1])
        {
            case 0: // wave select
                selectWave = selectWave+offset;
                variableValue[0] = abs(selectWave)%

            break;

            case 1: // reverb

            break;

            case 2: // chorus

            break;

            case 3: // filter

            break;
        }
    }
}