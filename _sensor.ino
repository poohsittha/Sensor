// Pin definitions
const int ldrPin = A0;
const int buzzerPin = 12;
const int armedLedPin = 7;
const int triggeredLedPin = 8;

// Threshold value for LDR trigger
const int threshold = 500; // Adjust this value as per your environment

// Boolean variables to track system state
boolean isArmed = true;
boolean isTriggered = false;

void setup() {
  // Initialize pins
  pinMode(ldrPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(armedLedPin, OUTPUT);
  pinMode(triggeredLedPin, OUTPUT);
  
  // Initially, set armed LED on and triggered LED off
  digitalWrite(armedLedPin, HIGH);
  digitalWrite(triggeredLedPin, LOW);
}

void loop() {
  // Read LDR value
  int ldrValue = analogRead(ldrPin);
  
  // Check if the system is armed
  if (isArmed) {
    // Check if the LDR value exceeds the threshold
    if (ldrValue > threshold) {
      // Set the system triggered
      isTriggered = true;
    }
  }
  
  // Check if the system is triggered
  if (isTriggered) {
    // Activate alarm
    tone(buzzerPin, 1000); // Activate buzzer
    digitalWrite(armedLedPin, LOW); // Turn off armed LED
    
    // Blink triggered LED
    for (int i = 0; i < 3; i++) {
      digitalWrite(triggeredLedPin, HIGH); // Turn on triggered LED
      delay(500); // Delay for half a second
      digitalWrite(triggeredLedPin, LOW); // Turn off triggered LED
      delay(500); // Delay for half a second
    }
  } else {
    // Deactivate alarm
    noTone(buzzerPin); // Deactivate buzzer
    digitalWrite(armedLedPin, HIGH); // Turn on armed LED
    digitalWrite(triggeredLedPin, LOW); // Turn off triggered LED
  }
  
  // Reset triggered state if system disarmed
  if (!isArmed) {
    isTriggered = false;
  }
  
  // Simulate arming/disarming the system (replace with actual logic)
  delay(1000); // Delay for stability
  isArmed = !isArmed; // Toggle armed state
}
