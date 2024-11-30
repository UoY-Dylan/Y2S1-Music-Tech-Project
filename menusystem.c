//========== VARIABLE DECLARATIONS ==========

//place holder variables
int buttonLpressed = 0;
int buttonRpressed = 0;


// ===== STATE VARIABLES =====

int currentLayer = 0;
//0 = variable
//1 = select
int currentVariable = 0;
//0 = wave select: sin, tri, sqr
//1 = reverb: on, off
//2 = chorus: on, off
//3 = filter: on, off
int menuLocation[2] = {currentLayer, currentVariable};

//holds the value of each variable
int variableValue[4] = {0, 0, 0, 0};
//[0] = wave select
//[1] = reverb
//[2] = chorus
//[3] = filter

int counterVariable = 0;
//pressing the left or right buttons adds/subtracts to this value resp

//========== FUNCTIONS ==========

void lrSelection(int offset) 
{
    // offset dictates direction: -1 for left, 1 for right

    if(menuLocation[0] == 0) //variable layer
    {
        switch(menuLocation[1])
        {
            case 0: // wave select

            break;

            case 1: // reverb

            break;

            case 2: // chorus

            break;

            case 3: // filter

            break;
            
        }
    }

    else if(menuLocation[0] == 1) //select layer
    {
        
    }
}