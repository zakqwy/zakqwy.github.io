/*    clock-one
 *    part of Z. Fredin's MiR @ TPZ
 *    CC-BY-SA 4.0
 *    
 *            HH:MM
 *    digit#  12:34
 *    
 *    AAA
 *   F   B
 *   F   B
 *    GGG
 *   E   C
 *   E   C
 *    DDD
 *    
 *    digit/seg   led no.
 *    1A
 *    1B          6,7
 *    1C          4,5
 *    1D
 *    1E          2,3
 *    1F          0,1
 *    1G
 *    
 *    2A
 *    2B
 *    2C
 *    2D
 *    2E
 *    2F
 *    2G
 */

#include <FastLED.h>
#define NUM_LEDS 58
#define DATA_PIN 9

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
}

int hour = 16;
int minute = 48;
long currentMillis, prevMillis;
int red, green, blue;

void loop() {
  switch (minute % 6) {
    case 0:
      green = 80;
      blue = 10;
      red = 20; 
      break;    
    case 1:
      green = 40;
      blue = 40;
      red = 10;
      break;
    case 2:
      green = 10;
      blue = 20;
      red = 80; 
      break;
    case 3:
      green = 10;
      blue = 40;
      red = 40;
      break;
    case 4:
      green = 20;
      blue = 80;
      red = 10; 
      break;
    case 5:
      green = 40;
      blue = 10;
      red = 40;
      break;
  } 
  currentMillis = millis();
  if (currentMillis - prevMillis >= 60000) {
    minute++;
    if (minute > 59) {
      minute = 0;
      hour++;
      if (hour > 23) {
        hour = 0;
      }
    }
    prevMillis = currentMillis;
  }
  clearDigits();
  dots(red,green,blue);
  writeHour(hour, red, green, blue);
  writeMinute(minute, red, green, blue);
  FastLED.show();
}

void writeHour(int hour, int red, int green, int blue) {
  if (hour < 10) {
    writeDigit(2, hour, red, green, blue);
  }
  else {
    writeDigit(2, hour % 10, red, green, blue);
    writeDigit(1, hour / 10, red, green, blue);
  }
}

void writeMinute(int minute, int red, int green, int blue) {
  writeDigit(3, minute / 10, red, green, blue);
  writeDigit(4, minute % 10, red, green, blue);
}

void clearDigits(void) {
  for (int i = 0; i < 58; i++) {
    leds[i].r = 0;
    leds[i].g = 0;
    leds[i].b = 0;
  }
}

void dots(int red, int green, int blue) {
  leds[44].setRGB(green, blue, red); //dot
  leds[45].setRGB(green, blue, red); //dot
}

