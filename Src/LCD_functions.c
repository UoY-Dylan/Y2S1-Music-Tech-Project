     //---------------------------------------------------------
    /*
      Program for writing to NHD-14432WG-BTFH-V#T LCD with the ST7920 controller
      This code is written for the Arduino Uno R3 using 8-bit parallel interface
      Newhaven Display invests time and resources providing this open source code,
      Please support Newhaven Display by purchasing products from Newhaven Display!
      This code is provided as an example only and without any warranty by Newhaven Display.
      Newhaven Display accepts no responsibility for any issues resulting from its use.
      The developer of the final application incorporating any parts of this
      sample code is responsible for ensuring its safe and correct operation
      and for any consequences resulting from its use.
      See the GNU General Public License for more details.
      Use Horizontal Orientation when converting BMP to hex code
      to display custom image using LCD assistant.
    */
    //---------------------------------------------------------
    #define RS      8  //Register Select signal
    #define RW      9  //Read/Write signal
    #define E       10 //Enable signal
    #include "144_32_Arrows.h"
    /****************************************************
                      Function Commands
    *****************************************************/
    //--------------------------------------------------------------------------
    void command(unsigned char c){
      unsigned char i, temp;
      PORTD = c;
      digitalWrite(RS, LOW);               // Command
      digitalWrite(RW, LOW);               // Write
      digitalWrite(E, HIGH);
      delay(1);
      digitalWrite(E, LOW);
      delay(1);
    }
    //--------------------------------------------------------------------------
    void data(unsigned char d){
      unsigned char i, temp;
      PORTD = d;
      digitalWrite(RS, HIGH);              // Data
      digitalWrite(RW, LOW);               // Write
      digitalWrite(E, HIGH);
      delay(1);
      digitalWrite(E, LOW);
      delay(1);          
    }
    /****************************************************
                      Display Commands
    *****************************************************/
    void disp(unsigned char *LCD_String)
    {
      unsigned int x, y, page;
      page = 0x80;
      for(int i=0;i<32;i++)
      {
        command(0x3E);
        command(page);
        command(0x80);           
        for (x=0;x<18;x++){
          data(*LCD_String);
          LCD_String++;
        }
        page++;
      }
    }
    void Fill()
    {
      unsigned int x, y, page;
      page = 0x80;
      for (page=0x80;page<0xA1;page++)
      {
        command(0x3E);
        command(page);
        command(0x80);
        for (x=0;x<18;x++)
        {
          data(0xFF);
          delayMicroseconds(50);
        }
      }
    }
    void Clear()
    {
      unsigned int x, y, page;
      page = 0x80;
      for (page=0x80;page<0xA1;page++)      
      {
        command(0x3E);
        command(page);
        command(0x80);
        for (x=0;x<18;x++)
        {
          data(0x00);
          delayMicroseconds(100);
        }
      }
    }
    /****************************************************
                Initialization For controller
    *****************************************************/
    void Initialization_Sequence()
    {
      command(0x38);        //Function Set: 8-bit mode, basic instruction
      delay(2);
      command(0x0C);        //Display control: Display on, cursor off, blink off
      delay(2);
      command(0x06);        //Entry Mode Set
      delay(2);
      command(0x02);        //Return home
      delay(100);
      command(0x01);        //Display Clear
      delay(10);
      for(int i=1;i<=32;i++){
        command(0x3E);
        command(0x80);
        command(0x80);
        for(int j=1;j<=40;j++){
          data(0x00);
        }
      } 
    }
    /*****************************************************
                Setup Function, to run once
    *****************************************************/
    void setup() {
      DDRD = 0xFF; // First 8 pins of PORT D as output
      DDRB = 0x3F; // Port B first 6 pins as output
      Initialization_Sequence();
      delay(10);
      Fill();
      delay(500);
      Clear();
      delay(500);
    }
