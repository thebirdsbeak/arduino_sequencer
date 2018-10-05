/***
 * 
 * Tone sequencer by Craig McIntyre
 * Released under the Unlicense.
 * 
 * Setup:
 *    A pot for each of A0 and A3 - note selection
 *    A pot for A4 - tempo selection
 *    A pot on A5 - chord selection
 *    Speaker on pin 8, with resistor / pot for volume
 *    Momentary switches with 10k pullup resistors on 10 and 11
 *    
 *  
 ***/


byte tonePots[] = {A0, A1, A2, A3};
const byte numPots = 4;
byte ledPins[] = {2, 3, 4, 5};
const byte numLeds = 4;
int piezoPin = 8;

int regStatus = 1;

int shiftPinUp = 11;
int shiftPinDown = 10;

// Chord




int bassreg[4][8] = {
  {131, 147, 165, 175, 196, 220, 247, 262}, // C
  {175, 196, 220, 233, 262, 294, 330, 349}, // F
  {196, 220, 233, 262, 294, 330, 370, 392}, // G
  {220, 247, 262, 294, 330, 349, 392, 440}  // Am
};

int medreg[4][8] = {
  {262, 294, 330, 349, 392, 440, 494, 523}, // C
  {349, 392, 440, 466, 523, 587, 659, 698}, // F
  {392, 440, 494, 523, 587, 659, 740, 784}, // G
  {440, 494, 523, 587, 659, 698, 784, 880}  // Am
};

int trebreg[4][8] = {
  {523, 587, 659, 698, 784, 880, 988, 1047}, // C
  {698, 784, 880, 932, 1047, 1175, 1319, 1397}, // F
  {784, 880, 988, 1047, 1175, 1319, 1480, 1568 }, // G
  {880, 988, 1047, 1175, 1319, 1397, 1568, 1760 }  // Am
};

// Set delay between notes (tempo)
int rest = 1000; 

void setup() {

  pinMode(shiftPinUp, INPUT);
  pinMode(shiftPinDown, INPUT);
  
  for (int ledPin = 0; ledPin < numLeds; ledPin ++) {
    pinMode(ledPins[ledPin], OUTPUT);
  
  }
}

 
void loop() {
// Reads each input and dispatches to functions

  for (int thisPin = 0; thisPin < numPots; thisPin++) {
    int restValue = analogRead(A4);
    rest = map(restValue, 0, 1023, 0, 1000);
    int sensorValue = analogRead(thisPin);
    if (sensorValue >= 100) {
      digitalWrite(ledPins[thisPin], HIGH);
      int chordValue = analogRead(A5);
      int chord = map(chordValue, 0, 1023, 0, 3);

    int upshift = digitalRead(shiftPinUp);
    int downshift = digitalRead(shiftPinDown);;

    if (upshift == HIGH) {
      if (chord == 0) {
        playTone(sensorValue, rest, trebreg[0]);
      }
      else if (chord == 1) {
          playTone(sensorValue, rest, trebreg[1]);
      }
      else if (chord == 2) {
          playTone(sensorValue, rest, trebreg[2]);
      }
      else if (chord == 3) {
          playTone(sensorValue, rest, trebreg[3]);
      } 
      delay(rest);
      digitalWrite(ledPins[thisPin], LOW);
    }
   
    else if (downshift == HIGH) {
            if (chord == 0) {
        playTone(sensorValue, rest, bassreg[0]);
      }
      else if (chord == 1) {
          playTone(sensorValue, rest, bassreg[1]);
      }
      else if (chord == 2) {
          playTone(sensorValue, rest, bassreg[2]);
      }
      else if (chord == 3) {
          playTone(sensorValue, rest, bassreg[3]);
      } 
      delay(rest);
      digitalWrite(ledPins[thisPin], LOW);
    }

    else {

// Selects register based on A5 value
      if (chord == 0) {
        playTone(sensorValue, rest, medreg[0]);
      }
      else if (chord == 1) {
          playTone(sensorValue, rest, medreg[1]);
      }
      else if (chord == 2) {
          playTone(sensorValue, rest, medreg[2]);
      }
      else if (chord == 3) {
          playTone(sensorValue, rest, medreg[3]);
      } 
      delay(rest);
      digitalWrite(ledPins[thisPin], LOW);
    }
    }
    else {
      delay(rest);
    }
    }
}


void playTone(int sensorValue, int rest, int chord[9]) {
// Play the relevant tone

  if (sensorValue >= 100 && sensorValue < 200) {
    tone(piezoPin, chord[0], rest);
  }

  else if (sensorValue >= 200 && sensorValue < 300) {
    tone(piezoPin, chord[1], rest);
  }

  else if (sensorValue >= 300 && sensorValue < 400) {
    tone(piezoPin, chord[2], rest);
  }

  else if (sensorValue >= 400 && sensorValue < 500) {
    tone(piezoPin, chord[3], rest);
  }

  else if (sensorValue >= 500 && sensorValue < 600) {
    tone(piezoPin, chord[4], rest);
  }

  else if (sensorValue >= 600 && sensorValue < 700) {
    tone(piezoPin, chord[5], rest);
  }

  else if (sensorValue >= 700 && sensorValue < 800) {
    tone(piezoPin, chord[6], rest);
  }

  else if (sensorValue >= 800) {
    tone(piezoPin, chord[7], rest);
  }

}

