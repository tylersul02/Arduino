
int clearPix ();
int trs ();
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6

#define NUMPIXELS      64

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int i = 0, j = 0;

int delayval = 50; 

void setup() {
  Serial.begin(9600);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin();
}

void loop() {
clearPix(); delay(1000); trs();  delay(2000);
 
  
}
int clearPix (){
  for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0)); 
    }
    pixels.show();
  }

int trs(){
int r,c;
int red = 0, green = 0, blue = 0;
int m[8][8] = {  
    {0,0,0,0,0,0,0,0} ,
    {0,0,1,0,0,1,0,0} ,
    {0,0,1,0,0,1,0,0} ,
    {0,0,1,0,0,1,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,1,0,0,0,0,1,0} ,
    {0,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0}   
};
  i = 0;
  int val;
  for (r = 0; r < 8; r++){
    for (c = 0; c < 8; c++){
      val = m[r][c];
      switch ( val ) {
          case 0:
            red = 255; green = 255; blue =0;// yellow
          break;
          case 1:
            red = 0; green = 0; blue =0;//black
          break;
          default:
          red = 0; green = 0; blue =0;
          break;
}
      
      
      // end of set the color
      pixels.setPixelColor(i, pixels.Color(red,green,blue));
 
      pixels.show(); 
      i++;
      delay(70);
     //Serial.print(c[x][y]);
    }//end y
}//end y and end of loop that increments x,y and i
}

