#include "SevSeg.h"
int trigPin = 12;
int echoPin = 11;
int led = 13;
SevSeg s;
int incPrev;
int cnt = 0;

void setup() {

  pinMode(trigPin, OUTPUT);  //setup trigger pin as output
  pinMode(echoPin, INPUT);   //setup echo pin as inputF
  pinMode(led, OUTPUT);      //
  Serial.begin(9600);
  pinMode(10, INPUT);

  //Set to 1 for single-digit display
  byte numDigits = 1;
  //defines common pins while using multi-digit display. Left for single digit display
  byte digitPins[] = {};
  //Defines Arduino pin connections in order: A, B, C, D, E, F, G, DP
  byte segmentPins[] = { 9, 8, 7, 6, 5, 4, 3, 2 };
  byte displayType = COMMON_ANODE;  //Use COMMON_ANODE for Common Anode display
  bool resistorsOnSegments = true;    //‘false’ if resistors are connected to common pin
  //Initialize sevseg object. Use COMMON_ANODE instead of COMMON_CATHODE for CA display
  s.begin(displayType, numDigits, digitPins, segmentPins, resistorsOnSegments);
  s.setBrightness(90);
}

void loop() {

  int inc = digitalRead(10);

  //sets trigger pin high for 10 ms
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  //sets trigger pin low for 10 ms
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);

  //again sets trigger pin high for 10 ms
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  int pingTravelTime = pulseIn(echoPin, HIGH);  //takes input from the echo pin and stores int he variable

  Serial.println(pingTravelTime);

  if (pingTravelTime > 600) {
    // brightness = 1;
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }


  if ((inc == HIGH) && (cnt < 9) && (inc != incPrev)) {
    delay(100);
    cnt++;
  }


  s.setNumber(cnt);
  s.refreshDisplay();

  
  if(cnt == 9){
    
    cnt = 0;
  }

  delay(100);

  incPrev = inc;
}
