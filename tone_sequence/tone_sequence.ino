/*
 * Tone sequencer by Craig McIntyre
 * Released under the Unlicense.
 * 
 * Setup:
 *    A pot for each of A0 and A3 - note selection
 *    A pot for A4 - tempo selection
 *    A pot on A5 - Key selection
 *    Speaker on pin 8, with resistor / pot for volume
 *    
 *    To add:
 *      Buttons for wider key range?
 *      Granular effects on tone?
 *  
 *  .......................................................0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
 *  
 */


byte tonePots[] = {A0, A1, A2, A3};
byte ledPins[] = {2, 3, 4, 5};
const byte numPots = 4;
int piezoPin = 8;


// Experimental registers
int keyc[9] = {262, 294, 330, 349, 392, 440, 494, 523, 587};
int keyf[9] = {349, 392, 440, 466, 523, 587, 659, 698, 784};
int keyg[9] = {392, 440, 494, 523, 587, 659, 740, 784, 880};
int keya[9] = {440, 494, 523, 587, 659, 698, 784, 880, 988}; 
// Experiment over

int rest = 1000;  // Set delay between notes 


void setup() {
  Serial.begin(9600);
}

 
void loop() {
// Reads each input and dispatches to functions

  for (int thisPin = 0; thisPin < numPots; thisPin++) {
    int restValue = analogRead(A4);
    rest = map(restValue, 0, 1023, 0, 2000);
    int sensorValue = analogRead(thisPin);
//    Serial.print(sensorValue);
//    Serial.print(" - ");
//    Serial.println(thisPin);
    if (sensorValue >= 100) {
      digitalWrite(ledPins[thisPin], HIGH);
      int keyValue = analogRead(A5);
      Serial.print(keyValue);
      Serial.print(" - ");
      int key = map(keyValue, 0, 1023, 0, 3);
      Serial.println(key);
      if (key == 0) {
        playTone(sensorValue, rest, keyc);
      }
      else if (key == 1) {
          playTone(sensorValue, rest, keyf);
      }
      else if (key == 2) {
          playTone(sensorValue, rest, keyg);
      }
      else if (key == 3) {
          playTone(sensorValue, rest, keya);
      }
     
    
//      playTone(sensorValue, rest, keyc);
      delay(rest);
      digitalWrite(ledPins[thisPin], LOW);
    }
    else {
      delay(rest);
    }
  }
}


void playTone(int sensorValue, int rest, int key[9]) {
// Play the relevant tone

  if (sensorValue >= 100 && sensorValue < 200) {
    tone(piezoPin, key[0], rest);
  }

  else if (sensorValue >= 200 && sensorValue < 300) {
    tone(piezoPin, key[1], rest);
  }

  else if (sensorValue >= 300 && sensorValue < 400) {
    tone(piezoPin, key[2], rest);
  }

  else if (sensorValue >= 400 && sensorValue < 600) {
    tone(piezoPin, key[3], rest);
  }

  else if (sensorValue >= 500 && sensorValue < 600) {
    tone(piezoPin, key[4], rest);
  }

  else if (sensorValue >= 600 && sensorValue < 700) {
    tone(piezoPin, key[5], rest);
  }

  else if (sensorValue >= 700 && sensorValue < 800) {
    tone(piezoPin, key[6], rest);
  }

  else if (sensorValue >= 800 && sensorValue < 900) {
    tone(piezoPin, key[7], rest);
  }

  else if (sensorValue >= 900) {
    tone(piezoPin, key[8], rest);
  }  
}

