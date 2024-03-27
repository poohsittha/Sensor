
const int ldrPin = A0;
const int buzzerPin = 12;
const int armedLedPin = 7;
const int triggeredLedPin = 8;

const int threshold = 500; 
boolean isArmed = true;
boolean isTriggered = false;

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(armedLedPin, OUTPUT);
  pinMode(triggeredLedPin, OUTPUT);
  digitalWrite(armedLedPin, HIGH);
  digitalWrite(triggeredLedPin, LOW);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  if (isArmed) {
    if (ldrValue > threshold) {
      isTriggered = true;
    }
  }
  
  if (isTriggered) {
    // Activate alarm
    tone(buzzerPin, 1000); 
    digitalWrite(armedLedPin, LOW);
    for (int i = 0; i < 3; i++) {
      digitalWrite(triggeredLedPin, HIGH); 
      delay(500); 
      digitalWrite(triggeredLedPin, LOW); 
      delay(500); 
    }
  } else {
    noTone(buzzerPin); 
    digitalWrite(armedLedPin, HIGH); 
    digitalWrite(triggeredLedPin, LOW); 
  }
  
  if (!isArmed) {
    isTriggered = false;
  }
  
  delay(1000); 
  isArmed = !isArmed; 
}
