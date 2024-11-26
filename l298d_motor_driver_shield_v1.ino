
/*
D8: serial
D12: latch
D4: CLK
D11: EN_M1
D3: EN_M2
D5:EN_M3
D6:EN_M4
*/


#define LATCH_PIN 12  // STCP pin
#define CLOCK_PIN 4  // SHCP pin
#define DATA_PIN 8   // DS pin

void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  Serial.begin(115200);
}
int i = 0;
void loop() {
  // Example: Control Motor States
  digitalWrite(LATCH_PIN, LOW);         // Start sending data
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0b00000101); // Example motor control data
  delay(0.05);
  digitalWrite(LATCH_PIN, HIGH);        // Latch data to outputs
  delay(100);
  i++;
  i = i % 256;
  Serial.println(i);
}
