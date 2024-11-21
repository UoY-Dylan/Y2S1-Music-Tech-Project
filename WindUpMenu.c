//Menu System

//define buttonL and buttonR

//Selection Functions

int lrCounter = 0;

void lrSelection()
    {
        if((buttonL || buttonR) == 1)
        {
            lrCounter = lrCounter++;
            //sleep for 200ms
        }
        //loop forever
    }