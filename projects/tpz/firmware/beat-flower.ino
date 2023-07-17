#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Bounce.h>

// WAV files converted to code by wav2sketch
#include "AudioSample1a_snare_sd1050.h"
#include "AudioSample2a_lowtom_lt25.h"
#include "AudioSample3amidtom_mt10.h"
#include "AudioSample4a_hitom_ht25.h"
#include "AudioSample5a_rimshot_rs.h"
#include "AudioSample6a_clap_cp.h"

#include "AudioSample1b_openhat_oh75.h"
#include "AudioSample2b_maraca_ma.h"
#include "AudioSample3b_cymbal_cy5000.h"
#include "AudioSample4b_claves_cl.h"
#include "AudioSample5b_closedhat_ch.h"
#include "AudioSample6b_cowbell_cb.h"

// Create the Audio components.  These should be created in the
// order data flows, inputs/sources -> processing -> outputs
//
AudioPlayMemory    sound0;
AudioPlayMemory    sound1;  // six memory players, so we can play
AudioPlayMemory    sound2;  // all six sounds simultaneously
AudioPlayMemory    sound3;
AudioPlayMemory    sound4;
AudioPlayMemory    sound5;
AudioMixer4        mix1;    // two 4-channel mixers are needed in
AudioMixer4        mix2;    // tandem to combine 6 audio sources
AudioOutputI2S     headphones;
AudioOutputAnalog  dac;     // play to both I2S audio board and on-chip DAC

// Create Audio connections between the components
//
AudioConnection c1(sound0, 0, mix1, 0);
AudioConnection c2(sound1, 0, mix1, 1);
AudioConnection c3(sound2, 0, mix1, 2);
AudioConnection c4(sound3, 0, mix1, 3);
AudioConnection c5(mix1, 0, mix2, 0);   // output of mix1 into 1st input on mix2
AudioConnection c6(sound4, 0, mix2, 1);
AudioConnection c7(sound5, 0, mix2, 2);
AudioConnection c8(mix2, 0, headphones, 0);
AudioConnection c9(mix2, 0, headphones, 1);
AudioConnection c10(mix2, 0, dac, 0);

// Create an object to control the audio shield.
// 
AudioControlSGTL5000 audioShield;

// Bounce objects to read six pushbuttons (pins 0-5)
//
Bounce button0 = Bounce(0, 5);
Bounce button1 = Bounce(1, 5);  // 5 ms debounce time
Bounce button2 = Bounce(2, 5);
Bounce button3 = Bounce(3, 5);
Bounce button4 = Bounce(4, 5);
Bounce button5 = Bounce(9, 5);
Bounce buttonmode = Bounce(5, 5);


void setup() {
  // Configure the pushbutton pins for pullups.
  // Each button should connect from the pin to GND.
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(10);

  // turn on the output
  audioShield.enable();
  audioShield.volume(0.75);

  // by default the Teensy 3.1 DAC uses 3.3Vp-p output
  // if your 3.3V power has noise, switching to the
  // internal 1.2V reference can give you a clean signal
  //dac.analogReference(INTERNAL);

  // reduce the gain on mixer channels, so more than 1
  // sound can play simultaneously without clipping
  mix1.gain(0, 0.75);
  mix1.gain(1, 0.75);
  mix1.gain(2, 0.75);
  mix1.gain(3, 0.75);
  mix2.gain(1, 0.75);
  mix2.gain(2, 0.75);
}

void loop() {
  // Update all the button objects
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  buttonmode.update();

  // When the buttons are pressed, just start a sound playing.
  // The audio library will play each sound through the mixers
  // so any combination can play simultaneously.
  //

  if (buttonmode.read() == HIGH) {
    if (button0.fallingEdge()) {
      sound0.play(AudioSample1a_snare_sd1050);
    }
    if (button1.fallingEdge()) {
      sound1.play(AudioSample2a_lowtom_lt25);
    }
    if (button2.fallingEdge()) {
      sound2.play(AudioSample3amidtom_mt10);
    }
    if (button3.fallingEdge()) {
      sound3.play(AudioSample4a_hitom_ht25);
    }
    if (button4.fallingEdge()) {
      sound4.play(AudioSample5a_rimshot_rs);
    }
    if (button5.fallingEdge()) {
      sound5.play(AudioSample6a_clap_cp);
    }
  }
  else {
        if (button0.fallingEdge()) {
      sound0.play(AudioSample1b_openhat_oh75);
    }
    if (button1.fallingEdge()) {
      sound1.play(AudioSample2b_maraca_ma);
    }
    if (button2.fallingEdge()) {
      sound2.play(AudioSample3b_cymbal_cy5000);
    }
    if (button3.fallingEdge()) {
      sound3.play(AudioSample4b_claves_cl);
    }
    if (button4.fallingEdge()) {
      sound4.play(AudioSample5b_closedhat_ch);
    }
    if (button5.fallingEdge()) {
      sound5.play(AudioSample6b_cowbell_cb);
    }
  }

}
