/*
 * Tone sequencer by Craig McIntyre
 * Released under the Unlicense.
 * 
 * Setup:
 *  Four pots connected between A0 and A3
 *  Speaker on pin 8
 *  
 */


byte tonePots[] = {A0, A1, A2, A3};
const byte numPots = 4;
int piezoPin = 8;


void setup() {
  Serial.begin(9600);
}

 
void loop() {
// Reads each input and dispatches to functions

  for (int thisPin = 0; thisPin < numPots; thisPin++) {
    int sensorValue = analogRead(thisPin);
    Serial.print(sensorValue);
    Serial.print(" - ");
    Serial.println(thisPin);
    playTone(sensorValue);
    delay(1000);

  }
}


void playTone(int sensorValue) {
// Play the relevant tone (Currently cmaj scale hardcoded)

  if (sensorValue >= 0 && sensorValue < 100) {
    tone(piezoPin, 262);
  }

  else if (sensorValue >= 100 && sensorValue < 200) {
    tone(piezoPin, 294);
  }

  else if (sensorValue >= 200 && sensorValue < 300) {
    tone(piezoPin, 294);
  }

  else if (sensorValue >= 300 && sensorValue < 400) {
    tone(piezoPin, 330);
  }

  else if (sensorValue >= 400 && sensorValue < 600) {
    tone(piezoPin, 349);
  }

  else if (sensorValue >= 500 && sensorValue < 600) {
    tone(piezoPin, 392);
  }

  else if (sensorValue >= 600 && sensorValue < 700) {
    tone(piezoPin, 440);
  }

  else if (sensorValue >= 700 && sensorValue < 800) {
    tone(piezoPin, 494);
  }

  else if (sensorValue >= 800 && sensorValue < 900) {
    tone(piezoPin, 523);
  }

  else if (sensorValue >= 900) {
    tone(piezoPin, 1300, 800);
  }  
}