void writeDigit(int digit, int val, int red, int green, int blue) {
  switch (digit) {
    case 1:
      switch (val) {
        case 0:
          leds[0].setRGB(green, blue, red); //F      
          leds[1].setRGB(green, blue, red); //F  
          leds[2].setRGB(green, blue, red); //E
          leds[3].setRGB(green, blue, red); //E       
          leds[4].setRGB(green, blue, red); //C      
          leds[5].setRGB(green, blue, red); //C
          leds[6].setRGB(green, blue, red); //B
          leds[7].setRGB(green, blue, red); //B
          leds[38].setRGB(green, blue, red);//A    
          leds[39].setRGB(green, blue, red);//A
          leds[56].setRGB(green, blue, red);//D
          leds[57].setRGB(green, blue, red);//D   
          break;  
        case 1:
          leds[4].setRGB(green, blue, red); //C      
          leds[5].setRGB(green, blue, red); //C
          leds[6].setRGB(green, blue, red); //B
          leds[7].setRGB(green, blue, red); //B
          break;
        case 2:
          leds[38].setRGB(green, blue, red);//A    
          leds[39].setRGB(green, blue, red);//A
          leds[6].setRGB(green, blue, red); //B
          leds[7].setRGB(green, blue, red); //B
          leds[40].setRGB(green, blue, red); //G
          leds[41].setRGB(green, blue, red); //G
          leds[2].setRGB(green, blue, red); //E
          leds[3].setRGB(green, blue, red); //E 
          leds[56].setRGB(green, blue, red);//D
          leds[57].setRGB(green, blue, red);//D   
          break;
        case 3:
          leds[38].setRGB(green, blue, red);//A    
          leds[39].setRGB(green, blue, red);//A
          leds[6].setRGB(green, blue, red); //B
          leds[7].setRGB(green, blue, red); //B
          leds[40].setRGB(green, blue, red); //G
          leds[41].setRGB(green, blue, red); //G
          leds[4].setRGB(green, blue, red); //C      
          leds[5].setRGB(green, blue, red); //C
          leds[56].setRGB(green, blue, red);//D
          leds[57].setRGB(green, blue, red);//D
          break;  
        case 4:
          leds[6].setRGB(green, blue, red); //B
          leds[7].setRGB(green, blue, red); //B
          leds[40].setRGB(green, blue, red); //G
          leds[41].setRGB(green, blue, red); //G
          leds[4].setRGB(green, blue, red); //C      
          leds[5].setRGB(green, blue, red); //C 
          leds[0].setRGB(green, blue, red); //F      
          leds[1].setRGB(green, blue, red); //F  
          break;     
        case 5:
          leds[38].setRGB(green, blue, red);//A    
          leds[39].setRGB(green, blue, red);//A 
          leds[0].setRGB(green, blue, red); //F      
          leds[1].setRGB(green, blue, red); //F
          leds[40].setRGB(green, blue, red); //G
          leds[41].setRGB(green, blue, red); //G
          leds[4].setRGB(green, blue, red); //C      
          leds[5].setRGB(green, blue, red); //C 
          leds[56].setRGB(green, blue, red);//D
          leds[57].setRGB(green, blue, red);//D  
          break;     
        case 6:
          leds[38].setRGB(green, blue, red);//A    
          leds[39].setRGB(green, blue, red);//A 
          leds[0].setRGB(green, blue, red); //F      
          leds[1].setRGB(green, blue, red); //F
          leds[40].setRGB(green, blue, red); //G
          leds[41].setRGB(green, blue, red); //G
          leds[4].setRGB(green, blue, red); //C      
          leds[5].setRGB(green, blue, red); //C 
          leds[56].setRGB(green, blue, red);//D
          leds[57].setRGB(green, blue, red);//D
          leds[2].setRGB(green, blue, red); //E
          leds[3].setRGB(green, blue, red); //E
          break; 
        case 7:
          leds[6].setRGB(green, blue, red); //B
          leds[7].setRGB(green, blue, red); //B
          leds[38].setRGB(green, blue, red);//A    
          leds[39].setRGB(green, blue, red);//A 
          leds[4].setRGB(green, blue, red); //C      
          leds[5].setRGB(green, blue, red); //C 
          break; 
        case 8:
          leds[0].setRGB(green, blue, red); //F      
          leds[1].setRGB(green, blue, red); //F  
          leds[2].setRGB(green, blue, red); //E
          leds[3].setRGB(green, blue, red); //E       
          leds[4].setRGB(green, blue, red); //C      
          leds[5].setRGB(green, blue, red); //C
          leds[6].setRGB(green, blue, red); //B
          leds[7].setRGB(green, blue, red); //B
          leds[38].setRGB(green, blue, red);//A    
          leds[39].setRGB(green, blue, red);//A
          leds[56].setRGB(green, blue, red);//D
          leds[57].setRGB(green, blue, red);//D  
          leds[40].setRGB(green, blue, red); //G
          leds[41].setRGB(green, blue, red); //G
          break; 
        case 9:
          leds[0].setRGB(green, blue, red); //F      
          leds[1].setRGB(green, blue, red); //F         
          leds[4].setRGB(green, blue, red); //C      
          leds[5].setRGB(green, blue, red); //C
          leds[6].setRGB(green, blue, red); //B
          leds[7].setRGB(green, blue, red); //B
          leds[38].setRGB(green, blue, red);//A    
          leds[39].setRGB(green, blue, red);//A
          leds[56].setRGB(green, blue, red);//D
          leds[57].setRGB(green, blue, red);//D  
          leds[40].setRGB(green, blue, red); //G
          leds[41].setRGB(green, blue, red); //G
          break;
        }
      break; 
    case 2: 
      switch (val) {
        case 0:
          leds[8].setRGB(green, blue, red); //F      
          leds[9].setRGB(green, blue, red); //F  
          leds[10].setRGB(green, blue, red); //E
          leds[11].setRGB(green, blue, red); //E       
          leds[12].setRGB(green, blue, red); //C      
          leds[13].setRGB(green, blue, red); //C
          leds[14].setRGB(green, blue, red); //B
          leds[15].setRGB(green, blue, red); //B
          leds[36].setRGB(green, blue, red); //A
          leds[37].setRGB(green, blue, red); //A
          leds[54].setRGB(green, blue, red); //D
          leds[55].setRGB(green, blue, red); //D
          break; 
        case 1:      
          leds[12].setRGB(green, blue, red); //C      
          leds[13].setRGB(green, blue, red); //C
          leds[14].setRGB(green, blue, red); //B
          leds[15].setRGB(green, blue, red); //B
          break; 
        case 2:
          leds[10].setRGB(green, blue, red); //E
          leds[11].setRGB(green, blue, red); //E       
          leds[14].setRGB(green, blue, red); //B
          leds[15].setRGB(green, blue, red); //B
          leds[36].setRGB(green, blue, red); //A
          leds[37].setRGB(green, blue, red); //A
          leds[54].setRGB(green, blue, red); //D
          leds[55].setRGB(green, blue, red); //D
          leds[42].setRGB(green, blue, red); //G
          leds[43].setRGB(green, blue, red); //G
          break; 
        case 3:
          leds[12].setRGB(green, blue, red); //C      
          leds[13].setRGB(green, blue, red); //C
          leds[14].setRGB(green, blue, red); //B
          leds[15].setRGB(green, blue, red); //B
          leds[36].setRGB(green, blue, red); //A
          leds[37].setRGB(green, blue, red); //A
          leds[54].setRGB(green, blue, red); //D
          leds[55].setRGB(green, blue, red); //D
          leds[42].setRGB(green, blue, red); //G
          leds[43].setRGB(green, blue, red); //G
          break; 
        case 4:
          leds[12].setRGB(green, blue, red); //C      
          leds[13].setRGB(green, blue, red); //C
          leds[14].setRGB(green, blue, red); //B
          leds[15].setRGB(green, blue, red); //B
          leds[42].setRGB(green, blue, red); //G
          leds[43].setRGB(green, blue, red); //G
          leds[8].setRGB(green, blue, red); //F      
          leds[9].setRGB(green, blue, red); //F 
          break; 
        case 5:
          leds[12].setRGB(green, blue, red); //C      
          leds[13].setRGB(green, blue, red); //C
          leds[8].setRGB(green, blue, red); //F      
          leds[9].setRGB(green, blue, red); //F 
          leds[36].setRGB(green, blue, red); //A
          leds[37].setRGB(green, blue, red); //A
          leds[54].setRGB(green, blue, red); //D
          leds[55].setRGB(green, blue, red); //D
          leds[42].setRGB(green, blue, red); //G
          leds[43].setRGB(green, blue, red); //G
          break; 
        case 6:
          leds[12].setRGB(green, blue, red); //C      
          leds[13].setRGB(green, blue, red); //C
          leds[8].setRGB(green, blue, red); //F      
          leds[9].setRGB(green, blue, red); //F 
          leds[36].setRGB(green, blue, red); //A
          leds[37].setRGB(green, blue, red); //A
          leds[54].setRGB(green, blue, red); //D
          leds[55].setRGB(green, blue, red); //D
          leds[42].setRGB(green, blue, red); //G
          leds[43].setRGB(green, blue, red); //G
          leds[10].setRGB(green, blue, red); //E
          leds[11].setRGB(green, blue, red); //E 
          break; 
        case 7:
          leds[12].setRGB(green, blue, red); //C      
          leds[13].setRGB(green, blue, red); //C
          leds[36].setRGB(green, blue, red); //A
          leds[37].setRGB(green, blue, red); //A
          leds[14].setRGB(green, blue, red); //B
          leds[15].setRGB(green, blue, red); //B
          break; 
        case 8:
          leds[12].setRGB(green, blue, red); //C      
          leds[13].setRGB(green, blue, red); //C
          leds[14].setRGB(green, blue, red); //B
          leds[15].setRGB(green, blue, red); //B
          leds[8].setRGB(green, blue, red); //F      
          leds[9].setRGB(green, blue, red); //F 
          leds[36].setRGB(green, blue, red); //A
          leds[37].setRGB(green, blue, red); //A
          leds[54].setRGB(green, blue, red); //D
          leds[55].setRGB(green, blue, red); //D
          leds[42].setRGB(green, blue, red); //G
          leds[43].setRGB(green, blue, red); //G
          leds[10].setRGB(green, blue, red); //E
          leds[11].setRGB(green, blue, red); //E 
          break; 
        case 9:
          leds[12].setRGB(green, blue, red); //C      
          leds[13].setRGB(green, blue, red); //C
          leds[14].setRGB(green, blue, red); //B
          leds[15].setRGB(green, blue, red); //B
          leds[8].setRGB(green, blue, red); //F      
          leds[9].setRGB(green, blue, red); //F 
          leds[36].setRGB(green, blue, red); //A
          leds[37].setRGB(green, blue, red); //A
          leds[54].setRGB(green, blue, red); //D
          leds[55].setRGB(green, blue, red); //D
          leds[42].setRGB(green, blue, red); //G
          leds[43].setRGB(green, blue, red); //G
          break; 
        }
      break; 
    case 3: 
      switch (val) {
        case 0:
          leds[16].setRGB(green, blue, red); //F      
          leds[17].setRGB(green, blue, red); //F  
          leds[18].setRGB(green, blue, red); //E
          leds[19].setRGB(green, blue, red); //E       
          leds[20].setRGB(green, blue, red); //C      
          leds[21].setRGB(green, blue, red); //C
          leds[22].setRGB(green, blue, red); //B
          leds[23].setRGB(green, blue, red); //B
          leds[34].setRGB(green, blue, red); //A
          leds[35].setRGB(green, blue, red); //A
          leds[52].setRGB(green, blue, red); //D
          leds[53].setRGB(green, blue, red); //D
          break; 
        case 1:     
          leds[20].setRGB(green, blue, red); //C      
          leds[21].setRGB(green, blue, red); //C
          leds[22].setRGB(green, blue, red); //B
          leds[23].setRGB(green, blue, red); //B
          break; 
        case 2:
          leds[18].setRGB(green, blue, red); //E
          leds[19].setRGB(green, blue, red); //E       
          leds[22].setRGB(green, blue, red); //B
          leds[23].setRGB(green, blue, red); //B
          leds[34].setRGB(green, blue, red); //A
          leds[35].setRGB(green, blue, red); //A
          leds[52].setRGB(green, blue, red); //D
          leds[53].setRGB(green, blue, red); //D
          leds[46].setRGB(green, blue, red); //G
          leds[47].setRGB(green, blue, red); //G
          break; 
        case 3:    
          leds[22].setRGB(green, blue, red); //B
          leds[23].setRGB(green, blue, red); //B
          leds[34].setRGB(green, blue, red); //A
          leds[35].setRGB(green, blue, red); //A
          leds[52].setRGB(green, blue, red); //D
          leds[53].setRGB(green, blue, red); //D
          leds[46].setRGB(green, blue, red); //G
          leds[47].setRGB(green, blue, red); //G
          leds[20].setRGB(green, blue, red); //C      
          leds[21].setRGB(green, blue, red); //C
          break; 
        case 4:    
          leds[22].setRGB(green, blue, red); //B
          leds[23].setRGB(green, blue, red); //B
          leds[46].setRGB(green, blue, red); //G
          leds[47].setRGB(green, blue, red); //G
          leds[20].setRGB(green, blue, red); //C      
          leds[21].setRGB(green, blue, red); //C
          leds[16].setRGB(green, blue, red); //F      
          leds[17].setRGB(green, blue, red); //F  
          break; 
        case 5:    
          leds[34].setRGB(green, blue, red); //A
          leds[35].setRGB(green, blue, red); //A
          leds[46].setRGB(green, blue, red); //G
          leds[47].setRGB(green, blue, red); //G
          leds[20].setRGB(green, blue, red); //C      
          leds[21].setRGB(green, blue, red); //C
          leds[16].setRGB(green, blue, red); //F      
          leds[17].setRGB(green, blue, red); //F 
          leds[52].setRGB(green, blue, red); //D
          leds[53].setRGB(green, blue, red); //D 
          break; 
        case 6:    
          leds[34].setRGB(green, blue, red); //A
          leds[35].setRGB(green, blue, red); //A
          leds[46].setRGB(green, blue, red); //G
          leds[47].setRGB(green, blue, red); //G
          leds[20].setRGB(green, blue, red); //C      
          leds[21].setRGB(green, blue, red); //C
          leds[16].setRGB(green, blue, red); //F      
          leds[17].setRGB(green, blue, red); //F 
          leds[52].setRGB(green, blue, red); //D
          leds[53].setRGB(green, blue, red); //D 
          leds[18].setRGB(green, blue, red); //E
          leds[19].setRGB(green, blue, red); //E 
          break; 
        case 7:    
          leds[22].setRGB(green, blue, red); //B
          leds[23].setRGB(green, blue, red); //B
          leds[34].setRGB(green, blue, red); //A
          leds[35].setRGB(green, blue, red); //A
          leds[20].setRGB(green, blue, red); //C      
          leds[21].setRGB(green, blue, red); //C
          break; 
        case 8:
          leds[16].setRGB(green, blue, red); //F      
          leds[17].setRGB(green, blue, red); //F  
          leds[18].setRGB(green, blue, red); //E
          leds[19].setRGB(green, blue, red); //E       
          leds[20].setRGB(green, blue, red); //C      
          leds[21].setRGB(green, blue, red); //C
          leds[22].setRGB(green, blue, red); //B
          leds[23].setRGB(green, blue, red); //B
          leds[34].setRGB(green, blue, red); //A
          leds[35].setRGB(green, blue, red); //A
          leds[52].setRGB(green, blue, red); //D
          leds[53].setRGB(green, blue, red); //D
          leds[46].setRGB(green, blue, red); //G
          leds[47].setRGB(green, blue, red); //G
          break;
        case 9:
          leds[16].setRGB(green, blue, red); //F      
          leds[17].setRGB(green, blue, red); //F       
          leds[20].setRGB(green, blue, red); //C      
          leds[21].setRGB(green, blue, red); //C
          leds[22].setRGB(green, blue, red); //B
          leds[23].setRGB(green, blue, red); //B
          leds[34].setRGB(green, blue, red); //A
          leds[35].setRGB(green, blue, red); //A
          leds[52].setRGB(green, blue, red); //D
          leds[53].setRGB(green, blue, red); //D
          leds[46].setRGB(green, blue, red); //G
          leds[47].setRGB(green, blue, red); //G
          break;
        }
        break;
    case 4: 
      switch (val) {
        case 0:
          leds[24].setRGB(green, blue, red); //F      
          leds[25].setRGB(green, blue, red); //F  
          leds[26].setRGB(green, blue, red); //E
          leds[27].setRGB(green, blue, red); //E       
          leds[28].setRGB(green, blue, red); //C      
          leds[29].setRGB(green, blue, red); //C
          leds[30].setRGB(green, blue, red); //B
          leds[31].setRGB(green, blue, red); //B
          leds[32].setRGB(green, blue, red); //A
          leds[33].setRGB(green, blue, red); //A
          leds[50].setRGB(green, blue, red); //D
          leds[51].setRGB(green, blue, red); //D
          break; 
        case 1:     
          leds[28].setRGB(green, blue, red); //C      
          leds[29].setRGB(green, blue, red); //C
          leds[30].setRGB(green, blue, red); //B
          leds[31].setRGB(green, blue, red); //B
          break; 
        case 2:  
          leds[26].setRGB(green, blue, red); //E
          leds[27].setRGB(green, blue, red); //E       
          leds[30].setRGB(green, blue, red); //B
          leds[31].setRGB(green, blue, red); //B
          leds[32].setRGB(green, blue, red); //A
          leds[33].setRGB(green, blue, red); //A
          leds[50].setRGB(green, blue, red); //D
          leds[51].setRGB(green, blue, red); //D
          leds[48].setRGB(green, blue, red); //G
          leds[49].setRGB(green, blue, red); //G
          break; 
        case 3:        
          leds[30].setRGB(green, blue, red); //B
          leds[31].setRGB(green, blue, red); //B
          leds[32].setRGB(green, blue, red); //A
          leds[33].setRGB(green, blue, red); //A
          leds[50].setRGB(green, blue, red); //D
          leds[51].setRGB(green, blue, red); //D
          leds[48].setRGB(green, blue, red); //G
          leds[49].setRGB(green, blue, red); //G
          leds[28].setRGB(green, blue, red); //C      
          leds[29].setRGB(green, blue, red); //C
          break; 
        case 4:        
          leds[30].setRGB(green, blue, red); //B
          leds[31].setRGB(green, blue, red); //B
          leds[48].setRGB(green, blue, red); //G
          leds[49].setRGB(green, blue, red); //G
          leds[28].setRGB(green, blue, red); //C      
          leds[29].setRGB(green, blue, red); //C
          leds[24].setRGB(green, blue, red); //F      
          leds[25].setRGB(green, blue, red); //F 
          break; 
        case 5:        
          leds[32].setRGB(green, blue, red); //A
          leds[33].setRGB(green, blue, red); //A
          leds[24].setRGB(green, blue, red); //F      
          leds[25].setRGB(green, blue, red); //F 
          leds[50].setRGB(green, blue, red); //D
          leds[51].setRGB(green, blue, red); //D
          leds[48].setRGB(green, blue, red); //G
          leds[49].setRGB(green, blue, red); //G
          leds[28].setRGB(green, blue, red); //C      
          leds[29].setRGB(green, blue, red); //C
          break; 
        case 6:        
          leds[32].setRGB(green, blue, red); //A
          leds[33].setRGB(green, blue, red); //A
          leds[24].setRGB(green, blue, red); //F      
          leds[25].setRGB(green, blue, red); //F 
          leds[50].setRGB(green, blue, red); //D
          leds[51].setRGB(green, blue, red); //D
          leds[48].setRGB(green, blue, red); //G
          leds[49].setRGB(green, blue, red); //G
          leds[28].setRGB(green, blue, red); //C      
          leds[29].setRGB(green, blue, red); //C
          leds[26].setRGB(green, blue, red); //E
          leds[27].setRGB(green, blue, red); //E 
          break; 
        case 7:        
          leds[32].setRGB(green, blue, red); //A
          leds[33].setRGB(green, blue, red); //A
          leds[28].setRGB(green, blue, red); //C      
          leds[29].setRGB(green, blue, red); //C 
          leds[30].setRGB(green, blue, red); //B
          leds[31].setRGB(green, blue, red); //B
          break; 
        case 8:        
          leds[32].setRGB(green, blue, red); //A
          leds[33].setRGB(green, blue, red); //A
          leds[24].setRGB(green, blue, red); //F      
          leds[25].setRGB(green, blue, red); //F 
          leds[50].setRGB(green, blue, red); //D
          leds[51].setRGB(green, blue, red); //D
          leds[48].setRGB(green, blue, red); //G
          leds[49].setRGB(green, blue, red); //G
          leds[28].setRGB(green, blue, red); //C      
          leds[29].setRGB(green, blue, red); //C
          leds[26].setRGB(green, blue, red); //E
          leds[27].setRGB(green, blue, red); //E
          leds[30].setRGB(green, blue, red); //B
          leds[31].setRGB(green, blue, red); //B 
          break; 
        case 9:        
          leds[32].setRGB(green, blue, red); //A
          leds[33].setRGB(green, blue, red); //A
          leds[24].setRGB(green, blue, red); //F      
          leds[25].setRGB(green, blue, red); //F 
          leds[50].setRGB(green, blue, red); //D
          leds[51].setRGB(green, blue, red); //D
          leds[48].setRGB(green, blue, red); //G
          leds[49].setRGB(green, blue, red); //G
          leds[28].setRGB(green, blue, red); //C      
          leds[29].setRGB(green, blue, red); //C
          leds[30].setRGB(green, blue, red); //B
          leds[31].setRGB(green, blue, red); //B 
          break; 
        }
      break;
  }
}
