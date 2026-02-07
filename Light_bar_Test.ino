const int RESET_PIN = 5; 
const int CLOCK_PIN = 6;
const int DATA_PIN  = 7;

const int TOTAL_LEDS = 20; 

void setup() {
  pinMode(RESET_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN,  OUTPUT);

  resetChain();
}

void loop() {
  // Turn off all LEDs to start fresh
  resetChain();

  // Set Data to HIGH so we shift in "1"s (ON state)
  digitalWrite(DATA_PIN, HIGH); 
  
  // Loop 20 times to turn on 20 LEDs
  for(int i = 0; i < TOTAL_LEDS; i++) {
    pulseClock();
    delay(1000); // Wait 1 second per LED (Total 20 seconds)
  }
}

void pulseClock() {
  digitalWrite(CLOCK_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(CLOCK_PIN, LOW);
}

void resetChain() {
  digitalWrite(RESET_PIN, HIGH);
  delay(10);
  digitalWrite(RESET_PIN, LOW);
}