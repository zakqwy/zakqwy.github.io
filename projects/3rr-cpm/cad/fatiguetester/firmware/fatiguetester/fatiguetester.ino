#include <avr/io.h>

#define LED PIN2_bm
#define SERVO PIN1_bm
#define SENSE PIN3_bm

// 75 TCA0 counts = 26.3 degrees = 2.85 degrees per TCA0 count
// 43 counts is around 15 degrees (verified with ImageJ)
// 57 counts is ~20 degrees

int servo_pos0 = 625;
int servo_pos1 = 568;

void setup() {
    // init _everything_ since reprogramming != reset
    TCA0.SINGLE.CTRLA = 0;
    TCA0.SINGLE.CTRLB = 0;
    TCA0.SINGLE.CTRLC = 0;
    TCA0.SINGLE.CTRLD = 0;

    // set up timer TCA for servo output on pin 4 / PA1 / W01
    TCA0.SINGLE.CTRLA |= ((1<<1) | (1<<3)); // fclk/64 (312.5 kHz)
    TCA0.SINGLE.PER = 6250; //pwm period = ~50 Hz
    TCA0.SINGLE.CMP1 = servo_pos0; //starting pulse width = 1.5 ms
    TCA0.SINGLE.CTRLB |= (1<<5); //enable compare TCA W01
    TCA0.SINGLE.CTRLB |= ((1<<0) | (1<<1)); //set TCA to single-slope PWM mode
    TCA0.SINGLE.CTRLA |= (1<<0); //enable timer TCA

    // GPIO setup
    PORTA.DIRSET = LED;
    PORTA.DIRSET = SERVO;
    PORTA.DIRCLR = SENSE;
    PORTA.PIN3CTRL |= (1<<3); //enable pullup on sense line

    Serial.begin(9600);
}

/* state machine
  0 ready
  1 test running
  2 test terminated
*/  
int state = 0; 
int count = 0;

int cycle_delay = 150; //ms

void loop() {
  switch(state) {
    case 0:
      Serial.println("ready to test");
      delay(500);
      PORTA.OUTCLR = LED;
      TCA0.SINGLE.CMP1 = servo_pos0;
      if ((PORTA.IN & SENSE) == false) {
        state = 1;
      }
      break;
    case 1:
      PORTA.OUTSET = LED;
      Serial.print("test started, ");
      Serial.print(servo_pos0 - servo_pos1);
      Serial.println(" servo counts per cycle");
      while((PORTA.IN & SENSE) == false) {
        TCA0.SINGLE.CMP1 = servo_pos1;
        delay(cycle_delay);
        TCA0.SINGLE.CMP1 = servo_pos0;
        delay(cycle_delay);
        count++;
        Serial.println(count);
      }
      state = 2;
      break;
    case 2:
      PORTA.OUTCLR = LED;
      Serial.print("final count ");
      Serial.print(count);
      Serial.print("; ");
      Serial.println("test finished, plz power cycle");
      delay(500);
      PORTA.OUTSET = LED;
      delay(100);
      break;
  }
}
